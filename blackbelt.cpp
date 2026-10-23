#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudents(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);

std::string menu();

bool byLastName(Student* a, Student* b);
bool byFirstName(Student* a, Student* b);
bool byCredits(Student* a, Student* b);


int main(){	
	std::vector<Student*> students;
	loadStudents(students);
	
	std::string choice ="";
	while (choice != "0"){
		choice = menu();
		if (choice == "1") {
			showStudentNames(students);
		} else if (choice == "2"){
			printStudents(students);
		} else if (choice == "3"){
			findStudents(students);
		} else if (choice == "4") {
			std::sort(students.begin(), students.end(), byLastName);
			std::cout << "sorted by last name" << std::endl;
		} else if (choice == "5") {
			std::sort(students.begin(), students.end(), byFirstName);
			std::cout << "sorted by first name" << std::endl;	
		} else if (choice == "6") {
			std::sort(students.begin(), students.end(), byCredits);
			std::cout << "sorted by credit hours" << std::endl;
		} else if (choice == "0") {
			std::cout << "bye" << std::endl;
		} else {
			std::cout << "not a valid choice" << std::endl;
		} // end if
	} // end while
	
	delStudents(students);
	return 0;
} // end main

void loadStudents(std::vector<Student*>& students){
	std::ifstream inFile;
	std::string line;
	inFile.open("students.csv");
	while (std::getline(inFile, line)){
		Student* s = new Student();
		s->init(line);
		students.push_back(s);
	} // end while
	inFile.close();
} // end loadStudents

void showStudentNames(std::vector<Student*>& students){
	for (auto& s : students){
		std::cout << s-> getLastFirst() << std::endl;
	} // end for
} // end showStudentNames

void printStudents(std::vector<Student*>& students){
	for (auto& s : students) {
		s->printStudent();
	} // end for
} // end printStudents

void findStudents(std::vector<Student*>& students){
	std::string target;
	std::cout << "last name of student: ";
	std::getline(std::cin, target);
	for (auto& s : students) {
		if (s->getLastName().find(target) != std::string::npos){
			s->printStudent();
		} // end if
	} // end for
} // end findStudents

void delStudents(std::vector<Student*>& students){
	for (auto& s : students){
		delete s;
	} // end for
} // end delStudents

std::string menu(){
	std::string choice;
	std::cout << std::endl;
	std::cout << "0) quit" << std::endl;
	std::cout << "1) print all student names" << std::endl;
	std::cout << "2) print all student data" << std::endl;
	std::cout << "3) find a student" << std::endl;
	std::cout << "4) sort by last name" << std::endl;
	std::cout << "5) sort by first name" << std::endl;
	std::cout << "6) sort by credit hours" <<std::endl;
	std::cout << std::endl;
	std::cout<< "please choose 0-6: ";
	std::getline(std::cin, choice);
	return choice;
} // end menu

bool byLastName(Student* a, Student* b) {
	return a->getLastName() < b -> getLastName();
} // end byLastName

bool byFirstName(Student* a, Student* b) {
	return a->getFirstName() < b->getFirstName();
} // end byFirstName

bool byCredits(Student* a, Student* b) {
	return a-> getCreditHours() > b-> getCreditHours();
} // end byCredits 
