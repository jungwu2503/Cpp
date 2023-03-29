#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"

Node *allocNode(int data)
{
	Node *tmp = (Node *)malloc(sizeof(Node)); 

	tmp->data = data;
	tmp->prev = tmp;
	tmp->next = tmp;

	return tmp;
}

void insert(Node *node, Node *chain)
{
	node->prev = chain->prev;
	node->next = chain;
	chain->prev->next = node;
	chain->prev = node;
}

void append(Node *node, Node *chain)
{
	node->prev = chain;
	node->next = chain->next;
	chain->next->prev = node;
	chain->next = node;
}

void removeNode(Node *node)
{
	//printf("node->data = %d\n", node->data);
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

/*main()
{
	Node *p;
	Node *q;
	Node *tmp;

	q = allocNode(7);

	tmp = q;
	printf("%d ", tmp->data);
	while (tmp->next != q) {		
		tmp = tmp->next;
		printf("%d ", tmp->data);
	}
	printf("\n");

	p = allocNode(5);
	insert(p, q);
	tmp = q;
	printf("%d ", tmp->data);
	while (tmp->next != q) {
		tmp = tmp->next;
		printf("%d ", tmp->data);
	}
	printf("\n");

	p = allocNode(9);
	insert(p, q);
	tmp = q;
	printf("%d ", tmp->data);
	while (tmp->next != q) {
		tmp = tmp->next;
		printf("%d ", tmp->data);
	}
	printf("\n");

	p = allocNode(8);
	insert(p, q);
	tmp = q;
	printf("%d ", tmp->data);
	while (tmp->next != q) {
		tmp = tmp->next;
		printf("%d ", tmp->data);
	}
	printf("\n");
}*/

void initList(LinkedList *l) 
{
	l->header = NULL;
	l->count = 0;
}

void disposeList(LinkedList *l) 
{
	Node *tmp;
	if (l->header == NULL) return;
	while (l->header->next != l->header) {
		tmp = l->header->next;
		removeNode(tmp);
	}
	removeNode(l->header);
}

void addFirst(LinkedList *l, int x)
{
	add(l, x);
	l->header = l->header->prev;

}

void add(LinkedList *l, int x) 
{
	Node *tmp;

	l->count = l->count + 1;
	if (l->header == NULL) {
		l->header = allocNode(x);
		return;
	}
	tmp = allocNode(x);
	insert(tmp, l->header);
}

void addLast(LinkedList *l, int x)
{
	add(l, x);
}

void addAt(LinkedList *l, int index, int x) 
{
	Node *tmp;
	Node *newNode;
	int i;

	if (index == 0) {
		addFirst(l, x);
		return;
	}
	tmp = l->header;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	newNode = allocNode(x);
	insert(newNode, tmp);
}

void addAllAt(LinkedList *l1, LinkedList *l2, int index)
{
	Node *tmp;
	Node *tmp2;
	Node *newNode;
	int l2Count;
	int i;

	tmp = l1->header;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	tmp2 = l2->header;
	l2Count = l2->count;
	while (l2Count-- > 0) {
		newNode = allocNode(tmp2->data);
		insert(newNode, tmp);
		tmp2 = tmp2->next;
		l1->count++;
	}
	if (index == 0) {
		for (i = 0; i < l2->count; i++) {
			tmp = tmp->prev;
		}
		l1->header = tmp;
	}
}

void print(LinkedList *l) 
{
	Node *tmp;
	
	if (l->header == NULL) {
		printf("[]\n");
		return;
	}
	tmp = l->header;
	printf("[%d", tmp->data);
	while (tmp->next != l->header) {
		tmp= tmp->next;
		printf(" %d", tmp->data);
	}
	printf("]\n");
}

int size(LinkedList *l)
{
	return l->count;
}

void clear(LinkedList *l)
{
	Node *tmp;
	if (l->header == NULL) return;
	while (l->header->next != l->header) {
		tmp = l->header->next;
		removeNode(tmp);
	}
	l->header = NULL;
	l->count = 0;
}

LinkedList *clone(LinkedList *org)
{
	LinkedList *newList;
	Node *tmp;
	Node *newNode;
	int i;

	newList = (LinkedList *)malloc(sizeof(LinkedList));
	initList(newList);

	tmp = org->header;
	for (i = 0; i < org->count; i++) {
		add(newList, tmp->data);
		tmp = tmp->next;
	}
	newList->count = org->count;

	return newList;
}

char contains(LinkedList *l, int x) 
{
	int i;
	Node *tmp;

	tmp = l->header;
	for (i = 0; i < l->count; i++) {
		if (tmp->data == x) return TRUE;
		tmp = tmp->next;
	}

	return FALSE;
}

int get(LinkedList *l, int index) 
{
	int i;
	Node *tmp;

	if (l->header == NULL) return -1;
	tmp = l->header;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	return tmp->data;
}

int getFirst(LinkedList *l) 
{
	if (l->header == NULL) return -1;
	return l->header->data;
}

int getLast(LinkedList *l) 
{
	if (l->header == NULL) return -1;
	return l->header->prev->data;
}

int indexOf(LinkedList *l, int x) 
{
	Node *tmp;
	int pos;
	int i;

	if (l->header == NULL) return -1;
	tmp = l->header;
	pos = 0;
	for (i = 0; i < l->count; i++) {
		if (tmp->data == x) return pos;
		tmp = tmp->next;
		pos++;
	}
	return -1;
}

int lastIndexOf(LinkedList *l, int x)
{
	Node *tmp;
	int pos;
	int i;
	int value = -1;

	if (l->header == NULL) return value;
	pos = 0;
	tmp = l->header;
	for (i = 0; i < l->count; i++) {
		if (tmp->data == x) value = pos;
		tmp = tmp->next;
		pos++;
	}

	return value;
}

int element(LinkedList *l) 
{
	if (l->header == NULL) return -1;
	return l->header->data;
}

void set(LinkedList *l, int index, int x) 
{
	Node *tmp;
	int i;

	if (l->header == NULL) {
		printf("List is empty\n");	
		return;
	}
	tmp = l->header;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	tmp->data = x;
}

void removeData(LinkedList *l, int x)
{
	Node *tmp;
	Node *toDelete;
	int i;

	if (l->header == NULL) {
		printf("List is empty\n");	
		return;
	}
	if (l->header->data == x) {
		if (l->count == 1) {
			toDelete = l->header;
			l->header = NULL;
			l->count = 0;
			free(toDelete);
			return;
		}
		toDelete = l->header;
		l->header = l->header->next;
		l->count = l->count - 1;
		removeNode(toDelete);
		free(toDelete);
		return;
	}
	tmp = l->header;
	for (i = 0; i < l->count; i++) {
		if (tmp->data == x) {
			l->count = l->count - 1;
			toDelete = tmp;
			removeNode(tmp);
			free(toDelete);
			return;
		}
		tmp = tmp->next;
	}

	printf("No such element\n");	
}

void removeAt(LinkedList *l, int index)
{
	Node *tmp;
	Node *toDelete;
	int i;

	if (l->header == NULL) {
		printf("List is empty\n");	
		return;
	}
	if (index > l->count-1) {
		printf("Index error\n");	
		return;
	}
	if (index == 0) {
		if (l->count == 1) {
			toDelete = l->header;
			l->header = NULL;
			l->count = 0;
			free(toDelete);
			return;
		}
		toDelete = l->header;
		l->header = l->header->next;
		l->count = l->count - 1;
		removeNode(toDelete);
		free(toDelete);
		return;
	}
	tmp = l->header;
	l->count = l->count - 1;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	removeNode(tmp);
	free(tmp);
}

int *toArray(LinkedList *l)
{
	int *arr;
	Node *tmp;
	int i;

	if (l->count == 0) return NULL;
	arr = (int *)malloc(sizeof(int) * size(l));
	tmp = l->header;

	for (i = 0; i < l->count; i++) {
		arr[i] = tmp->data;
		tmp = tmp->next;
	}

	return arr;
}