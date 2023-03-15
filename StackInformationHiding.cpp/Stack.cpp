#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

// scope resolution operator ::
Stack::Stack() 
{
	top = NULL;
}

Stack::~Stack()
{
	Node *tmp = top;
	while (tmp != NULL) {
		Node *p = tmp;
		tmp = tmp->getNext();
		delete p;
	}
}

void Stack::print()
{
	printf("[");
	Node *tmp = top;
	while (tmp != NULL) {
		printf("%d", tmp->getData());
		if (tmp->getNext() != NULL) {
			printf(",");
		}
		tmp = tmp->getNext();
	}
	printf("]\n");

}

void Stack::push(int x) 
{
	Node *tmp = new Node(x);
	tmp->setNext(top);
	top = tmp;
}

int Stack::pop()
{
	if (top == NULL) stackEmptyError();
	int x = top->getData();
	Node *p = top;
	top = top->getNext();
	delete p;
	return x;
}

int Stack::peek()
{
	if (top == NULL) stackEmptyError();

	return top->getData();
}

void Stack::stackEmptyError()
{
	printf("Stack Empty!!!\n");
	exit(-1);
}