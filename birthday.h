#pragma
#ifndef BIRTHDAY
#define BIRTHDAY

#include <iostream>
#include <string>
#include <map>

using namespace std;

class birthday
{
	private:
		map<string, int> monthVal;	//Holds the numberic values of each month
		int day;						//Holds the day of the month
		string name;					//Holds the name of the person whose birthday it is
		string month;					//Holds the month

	public:

		//Constructor
		birthday();
		birthday(string, string, int);

		//Methods
		void addMonth(string);
		void addDay(int);
		void addName(string);
		string getName();
		string getMonth();
		int getMonthValue();
		int getDay();
};

#endif