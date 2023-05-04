#pragma once
#include "Student.h"
#include <fstream>
#include <vector>

enum WorkWithFiles { input, output };
enum TopMenu { console = 1, file, module, quit };
enum BottomMenu { all = 1, university, course, group, back };

void WorkWithConsole(vector<Student>& students, int& actionBottom);

void WorkWithFile(vector<Student>& students, int& actionBottom);

void PrintStudents(vector<Student>& students);

void Fio();

void OptionsTop();

void InputOption(int option);

void OptionsBottom();

void Task();

void IncorrectOption();

char SaveResults(fstream& fout, string msg);

void PrintConsoleData(fstream& fout, vector<Student>& students);

string OpenFile(int option, fstream& file);

void StartProgram();