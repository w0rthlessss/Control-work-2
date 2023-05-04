#include "Tasks.h"
#include <algorithm>

//сортировка вектора
void SortArray(vector<Student>& students)
{
	//sort(students.begin(), students.end(), Comparator);
	sort(students.begin(), students.end(), [](Student x, Student y) ->bool {
		if (x.GetUniversity() != y.GetUniversity()) return x.GetUniversity() < y.GetUniversity();
		if (x.GetName() != y.GetName()) return x.GetName() < y.GetName();
		if (x.GetSurname() != y.GetSurname()) return x.GetSurname() < y.GetSurname();
		if (x.GetAdress() != y.GetAdress()) return x.GetAdress() < y.GetAdress();
		if (x.GetCourse() != y.GetCourse()) return x.GetCourse() < y.GetCourse();
		return x.GetGroup() < y.GetGroup(); });
}

//сравнение строк без учета регистра
bool Comparison(string university, string chosenUniversity)
{
	if (university == chosenUniversity) return true;
	else {
		if (university.length() == chosenUniversity.length()) {
			for (int i = 0; i < university.length(); i++) {
				if (tolower(university[i]) != tolower(chosenUniversity[i])) {
					return false;
				}
			}
			return true;
		}
		else return false;
	}
}

//фильтр студентов по университету
void FilterByUniversity(ui numberOfStudents, vector<Student> &students)
{
	vector<Student> filtered;
	string chosenUniversity = GetString("\nEnter the university you want to see students from: ");
	for (ui i = 0; i < numberOfStudents; i++) {
		if (Comparison(students[i].GetUniversity(), chosenUniversity)) {
			filtered.push_back(students[i]);
		}
	}
	string line = "Students from the " + chosenUniversity + " university:\n\n";
	Print(filtered, line);
}

//фильтр студентов по курсу
void FilterByCourse(ui numberOfStudents, vector<Student>& students)
{
	vector<Student> filtered;
	ui chosenCourse = static_cast<ui>(GetInt("\nEnter the course you want to see students from: "));
	for (ui i = 0; i < numberOfStudents; i++) {
		if (students[i].GetCourse()==chosenCourse) {
			filtered.push_back(students[i]);
		}
	}
	string line = "Students from the " + to_string(chosenCourse) + " course:\n\n";
	Print(filtered, line);
}

//фильтр студентов по группе
void FilterByGroup(ui numberOfStudents, vector<Student>& students)
{
	vector<Student> filtered;
	ui chosenGroup = static_cast<ui>(GetInt("\nEnter the group you want to see students from: "));
	for (ui i = 0; i < numberOfStudents; i++) {
		if (students[i].GetGroup() == chosenGroup) {
			filtered.push_back(students[i]);
		}
	}
	string line = "Students from the " + to_string(chosenGroup) + " group:\n\n";
	Print(filtered, line);
}

//вывод на консоль и в файл
void Print(vector<Student>& filteredStudents, string line)
{
	fstream fout;
	SortArray(filteredStudents);

	if (!filteredStudents.size()) {
		cout << "There is no students by such category!\n\n";
		return;
	}
	cout << line;
	for (ui i = 0; i < filteredStudents.size(); i++) {
		filteredStudents[i].ShowInformation(i + 1);
	}

	char ans = SaveResults(fout, "results");
	if (ans == 'y') {
		fout << line;
		for (ui i = 0; i < filteredStudents.size(); i++) {
			fout << filteredStudents[i].GetAll(i + 1);
		}
		fout.close();
	}
}
