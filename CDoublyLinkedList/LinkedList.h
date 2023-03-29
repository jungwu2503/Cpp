#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <malloc.h>

#define TRUE	(1)
#define FALSE	(0)

typedef struct _node {
	struct _node *prev;
	int data;
	struct _node *next;
} Node;

typedef struct _linkedList {
	Node *header;
	int count;
} LinkedList;

extern void initList(LinkedList *l);
extern void disposeList(LinkedList *l);
extern void addFirst(LinkedList *l, int x);
extern void add(LinkedList *l, int x);
extern void addLast(LinkedList *l, int x);
extern void addAt(LinkedList *l, int index, int x);
extern void addAllAt(LinkedList *l1, LinkedList *l2, int index);
extern void print(LinkedList *l);
extern int size(LinkedList *l);
extern void clear(LinkedList *l);
extern LinkedList *clone(LinkedList *org);
extern char contains(LinkedList *l, int x);
extern int get(LinkedList *l, int index);
extern int getFirst(LinkedList *l);
extern int getLast(LinkedList *l);
extern int indexOf(LinkedList *l, int x);
extern int lastIndexOf(LinkedList *l, int x);
extern int element(LinkedList *l);
extern void set(LinkedList *l, int index, int x);
extern void removeData(LinkedList *l, int x);
extern void removeAt(LinkedList *l, int index);
extern int *toArray(LinkedList *l);

#endif 