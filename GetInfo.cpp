#include "GetInfo.h"

//������� ������ �����
void IgnoreLine()
{
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

//���������� ������ ����� � �������
int GetInt(string s) {
	cout << s;
	int tmp = 0;
	while (true) {
		cin >> tmp;
		if (cin.fail()) {
			cin.clear();
			IgnoreLine();
			cout << "\nUse correct values!\n\n";
			cout << s;
		}
		else if (tmp <= 0) {
			cout << "\nValue must be >0\n\n";
			cin.clear();
			IgnoreLine();
			cout << s;
		}
		else {
			IgnoreLine();
			return tmp;
		}
	}
}

//���������� ������ � �������, �������� ����� ������� ��� �������� ������ �����������
string GetString(string s, int i)
{
	string a = "";
	while (true) {
		cout << s << i << ": ";
		cin >> a;
		if (getchar() != '\n') {
			cout << "\nInput only one word per line!\n";
			cout << s;
			cin.clear();
			IgnoreLine();
		}
		else if (a.empty()) {
			cout << "\nYou must enter a word!\n";
			cout << s;
			cin.clear();
			IgnoreLine();
		}
		else return a;
	}
}

//���������� ���� ������ ��� �������� ������ �����
string GetLink(string s)
{
	string b = "";
	cout << s;
	cout << "Path must not contain cyrillic symbols!\n\n>>";
	getline(cin, b);
	return b;
}

//���������� ������ ��� ���������
string GetString(string s)
{
	string b = "";
	while (true) {
		cout << s;
		cin >> b;
		if (getchar() != '\n') {
			cout << "\nInput only one word per line!\n";
			cout << s;
			cin.clear();
			IgnoreLine();
		}
		else if (b.empty()) {
			cout << "\nYou must enter a word!\n";
			cout << s;
			cin.clear();
			IgnoreLine();
		}
		else return b;
	}
	return b;
}

//���������� ������ y/n
char GetChar(string s)
{
	char tmp = '\n';
	cout << s;
	while (true) {
		tmp = getchar();
		if (tmp == '\n') {
			cout << "You must type y or n!\n\n";
			cout << s;
			cin.clear();
			IgnoreLine();
		}
		else if (getchar() != '\n') {
			cout << "Incorrect input! Type only y or n!\n\n";
			cout << s;
			cin.clear();
			IgnoreLine();
		}
		else return tmp;
	}
}

