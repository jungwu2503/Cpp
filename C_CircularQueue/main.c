#include <stdio.h>
#include "queue.h"

extern void print(Queue *q);
main() 
{
	Queue q;
	int i;
	
	initialize(&q);
	print(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	printf("%d\n", dequeue(&q));
	for (i = 1; i < 200; i++) {
		enqueue(&q, i);
		printf("%d\n", dequeue(&q));
	}
	print(&q);
}