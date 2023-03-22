#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"

void initList(LinkedList *l) 
{
	l->header = NULL;
	l->count = 0;
}

void addFirst(LinkedList *l, int x)
{
	Node *newNode;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = l->header;

	l->header = newNode;
	l->count = l->count + 1;

	return;
}

void add(LinkedList *l, int x) 
{
	Node *newNode;
	Node *tmp;

	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;

	if (l->count == 0) {
		l->header = newNode;
		l->count = l->count + 1;
		return;
	}

	tmp = l->header;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newNode;
	l->count = l->count + 1;
	return;
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
	if (index > l->count) {
		printf("Index out of bounds\n");
		return;
	}
	
	tmp = l->header;
	for (i = 1; i <= index-1; i++) {
		tmp = tmp->next;
	}
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = tmp->next;
	tmp->next = newNode;
	l->count = l->count + 1;

	return;
}

void addAllAt(LinkedList *l1, LinkedList *l2, int index)
{
	int pos;
	Node *tmp;

	if (index > l1->count) {
		printf("Index out of bounds\n");
		return;
	}
	tmp = l2->header;
	pos = index;
		while (tmp != NULL) {
			addAt(l1, pos, tmp->data);
			pos = pos + 1;
			tmp = tmp->next;
		}
	return;
}

void print(LinkedList *l) 
{
	Node *p = l->header;

	printf("[");
	while (p != NULL) {
		printf("%d", p->data);
		if (p->next != NULL) {
			printf(", ");
		}
		p = p->next;
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
	Node *toDelete;

	tmp = l->header;

	while (tmp != NULL) {
		toDelete = tmp;
		tmp = tmp->next;
		free(toDelete);
	}

	l->header = NULL;
	l->count = 0;
}

LinkedList *clone(LinkedList *org)
{
	LinkedList *tmp;
	Node *p;
	if (org == NULL) return NULL;

	tmp = (LinkedList *)malloc(sizeof(LinkedList));
	tmp->header = NULL;
	tmp->count = 0;

	p = org->header;
	while (p != NULL) {
		add(tmp, p->data);
		p = p->next;
	}

	return tmp;
}

char* contains(LinkedList *l, int x) 
{
	Node *tmp;
	tmp = l->header;
	
	while (tmp != NULL) {
		if (tmp->data == x) {
			return "TRUE";
		}
		tmp = tmp->next;
	}

	return "FALSE";
}

int get(LinkedList *l, int index) 
{
	Node *tmp = l->header;
	int returnValue = 0;
	int i;

	if (index == 0) {
		returnValue = tmp->data;
		return returnValue;
	}
	if (index >= l->count) {
		printf("Cannot get element");
		return -1;
	}
	
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	returnValue = tmp->data;
	return returnValue;
}

int getFirst(LinkedList *l) 
{
	Node *tmp;

	if (l->header == NULL) return -1;

	return l->header->data;
}

int getLast(LinkedList *l) 
{
	int value;
	Node *tmp;

	if (l->header == NULL) {
		printf("Error\n");
		return -1;
	}
	
	tmp = l->header;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	value = tmp->data;
	
	return value;
}

int indexOf(LinkedList *l, int x) 
{
	Node *tmp;
	int pos = 0;

	if (l->header == NULL) {
		printf("Error\n");
		return -1;
	}
	tmp = l->header;
	while (tmp != NULL) {
		if (tmp->data == x) return pos;
		pos = pos + 1;
		tmp = tmp->next;
	}
	printf("Cannot find element");
	return -1;
}

int lastIndexOf(LinkedList *l, int x)
{
	Node *tmp;
	int pos = 0;
	int value = -1;

	if (l->header == NULL) {
		printf("Error\n");
		return value;
	}
	tmp = l->header;
	while (tmp != NULL) {
		if (tmp->data == x) value = pos;
		tmp = tmp->next;
		pos = pos + 1;
	}

	if (value == -1) printf("Cannot find element");

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
	int pos = 0;

	if (l->header == NULL) {
		printf("Error\n");
		return;
	}
	if (index >= l->count) {
		printf("Error\n");
		return;
	}

	tmp = l->header;
	while (tmp != NULL) {
		if (pos == index) {
			tmp->data = x;
			return;
		}

		tmp = tmp->next;
		pos = pos + 1;
	}
}

void removeData(LinkedList *l, int x)
{
	Node *tmp;
	Node *follow;

	if (l->header == NULL) {
		printf("Error\n");
		return;
	}
	if (l->count == 1 && l->header->data == x) {
		l->header = NULL;
		l->count = l->count - 1;
		return;
	}
	tmp = l->header;
	follow = l->header;
	while (tmp != NULL) {
		if (tmp->data == x) {
			if (tmp == l->header) {
				l->header = tmp->next;
				l->count = l->count-1;
				return;
			}
			follow->next = tmp->next;
			free(tmp);
			l->count = l->count-1;
			return;
		}
		follow = tmp;
		tmp = tmp->next;
	}
	printf("Cannot find element");
}

void removeAt(LinkedList *l, int index)
{
	Node *tmp;
	Node *follow;
	int pos = 0;

	if (index == 0) {
		tmp = l->header;
		l->header = l->header->next;
		free(tmp);
		l->count = l->count-1;
		return;
	}
	if (index >= l->count) {
		printf("Cannot get element");
		return;
	}
	tmp = l->header;
	follow = l->header;
	for (pos = 0; pos < index; pos++) {
		follow = tmp;
		tmp = tmp->next;
	}
	follow->next = tmp->next;
	l->count = l->count-1;
	free(tmp);
	/*
	while (tmp != NULL) {
		if (pos == index-1) {
			follow->next = tmp->next;
			l->count = l->count-1;
			free(tmp);
			return;
		}
		pos = pos + 1;
		tmp = tmp->next;
	}*/
}

int *toArray(LinkedList *l)
{
	int *p;
	Node *tmp;
	int i;

	if (l->count == 0) return NULL;
	p = (int *)malloc(sizeof(int) * size(l));
	tmp = l->header;
	i = 0;
	while (tmp != NULL) {
		p[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return p;
}