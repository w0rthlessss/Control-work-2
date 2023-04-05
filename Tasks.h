#pragma once
#include "UserInterface.h"

bool Comparator(Student x, Student y);

void Sort(vector<Student>& students);

bool Comparison(string university, string chosenUniversity);

void PrintAll(int mode, ui numberOfStudents, vector<Student>& students);

void FilterByUniversity(int mode, ui numberOfStudents, vector<Student>& students);

void FilterByCourse(int mode, ui numberOfStudents, vector<Student>& students);

void FilterByGroup(int mode, ui numberOfStudents, vector<Student>& students);

void Print(int mode, vector<Student>& filteredStudents, string line);