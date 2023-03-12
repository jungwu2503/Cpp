#include "Queue.h"
#include <stdio.h>

void main() 
{
	/*Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	int x = q.dequeue();
	printf("%d\n", x);
	q.enqueue(40);
	q.enqueue(50);
	printf("%d\n", q.dequeue());*/

	Queue *q = new Queue();
	q->enqueue(10);
	q->enqueue(20);
	q->enqueue(30);
	int x = q->dequeue();
	printf("%d\n", x);
	q->enqueue(40);
	q->enqueue(50);
	printf("%d\n", q->dequeue());

	for (int i = 0; i < 20; i++) {
		q->enqueue(i*100+1);
		printf("%d\n", q->dequeue());
	}

	delete q;
}