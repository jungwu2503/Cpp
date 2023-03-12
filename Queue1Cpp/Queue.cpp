#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue::Queue() {
	front = -1;
	rear = -1;

	for (int i = 0; i < MAX; i++) s[i] = 0;
}

void Queue::enqueue(int x) {
	if (isFull()) overFlow();
	rear++;
	s[rear] = x;
	/*
	rear++;
	if (front == rear) {
		printf("Overflow\n");
		exit(-1);
	}
	s[rear] = x;
	*/
}

bool Queue::isFull() {
	if (rear == MAX-1) return true;
	return false;
}

void Queue::overFlow() {
	printf("Overflow\n");
	exit(-1);
}

int Queue::dequeue() {
	if (isEmpty()) emptyError();
	/*
	if (front == rear) {
		printf("Underflow\n");
		exit(-1);
	}
	*/
	front++;
	return s[front];
}

bool Queue::isEmpty() {
	if (front == rear) return true;
	return false;
}

void Queue::emptyError() {
	printf("Underflow\n");
	exit(-1);
}