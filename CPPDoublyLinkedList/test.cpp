#include <iostream>
using namespace std;
#include "LinkedList.h"
#include <list>

//doubly LinkedLIst -> Singly LinkedList 단점 보완(add, traverse 역순)

void main()
{
	LinkedList list1;
	LinkedList list2;
	int i;
	
	list1.add(10);
	list1.add(20);
	list1.add(30);
	list1.addAt(1,40);
	list1.print();
	cout << list1.size() << endl;

	list2.addLast(200);
	list2.addFirst(100);
	list2.addFirst(300);
	list2.clear();
	list2.print();
	cout << list2.size() << endl;

	list1.addAllAt(&list2, 3);
	list1.print();
	cout << list1.size() << endl;

	LinkedList *list3;
	list3 = list1.clone();
	list3->print();
	cout << list3->size() << endl;

	cout << list3->indexOf(40) << endl;
	list3->add(40);
	list3->add(40);
	list3->addLast(80);
	list3->set(3, 100);
	list3->removeData(40);
	list3->removeData(40);
	list3->removeData(80);
	list3->removeAt(0);

	list3->print();
	cout << list3->size() << endl;

	/*int *arr = list3->toArray();

	for (int i = 0; i < list3->size(); i++) cout << arr[i] + " ";
	cout << endl;*/

	//cout << list3->lastIndexOf(40) << endl;	
	//cout << list3->get(2) << endl;
	//cout << list3->getLast() << endl;

	/*list1.add(10);
	list1.print();
	list1.add(20);
	list1.add(30);
	list1.add(30);
	list1.add(30);
	list1.add(40);
	list1.add(50);

	list2.add(100);
	list2.add(200);

	list2.addAllAt(&list1, 0);
	list2.clear();

	//list2 = *list1.clone();

	//cout << list1.contains(101) << endl;
	
	cout << "list1 = ";
	list1.print();

	cout << "list2 = ";
	list2.print();

	list1.addFirst(100);
	list1.addFirst(200);
	list1.addFirst(300);
	list1.addLast(400);
	list1.addLast(500);
	list1.print();

	list1.addAt(0, 7);
	list1.print();*/

	/* Iterator it = list1.begin();
	while(it != list1.end()) {
		int data = *it;
		cout << data << endl;
		it++;
	} */

	/*
	add(&list2, 100);
	add(&list2, 200);
	add(&list2, 300);

	printf("get 0 %d\n", get(&list1, 0));
	printf("getFirst %d\n", getFirst(&list1));
	printf("getLast %d\n", getLast(&list1));
	printf("list1 = ");
	print(&list1);

	printf("list2 = ");
	print(&list2);

	//printf("%d\n", get(&list1, 0));
	//printf("%d\n", element(&list1));
	//printf("%d\n", getFirst(&list1));
	//printf("%d\n", getLast(&list1));
	printf("%d\n", lastIndexOf(&list1, 30));
	
	set(&list1, 3, 700);

	//removeAt(&list1, 2);
	//removeAt(&list1, 0);
	removeData(&list1, 700);
	
	printf("list1 = ");
	print(&list1);

	arr = toArray(&list1);
	for (i = 0; i < size(&list1); i++) {
		printf("%d ", arr[i]);
	}*/
}
