#pragma once
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class Book
{
private:
	string name;
	string authour;
	int num;
public:
	Book() :name(""), authour(""), num(0) {}
	Book(string name, string authour)
	{
		this->name = name;
		this->authour = authour;
		srand(time(0));
		this->num = rand() % 10000000000 + 10000000;
	}
	string getname()
	{
		return name;
	}
	string getauthour()
	{
		return authour;
	}
	friend ostream& operator << (ostream& out, const Book b)
	{
		out << b.authour << "|" << b.name << "|" << b.num;
		return out;
	}
	bool operator !=(Book b)
	{
		if ((this->authour != b.authour) || (this->name != b.name))
			return true;
		return false;
	}
	bool operator ==(Book b)
	{
		if ((this->authour == b.authour) && (this->name == b.name))
			return true;
		return false;
	}
};