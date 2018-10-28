#pragma once
#include <iostream>
#include "Book.h"
#include <cstdlib>
using namespace std;
struct Сatalog
{
	Сatalog* next;
	Book data;
};
class Library
{
private: 
	
	Сatalog *head, *tail;
	int n;
public:
	~Library(){ clear(); }
	Library() : head(NULL), tail(NULL), n(0) {}
	Сatalog* add(Book);
	Сatalog* insert(Сatalog*, Book);
	Сatalog* erase(Сatalog*);
	Сatalog* pop_head() { return erase(head); }
	Сatalog* pop_tail() { return erase(tail); }
	void clear();
	Сatalog* begin() { return head; }
	int size(){ return n; }
	bool empty() 
	{
		if (head == NULL)
			return true;
		return false;
	}
	friend ostream& operator <<(ostream&out,Library l)
	{
		Сatalog* p = l.head;
		while (p != NULL)
		{
			out << p->data << ";";
			p = p->next;
		}
		return out;
	}
};