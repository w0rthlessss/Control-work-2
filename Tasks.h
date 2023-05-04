#pragma once
#include "UserInterface.h"

void SortArray(vector<Student>& students);

bool Comparison(string university, string chosenUniversity);

void FilterByUniversity(ui numberOfStudents, vector<Student>& students);

void FilterByCourse(ui numberOfStudents, vector<Student>& students);

void FilterByGroup(ui numberOfStudents, vector<Student>& students);

void Print(vector<Student>& filteredStudents, string line);