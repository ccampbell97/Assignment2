#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include <vector>

using namespace std;

void readData(vector<Person> &vect)
{
	int i = 0;
	Person employ;
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
		vect.emplace_back(fName, lName, rate, hours);
		/*employ.setFirstName(fName);
		employ.setLastName(lName);
		employ.setHoursWorked(hours);
		employ.setPayRate(rate);*/
		vect.push_back(employ);
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
