#ifndef _STACK_H
#define _STACK_H

#include <iostream>
using namespace std;

#define INIT_SIZE		(10)

class Stack {
	static int nStack;
	int *s;
	int top;
	int sz;
	void stackEmptyError();
public:
	Stack();
	~Stack();
	void push(int x);
	//void operator+(int x);
	int pop();
	//int operator--();
	int peek();
	void print();
	static void sayHello();

	friend void pushX(Stack *p, int x);
	friend int popX(Stack *p);
	friend void operator+(Stack &s, int x);
	friend int operator--(Stack &s);
	friend ostream& operator<<(ostream& o, Stack &s);
};

#endif