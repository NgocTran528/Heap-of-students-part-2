#include <iostream>
#include <sstream>
#include "date.h"
using namespace std;

Date::Date(){
	dateString = "";
	month = 1;
	day = 1;
	year = 2000;
} // end Date

void Date::init(string ds){
	dateString = ds;

	stringstream ss;
	stringstream converter;
	string monthStr, dayStr, yearStr;

	ss.str(dateString);
	getline(ss, monthStr, '/');
	getline(ss, dayStr, '/');
	getline(ss, yearStr);

	converter.clear();
	converter.str(monthStr);
	converter >> month;

	converter.clear();
	converter.str(dayStr);
	converter >> day;

	converter. clear();
	converter.str(yearStr);
	converter >> year;
} // end init

void Date::printDate(){
	string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << months[month - 1] << " " << day << ", " << year << endl;
} // end printDate
