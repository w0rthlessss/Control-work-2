#pragma once
#include "Student.h"
#include "Tasks.h"

enum ValuesForModuleTests { first = 2, second = 2, third = 3, fourth = 7 };

bool Check(vector<Student> &test, vector<Student> &fileTest, int lim);

bool Test1();

bool Test2();

bool Test3();

bool Test4();

bool Test5();

void LaunchAllTests();