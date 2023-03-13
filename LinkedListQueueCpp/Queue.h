#include <stdio.h>
#define INIT_SIZE		(4)

class Node {
public:
	int data;
	Node *next;
	Node (int x) {
		data = x;
		next = NULL;
	}
};

class Queue {
	Node *front;
	Node *rear;
	int size;
	bool isFull();
	void resize();
	bool isEmpty();
	void emptyError();
public:
	Queue();
	~Queue();
	void enqueue(int x);
	int dequeue();
	void print();
};