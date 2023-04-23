#include "Person.h"

//конструктор по умолчанию
Person::Person()
{
	surname = "";
	adress = "";
}

//заполнение полей класса
void Person::SetInformation(string s, string a)
{
	surname = s;
	adress = a;
}

//получить поле "фамилия"
string Person::GetSurname()
{
	return surname;
}

//получить поле "адрес"
string Person::GetAdress()
{
	return adress;
}
