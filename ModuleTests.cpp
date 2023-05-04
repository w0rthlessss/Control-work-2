#include "ModuleTests.h"
#include "DataInput.h"
#include <sstream>

bool Check(vector<Student>& testArray, vector<Student>& testArrayFile, int lim)
{
	for (int i = 0; i < lim; i++) {
		if (testArray[i].GetName() != testArrayFile[i].GetName() ||
			testArray[i].GetSurname() != testArrayFile[i].GetSurname() ||
			testArray[i].GetAdress() != testArrayFile[i].GetAdress() ||
			testArray[i].GetUniversity() != testArrayFile[i].GetUniversity() ||
			testArray[i].GetCourse() != testArrayFile[i].GetCourse() ||
			testArray[i].GetGroup() != testArrayFile[i].GetGroup()
			) return false;

	}
	return true;
}

bool Test1()
{
	//проверка ввода данных с файла
	//cout << "\tTEST#1\n\tTesting file input...\n\n";
	
	fstream fin;
	ui numberOfStudents = 0;
	const string fileName = "test_info.txt";
	fin.open(fileName, ios::in);

	if (!fin.is_open()) {
		cout << "Test#1: FAILURE!\nMissing test file \"" << fileName<<"\"!\n\n";
		return false;
	}

	vector<Student> test_array(ValuesForModuleTests::first);
	vector<Student> test_array_file;

	test_array[0].SetInformation("Ilya", "Ekkert", "Berlin", "ITMO", 1, 978);
	test_array[1].SetInformation("Dmitriy", "Kaplunov", "Krasnoyarsk", "SIBGU", 2, 576);

	if (!FileInput(test_array_file, fin, numberOfStudents, fileName)) {
		cout << "Test#1: FAILURE!\nValues from inside the program and values from the test file do not match!\n\n";
		return false;
	}

	if (!Check(test_array, test_array_file, ValuesForModuleTests::first)) {
		cout << "Test#1: FAILURE!\nValues from inside the program and values from the test file do not match!\n\n";
		return false;
	}
	return true;

}

bool Test2()
{
	//фильтр по университету
	//cout << "\tTEST#2\n\tTesting unviersity filter function...\n\n";

	fstream fin;
	const string fileName = "test_info.txt";
	fin.open(fileName, ios::in);
	string res = "", resFile = "";

	if (!fin.is_open()) {
		cout << "Test#2: FAILURE!\nMissing test file \"" << fileName << "\"!\n\n";
		return false;
	}

	ui numberOfStudents = 0;

	vector<Student> test_array(ValuesForModuleTests::second);

	test_array[0].SetInformation("Ilya", "Ekkert", "Berlin", "ITMO", 1, 978);
	test_array[1].SetInformation("Dmitriy", "Kaplunov", "Krasnoyarsk", "SIBGU", 2, 576);

	res = test_array[1].GetUniversity();

	vector<Student> test_array_file;

	if (!FileInput(test_array_file, fin, numberOfStudents, fileName)) {
		cout << "Test #2: FAILURE!\nValues from inside the program and values from the test file do not match!\n\n";
		return false;
	}

	for (ui i = 0; i < numberOfStudents; i++) {
		if (Comparison(test_array_file[i].GetUniversity(), res)) {
			resFile = test_array_file[i].GetUniversity(); break;
		}
	}

	if (res != resFile) {
		cout << "Test#2: FAILURE!\nIncorrect answer\n\n";
		return false;
	}
	return true;
}

bool Test3()
{
	//фильтр по группе
	//cout << "\tTEST#3\n\tTesting group filter function...\n\n";

	fstream fin;
	const string fileName = "test_info.txt";
	fin.open(fileName, ios::in);
	ui res = 0, resFile = 0;

	if (!fin.is_open()) {
		cout << "Test#3: FAILURE!\nMissing test file \"" << fileName << "\"!\n\n";
		return false;
	}

	ui numberOfStudents = 0;

	vector<Student>test_array(ValuesForModuleTests::third);
	test_array[0].SetInformation("Ilya", "Ekkert", "Berlin", "ITMO", 1, 978);
	test_array[1].SetInformation("Dmitriy", "Kaplunov", "Krasnoyarsk", "SIBGU", 2, 576);
	test_array[2].SetInformation("Mikhail", "Zubenko", "Moldavia", "MGU", 1, 123);

	vector<Student>test_array_file;

	if (!FileInput(test_array_file, fin, numberOfStudents, fileName)) {
		cout << "Test#3: FAILURE!\nValues from inside the program and values from the test file do not match!\n\n";
		return false;
	}

	res = test_array[2].GetGroup();

	for (ui i = 0; i < numberOfStudents; i++) {
		if (test_array_file[i].GetGroup() == res) {
			resFile = test_array_file[i].GetGroup(); break;
		}
	}

	if (resFile != res) {
		cout << "Test#3: FAILURE!\nIncorrect answer\n\n";
		return false;
	}

	return true;
}

bool Test4()
{
	//корректность счёта строк в файле
	//cout << "\tTEST#4\n\tTesting correctness of counting lines in a file...\n\n";

	fstream fin;
	const string fileName = "test_info.txt";
	fin.open(fileName, ios::in);

	if (!fin) {
		cout << "Test#4: FAILURE!\nMissing test file \"" << fileName << "\"!\n\n";
		return false;
	}

	ui numberOfStudents = 0;

	vector<Student> test_array(ValuesForModuleTests::fourth);

	if (!FileInput(test_array, fin, numberOfStudents, fileName)) {
		cout << "Test#4: FAILURE!\nValues from inside the program and values from the test file do not match!\n\n";
		return false;
	}

	if (numberOfStudents != ValuesForModuleTests::fourth) {
		cout << "Test#4: FAILURE!\nIncorrect amount of data in the file!\n\n";
		return false;
	}

	return true;
}
bool Test5(){
	//корректность работы ввода с консоли
	//cout << "\tTEST#5\n\tTesting console input...\n\n";
	{
		istringstream test("576\n\n");
		streambuf* cinbuf = cin.rdbuf(test.rdbuf());

		bool res = (GetInt("") == 576);

		if (!res) {
			cout << "FAILURE!\nIncorrect console input!\n\n";
			return false;
		}

		cin.rdbuf(cinbuf);
	}
	return true;
}

void LaunchAllTests()
{
	bool tests[5] = { Test1(), Test2(), Test3(), Test4(), Test5() };


	if (tests[0] && tests[1] && tests[2] && tests[3] && tests[4]) cout << "All tests SUCCEDED!\n\n";
}
