#include <iostream>
#include <string.h>
using namespace std;
#include "LinkedList"

void main()
{
	LinkedList<Student> sList;
	LinkedList<Student> sList1;
	LinkedList<Student> sList2;
	Student a("Kim", true, 50);
	Student b("Lee", false, 70);
	Student c("Park", true, 30);

	sList.add(a);
	sList.add(b);
	sList.add(c);

	/*
	LinkedList<Student*> sList;
	sList.add(new Student("Kim", false, 30));
	sList.add(new Student("Lee", false, 90));
	sList.add(new Student("Park", false, 50));*/

	cout << sList << endl;

	LinkedList<int> list1;
	LinkedList<int> *list2 = new LinkedList<int>();

	list1.addFirst(10);
	list1.addFirst(20);
	list1.add(50);
	list1.add(60);
	list1.addAt(0, 300);

	list2->addFirst(100);
	list2->addFirst(200);

	cout << "list1 = " << list1;
	list1[2] = 20000;
	cout << "list1 = " << list1;

	int p = list1[2];
	cout << p << endl;

	int q = (*list2)[1];
	cout << q << endl;

	LinkedList<char *> ls;
	ls.add("kim");
	ls.add("lee");
	ls.add("park");
	cout << ls << endl;

}