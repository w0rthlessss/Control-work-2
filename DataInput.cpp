#include "DataInput.h"

#define arguments 6


//разделение строки по пробелам и заполнение массива полученными значениями
void SplitString(string s, string* ans)
{
	string cur = "";
	ui cnt = 0;

	for (int i = 0; i < arguments; i++) ans[i] = "";

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			ans[cnt] = cur;
			cur = "";
			cnt++;
		}
		else if (i == s.length() - 1) {
			cur += s[i];
			ans[cnt] = cur;
		}
		else cur += s[i];
	}
}

//ввод данных с консоли
void ConsoleInput(vector<Student>& students, ui& numberOfStudents)
{
	fstream fout;
	string n = "", s = "", a = "", u = "", tmp="";
	ui c = 0, g = 0;

	numberOfStudents = static_cast<ui>(GetInt("\nEnter number of students : "));

	students.resize(numberOfStudents);

	for (ui i = 0; i < numberOfStudents; i++) {
		cout << "\nStudent " << i + 1 << ":\n";

		n = GetString("Enter name of student #", i + 1);
		s = GetString("Enter surname of student #", i + 1);
		a = GetString("Enter adress of student #", i + 1);
		u = GetString("Enter university of student #", i + 1);

		tmp = "Enter course of student #" + to_string(i + 1) + ": ";
		g = static_cast<ui>(GetInt(tmp));

		tmp = "Enter group number of student #" + to_string(i + 1) + ": ";
		c = static_cast<ui>(GetInt(tmp));
		students[i].SetInformation(n, s, a, u, c, g);
	}

	if (SaveResults(fout, "data")=='y') {
		PrintConsoleData(fout, students);
	}
}

//ввод данных с файла
bool FileInput(vector<Student>& students, fstream &fin, ui &numberOfStudents, string name)
{
	string args[arguments];
	ui lineNumber = 0, j = 0, course = 0, group = 0;
	string tmp = "";
	char* trash;

	//подсчет количества данных о разных студентах в файле
	while (getline(fin, tmp)) {
		if (!tmp.empty()) numberOfStudents++;
	}
	fin.close();

	if (numberOfStudents == 0) {
		cout << "ERROR!\nThere is no correct data in the file\n";
		cout << "Choose another file or edit the current one\n\n";
		return false;
	}

	students.resize(numberOfStudents);

	fin.open(name);

	while (getline(fin, tmp) && j < numberOfStudents) {
		lineNumber++;
		if (!tmp.empty()) {
			SplitString(tmp, args);
			for (int i = 0; i < arguments; i++) {
				if (args[i] == "" || args[i] == " ") {
					cout << "\nERROR!\nCheck file line #" << lineNumber << "\nIt may be incorrect space input or incorrect amount of values\n";
					cout << "Choose another file or edit the current one\n\n";
					students.clear();
					return false;
				}
			}

			course = (strtol(args[4].c_str(), &trash, 10));
			group = (strtol(args[5].c_str(), &trash, 10));

			//проверка на положительность значения курса
			if (course <= 0) {
				cout << "\nERROR!\nCheck file line #" << lineNumber << "\nCourse number must be >0!\n";
				cout << "Choose another file or edit the current one\n\n";
				students.clear();
				return false;
			}

			//проверка на положительность значения группы
			if (group <= 0) {
				cout << "\nERROR!\nCheck file line #" << lineNumber << "\nGroup number must be >0!\n";
				cout << "Choose another file or edit the current one\n\n";
				students.clear();
				return false;
			}

			//проверка перевелась ли строка полностью к типу unsigned int
			if (static_cast<ui>(course) != static_cast<ui>(stoi(args[4]))) {
				cout << "\nERROR!\nCheck file line #" << lineNumber << "\nCourse number must be integer!\n";
				cout << "Choose another file or edit the current one\n\n";
				students.clear();
				return false;
			}
			if (static_cast<ui>(group) != static_cast<ui>(stoi(args[5]))) {
				cout << "\nERROR!\nCheck file line #" << lineNumber << "\nGroup number must be integer!\n";
				cout << "Choose another file or edit the current one\n\n";
				students.clear();
				return false;
			}

			//заполнение полей класса для i-того элемента
			students[j].SetInformation(args[0], args[1], args[2], args[3], course, group);
			j++;

		}
	}
	fin.close();
	return true;


}



