/*
File: mytypes.h
Description:
Course: 150018 C++ Workshop, Exercise 6, Question 3
Author: Dan Zilberstein
Students: eli ialoz 311201354
		& avishay farkash 205918790
*/
#include<iostream>
#include"BA.h"
using namespace std;
//Average tester
uint BA:: Average(uint* grades) {
	uint sum = 0;
	for (uint i = 0; i < _size; i++) 
		sum += grades[i];
	
	return sum /_size;
}
//Checking if he is allowed to get a stipend	
 bool BA::stipend() {
	 if (_numberOFcourses >= 10 && Average(_grades) > 95)
		 return true;
	 else
		 return false;
}
 //Print the student's identity
 void BA::print() {
	 cout << "ID:" << _id << endl;
	 cout << "First name:" <<_firstName << endl;
	 cout << "Last name:" <<_lastName << endl;
	 cout << "Number of courses:" << _numberOFcourses << endl;
	 cout << "Grades:";
	 for (uint i = 0; i < _size; i++)
		 cout << _grades[i] << " ";

	 cout << endl;
	 cout << "========================" << endl;
  }