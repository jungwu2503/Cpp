#include <stdio.h>
#include <malloc.h>
#include "stack.h"

main()
{
	/*Stack a;
	Stack b;
	int x;

	initialize(&a);
	push(&a, 10);
	push(&a, 20);
	push(&a, 30);

	x = pop(&a);

	push(&a, 40);

	printf("%d, %d\n", x, pop(&a));*/

	Stack *a;
	Stack b;
	int x;
	a = (Stack *)malloc(sizeof(Stack));

	initialize(a);
	push(a, 10);
	push(a, 20);
	push(a, 30);

	x = pop(a);

	push(a, 40);

	printf("%d, %d\n", x, pop(a));

	free(a);
}