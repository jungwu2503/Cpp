#define MAX		(15)

typedef struct _queue {
	int s[MAX];
	int front;
	int rear;
} Queue;

extern void initialize(Queue *p);
extern void enqueue(Queue *p, int x);
extern int dequeue(Queue *p);
extern void print(Queue *p);