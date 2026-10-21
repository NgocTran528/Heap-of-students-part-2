#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudents(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);

std::string menu();
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
} // end findStudent

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
	std::cout << std::endl;
	std::cout<< "please choose 0-3: ";
	std::getline(std::cin, choice);
	return choice;
} // end menu

void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate

void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst() << std::endl;
  delete student;
} // end testStudent
