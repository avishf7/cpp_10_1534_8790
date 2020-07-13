/*
File: mytypes.h
Description:
Course: 150018 C++ Workshop, Exercise 6, Question 3
Author: Dan Zilberstein
Students: eli ialoz 311201354
		& avishay farkash 205918790
*/
#ifndef _BA
#define _BA
#include<iostream>
#include"Student.h"

class BA :public Student {
protected:
	uint _size;
	uint* _grades;

	uint Average(uint* grades);
public:
	//Constractor
	BA(uint id, std::string firstName, std::string lastName, uint numberOFcourses, uint size, uint* grades) :Student(id, firstName, lastName, numberOFcourses), _size(size), _grades(grades) {}
	//Checking if he is allowed to get a stipend	
	bool stipend();
	//Print the student's identity
	void print();
	//destractor
	~BA() {
		delete _grades;
		_grades = nullptr;
	};
};







#endif 

