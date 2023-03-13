#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue::Queue() {
	front = NULL;
	rear = NULL;
	size = 0;
}

Queue::~Queue() {

}

void Queue::print() {
	printf("[");
	Node *tmp = front;
	while (tmp != NULL) {
		printf("%d", tmp->data);
		if (tmp->next != NULL) {
			printf(", ");
		}
		tmp = tmp->next;
	}
	printf("]\n");
}

void Queue::enqueue(int x) {
	Node *tmp = new Node(x);
	if (isEmpty()) {
		front = tmp;
		rear = tmp;
		size = size + 1;
	} else {
		size++;
		rear->next = tmp;
		rear = tmp;
	}
}

int Queue::dequeue() {
	if (isEmpty()) {
		emptyError();
	} else if (size == 1) {
		int value = front->data;
		front = NULL;
		rear = NULL;
		size = 0;
		return value;
	} else {
		int value = front->data;
		front = front->next;
		return value;
	}
}

bool Queue::isEmpty() {
	if (size == 0) return true;
	return false;
}

void Queue::emptyError() {
	printf("Empty\n");
	exit(-1);
}