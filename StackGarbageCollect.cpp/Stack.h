#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#define INIT_SIZE		(4)

class Node {
public:
	int data;
	Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class Stack {
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