#define MAX		(100)

class Queue {
	int s[MAX];
	int front;
	int rear;
	bool isFull();
	void overFlow();
	bool isEmpty();
	void emptyError();
public:
	Queue();
	void enqueue(int x);
	int dequeue();
};