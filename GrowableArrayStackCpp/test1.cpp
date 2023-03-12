#include <stdio.h>
#include "Stack.h"

void main() 
{
	/*Stack a;

	a.push(10);
	a.push(20);
	a.push(30);
	int x = a.pop();
	a.push(40);
	printf("%d\n", x);
	printf("%d\n", a.pop());*/

	Stack *a;
	a = new Stack();

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
	delete a;
}