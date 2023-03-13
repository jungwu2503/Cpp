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
	q->print();
	q->enqueue(10);
	q->print();
	q->enqueue(20);
	q->print();
	q->enqueue(30);
	q->print();
	int x = q->dequeue();
	q->print();
	printf("%d\n", x);
	q->print();
	q->enqueue(40);
	q->print();
	q->enqueue(50);
	q->print();
	printf("%d\n", q->dequeue());
	q->print();

	for (int i = 1; i < 20; i++) {
		q->enqueue(i);
		//printf("%d\n", q->dequeue());
	}

	q->print();
	delete q;

	/*Queue q;

	q.print();
	q.enqueue(10);
	q.print();
	q.enqueue(20);
	q.print();
	q.enqueue(30);
	q.print();
	q.enqueue(40);
	q.print();
	printf("%d\n", q.dequeue());
	printf("%d\n", q.dequeue());
	q.print();*/
}