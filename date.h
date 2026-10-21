#ifndef DATE_H
#define DATE_H
#include <string>

class Date {
	protected:
		std::string dateString;
		int month;
		int day;
		int year;
	public:
		Date();
		void init(std::string dateString);
		void printDate();
}; // end Date
#endif
