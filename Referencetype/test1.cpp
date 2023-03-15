#include <stdio.h>
#include "Stack.h"

void f()
{
	Stack x;
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
	int x = s.pop();

	printf("%d\n", x);

	s.push(100);
	s.push(200);
}

void doSomething(Stack *s) {
	int x = s->pop();

	printf("%d\n", x);

	s->push(100);
	s->push(200);
}

void main() 
{
	Stack a;

	a.push(10);
	a.push(20);
	a.push(30);

//	doSomething(a);
	doSomething(&a);

	a.print();
	
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