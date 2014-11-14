#pragma once
#ifndef READER
#define READER

#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class reader
{
	protected:
		ifstream database;
		string line;
		vector <string> lines; //Each item within a vector contains 1 line of data from the file
		map<char, int> ignore; //
		bool filePresent; 		//True if a file is already opened
	public:

	//Constructor
		reader();
//		reader(string); //Will take in the file name and then open it. Not implemented

	//Methods
		bool addFile(string);	//takes in a file name and attempts to open it.
		void readFile();		// maybe take in everything and then close file?
		bool closeFile();		//closes the file and then clears the ifstream making it ready for use again
		vector<string> getData();		//Returns all the data as a string vector
};

#endif