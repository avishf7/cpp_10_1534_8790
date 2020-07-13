/*
File: mytypes.h
Description:
Course: 150018 C++ Workshop, Exercise 6, Question 3
Author: Dan Zilberstein
Students: eli ialoz 311201354
		& avishay farkash 205918790
*/
#ifndef _MA
#define _MA
#include<iostream>
#include"BA.h"

class MA :public BA {
private:
	bool _participate;
public:
	//Constractor
	MA(uint id, std::string firstName, std::string lastName, uint numberOFcourses, uint size, uint* grades,bool participate):BA(id,firstName,lastName,numberOFcourses, size,grades), _participate(participate){}
	//Checking if he is allowed to get a stipend	
	bool stipend()override;
	//Print the student's identity
	void print();
};
#endif 

