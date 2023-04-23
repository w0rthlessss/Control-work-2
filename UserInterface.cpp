#include "UserInterface.h"
#include "Tasks.h"
#include "DataInput.h"
#include "ModuleTests.h"
#include <filesystem>

using namespace filesystem;

//чтение данных с консоли и работа с ними
void WorkWithConsole(vector<Student>& students, int& actionBottom)
{
	ui numberOfStudents = 0;
	actionBottom = 1;

	ConsoleInput(students, numberOfStudents);
	while (actionBottom != BottomMenu::back) {
		OptionsBottom();
		actionBottom = GetInt(">>");
		switch (actionBottom)
		{
		case BottomMenu::all:
			Print(TopMenu::console, students, "All students we have data about:\n\n");
			break;
		case BottomMenu::university:
			FilterByUniversity(TopMenu::console, numberOfStudents, students);
			break;
		case BottomMenu::course:
			FilterByCourse(TopMenu::console, numberOfStudents, students);
			break;
		case BottomMenu::group:
			FilterByGroup(TopMenu::console, numberOfStudents, students);
			break;
		case BottomMenu::back:
			system("cls");
			Fio();
			break;
		default:
			IncorrectOption();
			break;
		}
	}
}

//чтение данных из файла и работа с ними
void WorkWithFile(vector<Student>& students, int& actionBottom)
{
	ui numberOfStudents = 0;
	fstream docIn, docOut;
	bool isCorrect = false;
	do {
		string inputName = OpenFile(WorkWithFiles::input, docIn);
		isCorrect = FileInput(students, docIn, numberOfStudents, inputName);
		docIn.close();
	} while (isCorrect == false);

	while (actionBottom != BottomMenu::back) {
		OptionsBottom();
		actionBottom = GetInt(">>");

		switch (actionBottom)
		{
		case BottomMenu::all:
			Print(TopMenu::file, students, "All students we have data about:\n\n");
			break;
		case BottomMenu::university:
			FilterByUniversity(TopMenu::file, numberOfStudents, students);
			break;
		case BottomMenu::course:
			FilterByCourse(TopMenu::file, numberOfStudents, students);
			break;
		case BottomMenu::group:
			FilterByGroup(TopMenu::file, numberOfStudents, students);
			break;
		case BottomMenu::back:
			system("cls");
			Task();
			Fio();
			break;
		default:
			IncorrectOption();
			break;
		}
	}
}

void Fio()
{
	cout << "Control work #2\nEfremov Ivan Andreevich\nGroup #423\nVariant #8\n\n";
}

//меню верхнего уровн€
void OptionsTop()
{
	cout << "1 - Console input\n2 - File input\n3 - Run module tests\n4 - Exit\n\n";
}

void InputOption(int option)
{
	if (option == TopMenu::console) {
		cout << "\n<<Console Input>>\n\n";
	}
	else if (option == TopMenu::file) {
		cout << "\n<<File Input>>\n\n";
	}
}

//меню нижнего уровн€
void OptionsBottom()
{
	cout << "\n\n1 - List of all students\n";
	cout << "2 - Filter students by university\n";
	cout << "3 - Filter students by course\n";
	cout << "4 - Filter students by group\n";
	cout << "5 - Back\n\n";
}

//формулировка задани€
void Task()
{
	cout << "Create class \"Student\" (fields: \"name\", \"university\", \"course\", \"group\"),\nbased on the class \"Person\" (fields: \"surname\", \"adress\").\n";
	cout << "Create an array of objects of the class \"Student\". Realize the ability of:\n";
	cout << "1 - printing data about all students\n2 - filtrating students by university\n3 - filtrating students by course\n4 - filtrating students by group\n";
	cout << "\nData of each patient in the file must be written as:\n";
	cout << "\"name_1\" \"surname_1\" \"adress_1\" \"university_1\" \"course_1\" \"group_1\"\n";
	cout << ".\n.\n.\n\"name_n\" \"surname_n\" \"adress_n\" \"university_n\" \"course_n\" \"group_n\"\n\n";
}

void IncorrectOption()
{
	cout << "\nThere is no such option in menu!\n\n";
}

//предложить пользователю сохранить результаты работы программы в файл
char SaveResults(fstream& fout, string msg)
{
	string name;

	cout << "Do you want to save"<<msg<<"  in the file ? (y / n)\n\n";
	char res = 'n';
	do {
		res = GetChar(">>");
		if (res != 'y' && res != 'n') {
			cout << "Incorrect input. Type 'y' or 'n' only!\n\n";
		}
	} while (res != 'y' && res != 'n');
	if (res == 'y') {
		name = OpenFile(WorkWithFiles::output, fout);
	}

	return res;
}

void PrintConsoleData(fstream& fout, vector<Student>& students)
{
	for (ui i = 0; i < students.size(); i++) {
		fout << students[i].GetName() << ' ' <<
			students[i].GetSurname() << ' ' <<
			students[i].GetUniversity() << ' ' <<
			students[i].GetCourse() << ' ' <<
			students[i].GetGroup() << endl;
	}
}

//открытие файла дл€ чтени€ или записи
string OpenFile(int option, fstream& file)
{
	string name = "";
	error_code ec;
	if (option == WorkWithFiles::input) {
		do {
			name = GetLink("\nEnter the name of file with data. Example: students.txt\n");
			file.open(name, ios::in);
			if (!file.is_open()) {
				cout << "\nError opening file. Make sure, that file exists!\n";
				continue;
			}
			
			if (!is_regular_file(name, ec)) {
				cout << "\nAdress contains forbidden value. Try another file path!\n";
				continue;
			}

		} while (true);
		return name;

	}
	else {
		do {
			name = GetLink("\nEnter the name of file where results will be stored.\nIf there is data in the file it will be overwritten.\nExample: filtered.txt\n");

			file.open(name, ios::out, ios::trunc);

			if (!is_regular_file(name, ec)) {
				cout << "\nAdress contains forbidden value. Try another file path!\n";
				continue;
			}

		} while (true);
		return name;
	}
}

//основна€ структура программы
void StartProgram()
{
	vector <Student> students;
	int actionTop = 1, actionBottom = 1;
	Task();
	Fio();
	while (actionTop) {
		OptionsTop();
		actionTop = GetInt(">>");
		InputOption(actionTop);
		switch (actionTop)
		{
		case TopMenu::console:

			WorkWithConsole(students, actionBottom);
			break;

		case TopMenu::file:
			WorkWithFile(students, actionBottom);
			break;

		case TopMenu::module:
			LaunchAllTests();
			break;

		case TopMenu::quit:
			cout << "\nProgramm finished it's work!\n";
			exit(EXIT_SUCCESS);

		default:

			IncorrectOption();
			break;

		}
	}
}
