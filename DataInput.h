#pragma once

#include "UserInterface.h"

void SplitString(string s, string* ans);

void ConsoleInput(vector<Student> &students, ui & numberOfStudents);

bool FileInput(vector<Student>& students, fstream& fin, ui& numberOfStudents, string name);