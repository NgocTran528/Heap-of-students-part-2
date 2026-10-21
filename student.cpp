#include <iostream>
#include <sstream>
#include "student.h"

using namespace std;

Student::Student(){
	dob = new Date();
	expectedGrad = new Date();
	address = new Address();
	creditHours = 0;
} // end Student

Student::~Student(){
	delete dob;
	delete expectedGrad;
	delete address;
} // end ~Student

void Student::init(string ss) {
	studentString = ss;

	stringstream splitter;
	stringstream converter;
	string street, city, state, zip, dobStr, gradStr, creditStr;

	splitter.str(studentString);
	getline(splitter, firstName, ',');
	getline(splitter, lastName, ',');
	getline(splitter, street, ',');
	getline(splitter, city, ',');
	getline(splitter, state, ',');
	getline(splitter, zip, ',');
	getline(splitter, dobStr, ',');
	getline(splitter, gradStr, ',');
	getline(splitter, creditStr, ',');

	address->init(street, city, state, zip);
	dob->init(dobStr);
	expectedGrad->init(gradStr);
	
	converter.str(creditStr);
	converter >> creditHours;
} // end init

void Student::printStudent(){
	cout << firstName << " " << lastName << endl;
	address->printAddress();
	cout << "DOB: ";
	dob->printDate();
	cout << "Grad: ";
	expectedGrad->printDate();
	cout << "Credits: " << creditHours << endl;
	cout << "____________________________________" << endl;
} // end printStudent 

string Student::getFirstName(){
	return firstName;
} // end getFirstName;

string Student::getLastName(){
	return lastName;
} // end getLastName

int Student::getCreditHours(){
	return creditHours;
} // end getCreditHours

string Student::getLastFirst(){
	return lastName + ", " + firstName;
} // end getLastFirst
