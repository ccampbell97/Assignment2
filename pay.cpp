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
		//Person employ(fName, lName, rate, hours);
		/*vect.emplace_back(fName, lName, rate, hours);
		cout << vect[i].getFirstName() << endl;
		cout << vect[i].getLastName() << endl;
		cout << vect[i].getPayRate() << endl;
		cout << vect[i].getHoursWorked() << endl;
		i = i + 1;*/
		/*employ.setFirstName(fName);
		employ.setLastName(lName);
		employ.setHoursWorked(hours);
		employ.setPayRate(rate);*/
		vect.emplace_back(Person(fName, lName, rate, hours));
		//vect.emplace_back(employ);
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
