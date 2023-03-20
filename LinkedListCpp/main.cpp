#include <iostream>
using namespace std;
#include "LinkedList.h"

void main()
{
	LinkedList list1;
	LinkedList *list2 = new LinkedList();

	list1.addFirst(10);
	list1.addFirst(20);
	list1.add(50);
	list1.add(60);
	list1.addAt(0, 300);
	
	list2->addFirst(100);
	list2->addFirst(200);

	list1.addAllAt(list2, 3);

	//list1.clear();
	//list1 = *list2->clone();

	//cout << list1.contains(300) << endl; //��½� 1,0

	//cout << "list2�� First element : " << list2->element() << endl;
	
	//cout << "list1 0��° index element get�� ��� : " << list1.get(0) << endl;
	//cout << "list1 getFirst�� ��� : " << list1.getFirst() << endl;
	//cout << "list1 getLast�� ��� : " << list1.getLast() << endl;

	//cout << "list1�� indexOf(200) �� ��� : " << list1.indexOf(999) << endl;
	list1.add(20);
	list1.add(20);
	list1.add(30);
	//list1.offer(3000);
	//list1.offerFirst(1000);
	//list1.offerLast(5000);

	//cout << "list1�� peek() �� : " << list1.peek() << endl;
	//cout << "list1�� peekFirst() �� : " << list1.peekFirst() << endl;
	//cout << "list1�� peekLast() �� : " << list1.peekLast() << endl;

	//cout << "list1�� poll() �� : " << list1.poll() << endl;
	//cout << "list1�� pollFirst() �� : " << list1.pollFirst() << endl;
	//cout << "list1�� pollLast() �� : " << list1.pollLast() << endl;

	//cout << "list1�� lastIndexOf(20) �� ��� : " << list1.lastIndexOf(20) << endl;

	//cout << "list2�� remove() �� ��� �� : " << list2->remove() << endl;
	//cout << "list2�� remove() �� ��� �� : " << list2->remove() << endl;
	//cout << "list2�� remove() �� ��� �� : " << list2->remove() << endl;

	//cout << "list2�� removeAt(1) �� ��� �� : " << list2->removeAt(1) << endl;
	//cout << "list1�� remove(20) �� ��� �� : " << list1.remove(20) << endl;

	//cout << "list1�� removeFirst() �� ��� �� : " << list1.removeFirst() << endl;
	//cout << "list2�� removeFirst() �� ��� �� : " << list2->removeFirst() << endl;
	//cout << "list2�� removeLast() �� ��� �� : " << list2->removeLast() << endl;

	//list1.set(0, 123);

	cout << "Size of list1 = " << list1.size() << endl;
	cout << "Size of list2 = " << list2->size() << endl;

	cout << "list1 = " << list1;
	cout << "list2 = " << *list2;

	int* arr = list1.toArray();
	cout << "list1.toArray() = [ ";
	for (int i = 0; i < list1.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "]";
}