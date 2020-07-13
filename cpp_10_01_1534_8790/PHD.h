/*
File: mytypes.h
Description:
Course: 150018 C++ Workshop, Exercise 6, Question 3
Author: Dan Zilberstein
Students: eli ialoz 311201354
		& avishay farkash 205918790
*/
#ifndef _PHD
#define _PHD
#include<iostream>
#include"Student.h"

class PHD :public Student {
private:
	uint _numberOFhours;
public:
	//Constractor
	PHD(uint id, std::string firstName, std::string lastName, uint numberOFcourses, uint numberOFhours):Student(id,firstName,lastName,numberOFcourses),_numberOFhours(numberOFhours){}
	//Checking if he is allowed to get a stipend	
	bool stipend();
	//Print the student's identity
	void print();
};

#endif 

