#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue::Queue() {
	front = 0;
	rear = 1;

	for (int i = 0; i < MAX; i++) s[i] = 0;
}

void Queue::enqueue(int x) {
	if (isFull()) overFlow();
	rear = (rear+1)%MAX;
	s[rear] = x;
}

bool Queue::isFull() {
	if (rear+1 == front%10) return true;
	return false;
}

void Queue::overFlow() {
	printf("Overflow\n");
	exit(-1);
}

int Queue::dequeue() {
	if (isEmpty()) emptyError();
	front = (front+1)%MAX;
	return s[front+1];
}

bool Queue::isEmpty() {
	if (front-1 == rear%10) return true;
	return false;
}

void Queue::emptyError() {
	printf("Empty\n");
	exit(-1);
}