#define MAX		(100)

typedef struct _stack {
	int s[MAX];
	int top;
} Stack;

extern void initialize(Stack *p);
extern void push(Stack *p, int x);
extern int pop(Stack *p);