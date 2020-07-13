/*
File: mytypes.h
Description:
Course: 150018 C++ Workshop, Exercise 6, Question 3
Author: Dan Zilberstein
Students: eli ialoz 311201354
		& avishay farkash 205918790
*/
#include<iostream>
#include"Student.h"
#include"BA.h"
#include"MA.h"
#include"PHD.h"

void Confirmed(Student** s) {
	for (uint i = 0; i < 7; i++) {
		if (s[i]->stipend())
			s[i]->print();
	}
}

int main() {
	Student* Studentarr[7];

	Studentarr[0] = new BA(123, "Abe", "Avraham", 3, 3, new uint[]{ 90,100,90 });
	Studentarr[1] = new BA(234, "Yitzhak", "Avrahamson", 10, 10,new uint[]{ 100,100,90,100,90,100,90,100,90,100 });
	Studentarr[2] = new MA(345, "Yaacov", "Jacobson", 7, 7, new uint[]{ 90, 100, 90, 100, 90, 100, 90 }, false);
	Studentarr[3] = new MA(456, "Sara", "Emanu", 7, 7, new uint[]{ 90, 100, 90, 100, 90, 100, 90 }, true);
	Studentarr[4] = new PHD(567, "Rivka", "Imanu", 1, 30);
	Studentarr[5] = new PHD(678, "Rachel", "Jacobs", 2, 20);
	Studentarr[6] = new PHD(789, "Leah", "Jacobs", 2, 30);

	Confirmed(Studentarr);

	for (uint i = 0; i < 7; i++)
		delete  Studentarr[i];
	
	return 0;
}

