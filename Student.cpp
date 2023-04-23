#include "Student.h"

//конструктор по умолчанию
Student::Student()
{
	name = "";
	surname = "";
	adress = "";
	university = "";
	course = 1;
	group = 1;
}

//заполнение полей класса
void Student::SetInformation(string n, string s, string a, string u, ui c, ui g)
{
	name = n;
	surname = s;
	adress = a;
	university = u;
	course = c;
	group = g;
}

//вывод информации об объекте на консоль
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

//получить информацию об объекте в виде строки
string Student::GetAll(ui number)
{
	return "Information about student #" + to_string(number) + ":\n"
		+ "Name: " + name + '\n' + "Surname: " + surname + '\n'
		+ "Adress: " + adress + '\n' + "University: " + university + '\n'
		+ "Course: " + to_string(course) + '\n' + "Group: " + to_string(group) + "\n\n";
}

//получить поле "имя"
string Student::GetName()
{
	return name;
}

//получить поле "университет"
string Student::GetUniversity()
{
	return university;
}

//получить поле "курс"
ui Student::GetCourse()
{
	return course;
}

//получить поле "группа"
ui Student::GetGroup()
{
	return group;
}


