#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "writer.h"

using namespace std;

writer::writer()
{
	filePresent = false;
}

/*
addFile(string name)
Precondition: The name read in is that of an actual file.
Postconditon: Opens the file to be written.
*/
bool writer::addFile(string fileName)
{
	if (filePresent == false) // open file
	{
		wFile.open(fileName);
		if (wFile.good())
		{
			cout << "File has been successfully opened." << endl;
			filePresent = true;
			return true;
		}
		else //if the file is bad it will discard the file
		{
			cout << "Error file has been deemed bad and discarded" << endl;
			filePresent = false;
			wFile.close();
			wFile.clear();
		}
	}
	else //prevents user from reading more than 1 file at a time using the same writer object
	{
		cout << "Cannot add multiple files to same reader." << endl;
		return false;
	}
}

/*
closeFile()
Precondition: N/A
Postcondition: Closes the file if there is one open and removes any
data was set to be written in.
*/
bool writer::closeFile()
{
	if (filePresent == true)
	{
		wFile.close();
		wFile.clear();
		filePresent = false;
		clearData();
		return true;
	}
	else
	{
		cout << "There is no file present and thus nothing to be closed.";
		return false;
	}
}

void writer::clearData()
{
	toBeWritten.empty();
}

/*
	bool addData(vector<string> newData)
	Precondition: N/A
	Postcondition: If no data is current present add the
	new data to be read.
*/
bool writer::addData(vector<string> newData)
{
	if (toBeWritten.size() < 1)
	{
		toBeWritten = newData;
		return true;
	}
	else
	{
		cout << "Data already present please clear Writer before adding new data" << endl;
		return false;
	}
}

void writer::writeFile()
{
	if (wFile.good())
	{
		for (int i = 0; i < toBeWritten.size(); i++)
		{
			wFile << toBeWritten.at(i) << endl;
		}
	}
	else
	{
		cout << "file is bad and data was not written" << endl;
	}
}