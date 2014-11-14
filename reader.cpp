#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "reader.h"

using namespace std;

reader::reader()
{
	filePresent = false;
}

bool reader::addFile(string name) //needs to check file name later
{
	if(filePresent == false) // open file
	{
		database.open(name);
		if(database.good())
		{		
			cout << "File has been successfully opened." << endl;
			filePresent = true;
			return true;
		}
		else //if the file is bad it will discard the file
		{
			cout << "Error file has been deemed bad and discarded" << endl;
			filePresent = false;
			database.close();
			database.clear();
		}
	}
	else
	{
		cout << "Cannot add multiple files to same reader." << endl;
		return false;
	}
}

bool reader::closeFile()
{
	if (filePresent == true)
	{
		database.close();
		database.clear();
		filePresent = false;
		return true;
	}
	else
	{
		cout << "There is no file present and thus nothing to be closed.";
		return false;
	}
}

void reader::readFile()
{
	while(database.good())
	{
		getline(database, line);
		cout << line << endl;
		lines.push_back(line);
	}
}

vector<string> reader::getData()
{
	return lines;
}