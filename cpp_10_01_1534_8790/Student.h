/*
File: mytypes.h
Description:
Course: 150018 C++ Workshop, Exercise 6, Question 3
Author: Dan Zilberstein
Students: eli ialoz 311201354
		& avishay farkash 205918790
*/
#ifndef _STUDENT
#define _STUDENT
#include<iostream>
#include<string>
#include"mytype.h"

class Student {
protected:
	uint _id;
	std::string _firstName;
	std::string _lastName;
	uint _numberOFcourses;

public:
	//Constractor
	Student() {}
	Student(uint id,std::string firstName, std::string lastName, uint numberOFcourses) :_id(id), _firstName(firstName), _lastName(lastName), _numberOFcourses(numberOFcourses) {}
	//pure virtual function
	virtual bool stipend() = 0;
	virtual void print() = 0;
	

	//destractor
	virtual ~Student() {
	};
};

#endif 