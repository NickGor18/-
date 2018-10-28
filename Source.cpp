#include <iostream>
#include <assert.h>
#include "Book.h"
#include "Library.h"
#include <string>
using namespace std;
int main()
{
	Library l;
	int i = 0;
	try
	{
		while (i != 9)
		{
			cout << "Menu" << endl;
			cout << "1. Add book" << endl;
			cout << "2. Insert book" << endl;
			cout << "3. Take book" << endl;
			cout << "4. Pop from head" << endl;
			cout << "5. Pop from tail" << endl;
			cout << "6. Print library" << endl;
			cout << "7. Clear library" << endl;
			cout << "8. Size of library" << endl;
			cout << "9. Stop working with library" << endl;
			cin >> i;
			switch(i)
			{
			case 1:
			{
				string str1, str2;
				cout << "Enter author name: ";
				cin >> str1;
				cout << "Enter book name: ";
				cin >> str2;
				Book b(str1, str2);
				l.add(b);
				break;
			}
			case 2:
			{
				string str1, str2;
				cout << "Enter author name: ";
				cin >> str1;
				cout << "Enter book name: ";
				cin >> str2;
				Book b(str1, str2);
				Сatalog *p = l.begin();
				cout << "Book after which you want enter new book: "<<endl;
				cout << "Enter author name: ";
				cin >> str1;
				cout << "Enter book name: ";
				cin >> str2;
				Book b1(str1, str2);
				while (p!=NULL)
				{
					if ((p->data.getauthour() == b1.getauthour())&&(p->data.getname() == b1.getname()))
					{
						p = l.insert(p, b);
						assert(p != NULL);
					}
					p = p->next;
				}
				break;
			}
			case 3:
			{
				string str1, str2;
				cout << "Book which you want to take: "<<endl;
				cout << "Enter author name: ";
				cin >> str1;
				cout << "Enter book name: ";
				cin >> str2;
				Book b(str1, str2);
				Сatalog *p = l.begin();
				while(p!=NULL)
				{
					if ((p->data.getauthour() == b.getauthour())&&(p->data.getname() == b.getname()))
					{
						l.erase(p);
						break;
					}
					else
					p=p->next;
				}
				break;
			}
			case 4:
			{
				l.pop_head();
				break;
			}
			case 5:
			{
				l.pop_tail();
				break;
			}
			case 6:
			{
				if(l.size()==0)
				{
					cout<<"Library is empty!"<<endl;
					break;
				}
				cout<<"Library: ";
				cout<<l<<endl;
				break;
			}
			case 7:
			{
				l.clear();
				cout<<"Library is cleared!"<<endl;
				break;
			}
			case 8:
			{
				cout<<"Size of library: "<<l.size()<<endl;
				break;
			}
			case 9:
			{
				break;
			}
			}
		}
	}
	catch(...)
	{ 
		cout << "Critical mistake!" << endl;
	}
	return 0;
}