#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef char	BOOL;

#define TRUE		(1)
#define FALSE		(0)	

BOOL isFull(Queue *q);
void overFlow();

void print(Queue *q) {
	int i;
	printf("%d, %d\n", q->front, q->rear);
	for (i = 0; i < MAX; i++) {
		printf("%d ",q->s[i]);
	}
	printf("\n");
}

void initialize(Queue *q) {
	int i;
	q->front = 0;
	q->rear = 0;
	for (i = 0; i < MAX; i++) q->s[i] = 0;
}

void enqueue(Queue *q, int x) {
	if (isFull(q)) overFlow();
	q->rear = ((q->rear)+1)%MAX;
	q->s[q->rear] = x;
}

BOOL isFull(Queue *q) {
	if (((q->rear)+1)%MAX == q->front) return TRUE;
	return FALSE;
}

void overFlow() {
	printf("Overflow\n");
	exit(-1);
}

BOOL isEmpty(Queue *q) {
	if (q->front == q->rear) return TRUE;
	return FALSE;
}

void empty() {
	printf("Empty\n");
	exit(-1);
}

int dequeue(Queue *q) {
	if (isEmpty(q)) empty();
	q->front = ((q->front)+1)%MAX;
	return q->s[q->front];
}



