#define INIT_SIZE		(4)

class Queue {
	int *s;
	int sz;
	int front;
	int rear;
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