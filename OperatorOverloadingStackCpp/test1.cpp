#include <stdio.h>
#include <iostream>
using namespace std;
#include "Stack.h"

void f()
{
	Stack x;
}

void operator+(Stack &s, int x)
{
	s.top++;
	s.s[s.top] = x;
}

int operator--(Stack &s)
{
	s.top--;
	return s.s[s.top+1];
}

void pushX(Stack *p, int x) {
	p->top++;
	p->s[p->top] = x;
}

int popX(Stack *p) {
	p->top--;
	return p->s[p->top+1];
}

void doSomething(Stack &s) {
	int x = --s;
	x = --s;

	printf("%d\n", x);

	s + 100;
	s + 200;
}

void doSomething(Stack *s) {
	int x = s->pop();

	printf("%d\n", x);

	s->push(100);
	s->push(200);
}

void main() 
{
	cout << "hello world\n";
	cout << 10;
	operator<<(cout,"HELLO WORLD\n");

	Stack a;

	a + 10;
	a.push(20);
	a + 30;

//	doSomething(a);
	doSomething(&a);

	cout << a;

	Stack b;
	b.push(100);

	Stack *p = new Stack();
	p->push(50);

	Stack::sayHello();
	
	/*
	Stack a;

	pushX(&a, 10);
	pushX(&a, 20);
	pushX(&a, 30);
	int x = popX(&a);
	x = popX(&a);
	pushX(&a, 40);
	printf("%d %d\n", x, popX(&a));*/

	/*Stack a;
	Stack b;
	Stack c;

	a.push(10);
	a.push(20);
	a.push(30);
	int x = a.pop();
	a.push(40);

	f();

	printf("%d\n", x);
	printf("%d\n", a.pop());*/

	/*Stack *a;
	a = new Stack();
	Stack *b = a;

	a->push(10);
	a->push(20);
	a->push(30);
	int x = a->pop();
	a->push(40);

	for (int i = 100; i < 120; i++) {
		a->push(i);
	}

	printf("%d\n", x);
	printf("%d\n", a->pop());

	a->print();
	
	delete a;*/
	//delete b;
}