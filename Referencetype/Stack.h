#define INIT_SIZE		(10)

class Stack {
	int *s;
	int top;
	int sz;
	void stackEmptyError();
public:
	Stack();
	~Stack();
	void push(int x);
	int pop();
	int peek();
	void print();

	friend static void pushX(Stack *p, int x);
	friend static int popX(Stack *p);
};