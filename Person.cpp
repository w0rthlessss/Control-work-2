#include "Person.h"

Person::Person()
{
	surname = "";
	adress = "";
}

void Person::SetInformation(string s, string a)
{
	surname = s;
	adress = a;
}

string Person::GetSurname()
{
	return surname;
}

string Person::GetAdress()
{
	return adress;
}
