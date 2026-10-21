#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "address.h"
#include "date.h"

class Student {
	protected:
		std::string studentString;
		std::string firstName;
		std::string lastName;
		Date* dob;
		Date* expectedGrad;
		Address* address;
		int creditHours;
	public:
		Student();
		~Student();
		void init(std::string studentString);
		void printStudent();
		std::string getFirstName();
		std::string getLastName();
		int getCreditHours();
		std::string getLastFirst();
}; // end Student
#endif
