#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue::Queue() {
	front = 0;
	rear = 0;
	sz = INIT_SIZE;
	s = new int[sz];

	for (int i = 0; i < sz; i++) s[i] = 0;
}

void Queue::print() {
	printf("%d %d %d\n", front, rear, sz);
	for (int i = 0; i < sz; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
	printf("\n");
}

void Queue::enqueue(int x) {
	if (isFull()) {
		int *tmp = new int[sz*2];
		int tmp_front = (front+1)%sz;
		for (int i = 0; i < sz-1; i++) {
			tmp[i] = s[tmp_front];
			tmp_front = (tmp_front+1)%sz;
		}
		for (int i = sz-1; i < sz*2; i++) {
			tmp[i] = 0;
		}
		rear = sz-1;
		sz *= 2;
		s = tmp;
		s[rear] = x;
		front = sz-1;
	}
	else {
		rear = (rear+1)%sz;
		s[rear] = x;
	}
}

bool Queue::isFull() {
	if ((rear+1)%sz == front) return true;
	return false;
}

void Queue::resize() {
	
}

int Queue::dequeue() {
	if (isEmpty()) emptyError();
	front = (front+1)%sz;
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