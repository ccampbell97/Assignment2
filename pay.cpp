#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

int readData(Person *arr1, int size)
{
	int i;
	string fName, lName;
	float hours, rate;
	ifstream dataFile;
	dataFile.open("input.txt");
	for (i = 0; i < size - 1; i++)
	{
		if (dataFile.eof() == true)
			return i;
		dataFile >> fName;
		dataFile >> lName;
		dataFile >> hours;
		dataFile >> rate;
		arr1[i].setFirstName(fName);
		arr1[i].setLastName(lName);
		arr1[i].setHoursWorked(hours);
		arr1[i].setPayRate(rate);
	}
	return size;
}

void writeData(Person *arr1, int size)
{
	int i;
	ofstream dataFile;
	dataFile.open("output.txt");
	for (i = 0; i < size; i++)
	{
		dataFile << arr1[i].fullName() << " ";
		dataFile << arr1[i].totalPay() << endl;
	}
}

int main()
{
	Person arr1[20];
	int size = 20;
	size = readData(arr1, size);
	writeData(arr1, size);
}
