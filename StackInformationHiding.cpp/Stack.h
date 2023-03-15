#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#define INIT_SIZE		(4)

class Stack {
	class Node {
		int data;
		Node *next;
	public:
		Node(int x) {
			data = x;
			next = NULL;
		}
		inline Node *getNext() { return next; }
		inline int getData() { return data; };
		inline void setNext(Node *p) { next = p; }
	};
	Node *top;
	void stackEmptyError();
public:
	Stack();
	~Stack();
	void push(int x);
	int pop();
	int peek();
	void print();
};

#endif