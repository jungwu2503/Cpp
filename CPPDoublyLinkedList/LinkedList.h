#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <malloc.h>

#define TRUE	(1)
#define FALSE	(0)

class LinkedList;
class Node;

class Iterator {
	Node *tmp;
	Node *endPtr;
	LinkedList *listOrg;
public:
	Iterator(LinkedList *list);
	Iterator(LinkedList *list, Node *ptr);
	int operator*();
	void operator++();
	bool operator!=(Iterator &it) {
		return tmp != it.endPtr;
	}
	bool operator==(Iterator &it) {
		return tmp == it.endPtr;
	}
	friend LinkedList;
};

class Node {
	Node *prev;
	int data;
	Node *next;
	Node() {
		prev = next = this;
		data = 0;
	}
	Node(int d) {
		prev = next = this;
		data = d;
	}
	void insert(Node *chain);
	void append(Node *chain);
	void remove();
	friend LinkedList;
	friend Iterator;
};

class LinkedList {
	bool startFlag;
	Node *header;
	int count;
public:
	LinkedList();
	~LinkedList();
	Iterator begin() {
		startFlag = true;
		return Iterator(this);
	}
	Iterator end() {
		if (startFlag == true) return Iterator(this, NULL);
		return Iterator(this, header);
	}
	void addFirst(int x);
	void add(int x);
	void addLast(int x);
	void addAt(int index, int x);
	void addAllAt(LinkedList *l2, int index);
	void print();
	int size();
	void clear();
	LinkedList *clone();
	bool contains(int x);
	int get(int index);
	int getFirst();
	int getLast();
	int indexOf(int x);
	int lastIndexOf(int x);
	int element();
	void set(int index, int x);
	void removeData(int x);
	void removeAt(int index);
	int *toArray();
	friend Iterator;
};



#endif 