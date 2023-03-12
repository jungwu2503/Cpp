#include "stack.h"

void initialize(Stack *p) {
	int i;
	p->top = -1;
	for (i = 0; i < MAX; i++) p->s[i] = 0;
}

void push(Stack *p, int x) {
	p->top = p->top + 1;
	p->s[p->top] = x;
}

int pop(Stack *p) {
	p->top = p->top - 1;
	return p->s[p->top+1];
}