#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "person.h"

using namespace std;

void readData(vector<Person> &vect)
{
	int i = 0;
	string fName, lName;
	float hours, rate;
	ifstream dataFile;
	dataFile.open("input.txt");
	while (dataFile)
	{
		if (dataFile.eof() == true)
			break;
		dataFile >> fName;
		dataFile >> lName;
		dataFile >> rate;
		dataFile >> hours;
		vect.emplace_back(Person(fName, lName, rate, hours));
	}
}

void writeData(vector<Person> &vect)
{
	int i = 0;
	ofstream dataFile;
	dataFile.open("output.txt");
	for (i = 0; i < vect.size(); i++)
	{
		dataFile << vect[i].fullName() << " ";
		dataFile << vect[i].totalPay() << endl;
	}
}

int main()
{
	vector<Person> vect;
	readData(vect);
	writeData(vect);
	return 0;
}
