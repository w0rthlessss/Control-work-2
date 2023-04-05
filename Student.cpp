#include "Student.h"

Student::Student()
{
	name = "";
	surname = "";
	adress = "";
	university = "";
	course = 1;
	group = 1;
}

void Student::SetInformation(string n, string s, string a, string u, ui c, ui g)
{
	name = n;
	surname = s;
	adress = a;
	university = u;
	course = c;
	group = g;
}

void Student::ShowInformation(ui number)
{
	cout << "Information about student #" << number << ":\n";
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Adress: " << adress << endl;
	cout << "University: " << university << endl;
	cout << "Course: " << course << endl;
	cout << "Group: " << group << endl << endl;
}

string Student::GetAll(ui number)
{
	return "Information about student #" + to_string(number) + ":\n"
		+ "Name: " + name + '\n' + "Surname: " + surname + '\n'
		+ "Adress: " + adress + '\n' + "University: " + university + '\n'
		+ "Course: " + to_string(course) + '\n' + "Group: " + to_string(group) + "\n\n";
}

string Student::GetName()
{
	return name;
}

string Student::GetUniversity()
{
	return university;
}


ui Student::GetCourse()
{
	return course;
}

ui Student::GetGroup()
{
	return group;
}


