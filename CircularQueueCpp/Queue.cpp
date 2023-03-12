#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue::Queue() {
	front = 0;
	rear = 0;

	for (int i = 0; i < MAX; i++) s[i] = 0;
}

void Queue::print() {
	printf("%d %d\n", front, rear);
	for (int i = 0; i < MAX; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
}

void Queue::enqueue(int x) {
	if (isFull()) overFlow();
	rear = (rear+1)%MAX;
	s[rear] = x;
}

bool Queue::isFull() {
	if (rear+1 == front%MAX) return true;
	return false;
}

void Queue::overFlow() {
	printf("Overflow\n");
	exit(-1);
}

int Queue::dequeue() {
	if (isEmpty()) emptyError();
	front = (front+1)%MAX;
	return s[front];
}

bool Queue::isEmpty() {
	if (front == rear) return true;
	return false;
}

void Queue::emptyError() {
	printf("Empty\n");
	exit(-1);
}