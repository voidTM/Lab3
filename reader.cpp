#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "reader.h"

using namespace std;

/*
	reader()
	Precondition: N/A
	Postconditon: An reader object is initialized with no file set to be read.
*/
reader::reader()
{
	filePresent = false;
}

/*
addFile(string name)
Precondition: The name read in is that of an actual file.
Postconditon: Opens the file to be read.
*/
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

/*
closeFile()
Precondition: N/A
Postcondition: Closes the file if there is one open and removes any 
data that has been previously read in.
*/
bool reader::closeFile()
{
	if (filePresent == true)
	{
		database.close();
		database.clear();
		filePresent = false;
		lines.empty();
		return true;
	}
	else
	{
		cout << "There is no file present and thus nothing to be closed.";
		return false;
	}
}

/*
void readFile()
Precondition: A file should have been already opened and read to be read.
Postcondition: The contents of the file are read in line by line and then
stored in vectors.
*/
void reader::readFile()
{
	while(database.good())
	{
		getline(database, line);
//		cout << line << endl;
		lines.push_back(line);
	}
}

/*
cector<string> getData()
Precondition: The file should have already been read.
Postcondition: returns all the data that has been read
from the file.
*/
vector<string> reader::getData()
{
	return lines;
}