#include <iostream>
#include <string>
#include <map>
#include "birthday.h"

using namespace std;

birthday::birthday() : name("UNKOWN"), month("UNKNOWN"), day(-1) 
{
	monthVal["January"] = 1;
	monthVal["Febuary"] = 2;
	monthVal["March"] = 3;
	monthVal["April"] = 4;
	monthVal["May"] = 5;
	monthVal["June"] = 6;
	monthVal["July"] = 7;
	monthVal["August"] = 8;
	monthVal["September"] = 9;
	monthVal["October"] = 10;
	monthVal["November"] = 11;
	monthVal["December"] = 12;
}

birthday::birthday(string n, string m, int d)
{
	name = n;
	month = m;
	day  = d;

	monthVal["January"] = 1;
	monthVal["Febuary"] = 2;
	monthVal["March"] = 3;
	monthVal["April"] = 4;
	monthVal["May"] = 5;
	monthVal["June"] = 6;
	monthVal["July"] = 7;
	monthVal["August"] = 8;
	monthVal["September"] = 9;
	monthVal["October"] = 10;
	monthVal["November"] = 11;
	monthVal["December"] = 12;
}

void birthday::addMonth(string m)
	{month = m;}

void birthday::addDay(int d)
	{day = d;}

void birthday::addName(string n)
	{name = n;}

string birthday::getName()
	{return name;}

string birthday::getMonth()
	{return month;}

int birthday::getMonthValue()
{
	if(monthVal.count(month) > 0)
	{
		cout << "Month found." << endl;
		return monthVal.find(month)->second;
	}
	else
	{
		cout << "No proper month " + month + " was found." << endl;
		return -1;
	}
}

int birthday::getDay()
	{return day;}