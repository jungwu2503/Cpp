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

}

void Stack::print()
{
	printf("[");
	Node *tmp = top;
	while (tmp != NULL) {
		printf("%d", tmp->data);
		if (tmp->next != NULL) {
			printf(",");
		}
		tmp = tmp->next;
	}
	printf("]\n");

}

void Stack::push(int x) 
{
	Node *tmp = new Node(x);
	tmp->next = top;
	top = tmp;
}

int Stack::pop()
{
	if (top == NULL) stackEmptyError();
	int x = top->data;
	top = top->next;
	return x;
}

int Stack::peek()
{
	if (top == NULL) stackEmptyError();

	return top->data;
}

void Stack::stackEmptyError()
{
	printf("Stack Empty!!!\n");
	exit(-1);
}