#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<string>
#include"menu.h"
#include"student.h"
#include"BA.h"
#include"MA.h"
#include"PHD.h"

using namespace std;

void add(vector<Student*>& vec)
{
	int choice;
	bool ifResearch;
	uint id, numOfCourses, researchHours;
	string firstName, lastName;
	uint* grades;

	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> choice;

	cout << "enter id, first name, last name and number Of Courses\n";
	cin >> id >> firstName >> lastName >> numOfCourses;

	switch (choice)
	{
	case 1:
		grades = new uint[numOfCourses];

		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++)
		{
			cout << i + 1 << ". ";
			cin >> grades[i];
			cout << endl;
			if (grades[i] > 100 || grades[i] < 1)
			{
				cout << "\nERROR: invaild grade\n";
				i--;
			}
		}

		vec.push_back(new BA(id, firstName, lastName, numOfCourses, numOfCourses, grades));
		break;
	case 2:
		grades = new uint[numOfCourses];

		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++)
		{
			cout << i + 1 << ". ";
			cin >> grades[i];
			cout << endl;
			if (grades[i] > 100 || grades[i] < 1)
			{
				cout << "\nERROR: invaild grade\n";
				i--;
			}
		}

		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> ifResearch;

		vec.push_back(new MA(id, firstName, lastName, numOfCourses, numOfCourses, grades, ifResearch));
		break;
	case 3:
		cout << "enter number of research hours\n";
		cin >> researchHours;

		vec.push_back(new PHD(id, firstName, lastName, numOfCourses, researchHours));
			break;
	}

}
void milga(vector<Student*>& vec) 
{
	for (vector<Student*>::iterator it = vec.begin(); it != vec.end(); it++) 
		if ((*it)->stipend())
			(*it)->print();
}
Student* mostResearchHours(vector<Student*> vec) 
{
	vector<Student*>::iterator max = find_if(vec.begin(),vec.end(), [](Student* st) {return st->studType() == "PHD"; });

	for (vector<Student*>::iterator it = max + 1; it != --vec.end(); it++)
		if ((*it)->studType() == "PHD" && *((PHD*)*max) < *((PHD*)*it))
				max = it;

	vec.pop_back();
	return *max; 
}

int main() {
	vector<Student*> vec;
	MenuOption choice;
	Student* ptrStud;

	while ((choice = menu()) != EXIT) {
		int num;

		switch (choice) {
		case ADD_NEW_STUDENT:
			add(vec);
			break;

		case STIPEND_LIST:
			milga(vec);	
			break;

		case MOST_RESEARCH:
			ptrStud = mostResearchHours(vec);
			cout << "PHD studnet with most research hours: ";
			cout << ptrStud->firstName() << ' ' << ptrStud->lastName() << endl;
			break;

		case COUNT_STIPEND_BA:
			cout << "number of BA studnets for milga: " << count_if(vec.begin(),vec.end(), [](Student* st) {return (st->studType() == "BA" && st->stipend()); }) << endl;
			break;

		case NO_RESEARCH_MA:
			cout << "list of no research MA students : ";
			for_each(vec.begin(),vec.end(), [](Student* st) {if (st->studType() == "MA" && !(((MA*)st)->participate())) cout << st->firstName() << " " << st->lastName() << endl; });
			cout << endl;
			break;

		case OVERHEAD_STUDENT:
			if (any_of(vec.begin(), vec.end(), [](Student* st) { return st->numberOFcourses() > 15; }))
				cout << "there is a student that takes more than 15 courses\n";
			else
				cout << "no student takes more than 15 courses\n";
			break;

		case REMOVE_PHD_FAILERS:
			vec.resize(remove_if(vec.begin(), vec.end(), [](Student* st) { return st->studType() == "PHD" && !(st->numberOFcourses()); }) - vec.begin());
			for_each(vec.begin(), vec.end(), [](Student* st) {st->print(); });
			break;

		default:
			cout << "ERROR!" << endl;
		}
	}

	return 0;
}
