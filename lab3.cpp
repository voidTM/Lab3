#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "math.h"
#include "ctype.h"
#include "reader.h"
#include "birthday.h"
#include "treenode.h"
#include "binarytree.h"

using namespace std;

birthday birthdayParser(string aLine)
{
	int days = 0;
	int n = 0;;
	birthday someOne;
	string temp;
	vector<string> phrase;
	int arr[5];
	map<char, int> integer;
	integer['0'] = 0;
	integer['1'] = 1;
	integer['2'] = 2;
	integer['3'] = 3;
	integer['4'] = 4;
	integer['5'] = 5;
	integer['6'] = 6;
	integer['7'] = 7;
	integer['8'] = 8;
	integer['9'] = 9;

	cout << "deciphering" << aLine << endl;
	for (int i = 0; i < aLine.length(); i++)
	{
		char x = aLine.at(i);
	//	cout << "at"<< i << "x is:" << x << endl;
		if (isdigit(x))
		{
			cout << "attempting to add" << x << endl;
			arr[n] = integer.find(x)->second;
			n++;
		}
		else
		{
			switch (x)
			{
				case '<':
					break;
				case ',':
					phrase.push_back(temp);
					temp = "";
					break;
				case '>':
					for (int y = 0; y < n; y++)
					{
						days += pow(10, n - x -1) * arr[y];
					}
//					cout <<"birthday date "<< days << endl;
//					cout << "phrase.at(0)" << phrase.at(0) << endl;
					someOne.addName(phrase.at(0));
					cout << "Name:" << someOne.getName() <<endl;
					someOne.addMonth(phrase.at(1));
					cout << "Month" << someOne.getMonth() <<endl;
					someOne.addDay(days);
					break;
				default:
					temp += x;
			}
		}
	}
	return someOne;
}

int main()
{
	reader magic;
	vector<string> readIn;
	birthday temp;
	binarytree <birthday> testTree;
	magic.addFile("Birthdays.txt");
	magic.readFile();
	readIn = magic.getData();
	magic.closeFile();

	cout << "Lines read in:" << readIn.size() << endl;
	for (int i = 0; i < readIn.size(); i++)
	{
		temp = birthdayParser(readIn.at(i));
		cout << "Name after: " << temp.getName() << endl;
	}
}
