/*
File: mytypes.h
Description:
Course: 150018 C++ Workshop, Exercise 6, Question 3
Author: Dan Zilberstein
Students: eli ialoz 311201354
		& avishay farkash 205918790
*/
#include<iostream>
#include"PHD.h"
using namespace std;

//Checking if he is allowed to get a stipend	
bool PHD::stipend() {
	if (_numberOFcourses == 2 && _numberOFhours >= 25)
		return true;
	else
		return false;
}

void PHD::print() {
	cout << "ID:" << _id << endl;
	cout << "First name:" << _firstName << endl;
	cout << "Last name:" << _lastName << endl;
	cout << "Number of courses:" << _numberOFcourses << endl;
	cout << "Research hours:" << _numberOFhours << endl;
	cout << "========================" << endl;
}