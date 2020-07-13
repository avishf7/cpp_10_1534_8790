/*
File: mytypes.h
Description:
Course: 150018 C++ Workshop, Exercise 6, Question 3
Author: Dan Zilberstein
Students: eli ialoz 311201354
		& avishay farkash 205918790
*/
#include<iostream>
#include"MA.h"
using namespace std;

//Checking if he is allowed to get a stipend	
bool MA::stipend() {
	if (_numberOFcourses >=7 && Average(_grades) > 90 && _participate)
		return true;
	else
		return false;
}
//Print the student's identity
void MA::print() {
	cout << "ID:" << _id << endl;
	cout << "First name:" << _firstName << endl;
	cout << "Last name:" << _lastName << endl;
	cout << "Number of courses:" << _numberOFcourses << endl;
	cout << "Grades:";
	for (uint i = 0; i < _size; i++)
		cout << _grades[i] << " ";

	if (_participate) 
	cout<< endl << "Research:" << "yes" << endl;

	cout << "========================" << endl;
}