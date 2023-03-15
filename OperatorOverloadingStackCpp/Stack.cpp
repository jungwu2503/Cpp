#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int Stack::nStack = 0;

ostream& operator<<(ostream& o, Stack &s)
{
	o << "top = " << s.top << endl;
	for (int i = 0; i < s.sz; i++) {
		o << s.s[i] << " ";
	}
	o << endl;

	return o;
}

void Stack::sayHello() 
{
	cout << "n = " << nStack;
}

// scope resolution operator ::
Stack::Stack() 
{
	nStack++;

	top = -1;
	sz = INIT_SIZE;

	s = new int[sz];

	for (int i = 0; i < sz; i++) s[i] = 0;
}

Stack::~Stack()
{
	//printf("Hello\n");
	if (s) delete []s;
}

void Stack::print()
{
	printf("top = %d\n", top);
	for (int i = 0; i < sz; i++) {
		printf("%d ", s[i]); 
	}
	printf("\n");
}

void Stack::push(int x) 
{
	if (top >= sz-1) {
		int *tmp = new int[sz*2];
		for (int i = 0; i < sz; i++) {
			tmp[i] = s[i];
		}
		for (int i = sz; i < 2*sz; i++) tmp[i] = 0;
		delete []s;
		s = tmp;
		sz *= 2;
	}
	top++;
	s[top] = x;
}

/*void Stack::operator+(int x) 
{
	if (top >= sz-1) {
		int *tmp = new int[sz*2];
		for (int i = 0; i < sz; i++) {
			tmp[i] = s[i];
		}
		for (int i = sz; i < 2*sz; i++) tmp[i] = 0;
		delete []s;
		s = tmp;
		sz *= 2;
	}
	top++;
	s[top] = x;
}*/

int Stack::pop()
{
	if (top == -1) stackEmptyError();

	top--;
	return s[top+1];
}

/*int Stack::operator--() 
{
	if (top == -1) stackEmptyError();

	top--;
	return s[top+1];
}*/

int Stack::peek()
{
	if (top == -1) stackEmptyError();

	return s[top];
}

void Stack::stackEmptyError()
{
	printf("Stack Empty!!!\n");
	exit(-1);
}

