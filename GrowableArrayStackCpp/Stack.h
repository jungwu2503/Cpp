#define INIT_SIZE		(4)

class Stack {
	int *s;
	int top;
	int sz;
	void stackEmptyError();
public:
	Stack();
	void push(int x);
	int pop();
	int peek();
	void print();
};