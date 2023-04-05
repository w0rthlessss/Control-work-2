#pragma once
#include "GetInfo.h"
class Person{

protected:
	string surname;
	string adress;
public:
	Person();
	void SetInformation(string s, string a);
	string GetSurname();
	string GetAdress();
};

