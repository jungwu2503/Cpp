#define MAX		(100)

class Stack {
	int s[MAX];
	int top;
	void stackEmptyError();
public:
	Stack();
	void push(int x);
	int pop();
	int peek();
};