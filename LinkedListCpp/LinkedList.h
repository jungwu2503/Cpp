#pragma once
#include <iostream>
using namespace std;

class LinkedList;

class Node 
{
	int data;
	Node *next;
public:
	Node(int x) {
		data = x;
		next = NULL;
	}
	friend LinkedList;
	friend ostream& operator<<(ostream& out, LinkedList &l);
};

class LinkedList
{
	Node *header;
	int count;
public:
	LinkedList();
	~LinkedList();
	void addFirst(int x);
	void add(int x);
	void addLast(int x);
	void addAt(int index, int x);
	void addAllAt(LinkedList *list2, int index);
	void clear();
	bool contains(int x);
	LinkedList* clone();
	int element();
	int get(int index);
	int getFirst();
	int getLast();
	int indexOf(int x);
	int lastIndexOf(int x);
	void offer(int x);
	void offerFirst(int x);
	void offerLast(int x);
	int peek();
	int peekFirst();
	int peekLast();
	int poll();
	int pollFirst();
	int pollLast();
	int remove();
	int removeAt(int index);
	int remove(int x);
	int removeFirst();
	int removeLast();
	void set(int index, int x);
	int* toArray();
	inline int size() { return count; }
	friend ostream& operator<<(ostream& out, LinkedList &l);
};

