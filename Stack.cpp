#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

// scope resolution operator ::
Stack::Stack() 
{
	top = -1;

	for (int i = 0; i < MAX; i++) s[i] = 0;
}

void Stack::push(int x) 
{
	if (top >= MAX-1) {
		printf("Overflow!!!\n");
		exit(-1);
	}
	top++;
	s[top] = x;
}

int Stack::pop()
{
	if (top == -1) stackEmptyError();

	top--;
	return s[top+1];
}

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