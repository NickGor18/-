#include <iostream>
#include "Book.h"
#include "Library.h"
Сatalog* Library::add(Book b)
{
	Сatalog* p = new Сatalog();
	if (p != NULL)
	{
		p->data = b;
		p->next = NULL;
		if (head == NULL)
			head = tail = p;
		else
			tail = tail->next = p;
		++n;
	}
	return p;
}
Сatalog* Library::insert(Сatalog* pos, Book b)
{
	if (pos == NULL)
		return pos;
	Сatalog* x = head, *y = head;
	while (x != pos)
	{
		y = x;
		x = x->next;
	}
	Сatalog* p = new Сatalog();
	if (p != NULL)
	{
		p->data = b;
		if (pos == head)
		{
			p->next = head;
			head = p;
		}
		else
		{
			p->next = pos;
			y->next = p;
		}
		++n;
	}
	return pos;
}
Сatalog* Library::erase(Сatalog* pos)
{
	if (pos == NULL)
	{
		return pos;
	}
	else
		if (pos == head)
		{
			head = head->next;
			if (head == NULL)
			{
				tail = NULL;
			}
		}
		else
		{
			Сatalog* x = head, *y = head;
			while (x != pos)
			{
				y = x;
				x = x->next;
			}
			y->next = pos->next;
			if (pos == tail)
			{
				tail = y;
			}
		}
	Сatalog *p = pos->next;
	cout<<pos->data<<endl;
	delete pos;
	--n;
	return p;
}
void Library::clear()
{
	Сatalog* t;
	while (head != NULL)
	{
		t = head;
		head = head->next;
		delete t;
	}
	tail = NULL;
	n = 0;
}