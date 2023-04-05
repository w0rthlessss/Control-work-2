#pragma once
#include "Person.h"
#define ui unsigned int
class Student : public Person{

private:
	string name;
	string university;
	ui course;
	ui group;

public:
	Student();
	void SetInformation(string n, string s, string a, string u, ui c, ui g);
	void ShowInformation(ui number);
	string GetAll(ui number);
	string GetName();
	string GetUniversity();
	ui GetCourse();
	ui GetGroup();

};

