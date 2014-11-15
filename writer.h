#pragma once
#ifndef WRITER
#define	WRITER

#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class writer
{
	private:
		ofstream wFile;
		string line;
		vector<string> toBeWritten;
		bool filePresent;
	public:

	//Constructor
		writer();

	//Methods
		bool addFile(string);
		bool closeFile();
		void clearData();
		bool addData(vector<string>);
		void writeFile();
};

#endif