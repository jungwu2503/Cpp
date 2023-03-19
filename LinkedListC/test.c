#include <stdio.h>
#include <malloc.h>

typedef struct _node {
	int data;
	struct _node *next;
} Node;

typedef struct _linkedList {
	Node *header;
	int count;
} LinkedList;

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
	Node *toDelete;
	int pos = 0;
	int returnValue = 0;

	if (index == 0) {
		returnValue = tmp->data;
		l->header = tmp->next;
		toDelete = tmp;
		free(toDelete);
		return returnValue;
	}
	if (index >= l->count) {
		printf("Cannot get element");
		return -1;
	}
	
	while (tmp != NULL) {
		if (pos == index-1) {
			toDelete = tmp->next;
			tmp->next = toDelete->next;
			returnValue = toDelete->data;
			free(toDelete);
			return returnValue;
		}
		pos = pos + 1;
		tmp = tmp->next;
	}

	return -1;
}

int getFirst(LinkedList *l) 
{
	Node *tmp;
	int returnValue = 0;

	if (l->header == NULL) return -1;

	tmp = l->header;
	returnValue = tmp->data;
	l->header = tmp->next;
	free(tmp);
	return returnValue;
}

int getLast(LinkedList *l) 
{
	int value;
	Node *tmp;
	Node *follow;

	if (l->header == NULL) {
		printf("Error\n");
		return -1;
	}
	if (l->count == 1) {
		value = l->header->data;
		l->header = NULL;
		l->count = l->count - 1;
		return value;
	}
	
	tmp = l->header;
	follow = l->header;
	while (tmp->next != NULL) {
		follow = tmp;
		tmp = tmp->next;
	}
	l->count = l->count-1;
	value = tmp->data;
	follow->next = NULL;
	free(tmp);

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

main()
{
	LinkedList list1;
	LinkedList list2;
	int *arr;
	int i;

	initList(&list1);
	initList(&list2);

	add(&list1, 10);
	add(&list1, 20);
	add(&list1, 30);
	add(&list1, 30);
	add(&list1, 30);
	add(&list1, 40);
	add(&list1, 50);

	add(&list2, 100);
	add(&list2, 200);
	add(&list2, 300);

	printf("list1 = ");
	print(&list1);

	printf("list2 = ");
	print(&list2);

	//printf("%d\n", get(&list1, 0));
	//printf("%d\n", element(&list1));
	//printf("%d\n", getFirst(&list1));
	//printf("%d\n", getLast(&list1));
	printf("%d\n", lastIndexOf(&list1, 30));
	
	set(&list1, 3, 700);

	//removeAt(&list1, 2);
	//removeAt(&list1, 0);
	removeData(&list1, 700);
	
	printf("list1 = ");
	print(&list1);

	arr = toArray(&list1);
	for (i = 0; i < size(&list1); i++) {
		printf("%d ", arr[i]);
	}

	/*LinkedList list1;
	LinkedList list2;
	LinkedList *copied;

	initList(&list1);
	initList(&list2);

	add(&list1, 10);
	add(&list1, 20);
	add(&list1, 30);
	add(&list1, 40);
	add(&list1, 50);

	printf("list1 = ");
	print(&list1);

	add(&list2, 100);
	add(&list2, 200);
	add(&list2, 300);

	printf("list2 = ");
	print(&list2);

	//addAllAt(&list1, &list2, 0);
	addAllAt(&list1, &list2, 2);
	//addAllAt(&list1, &list2, 10);

	printf("list1 = ");
	print(&list1);

	copied = clone(&list1);
	printf("copied = ");
	print(copied);

	printf("%s\n", contains(&list1, 300));

	printf("%d\n", get(&list1, 7));

	printf("%d\n", indexOf(&list1, 50));

	clear(&list1);
	printf("list1 = ");
	print(&list1);*/

	/*LinkedList list;
	int n;

	initList(&list);

	addAt(&list, 0, 5);

	addFirst(&list, 300);

	add(&list, 10);
	add(&list, 20);
	add(&list, 30);

	addFirst(&list, 100);
	addFirst(&list, 200);

	addLast(&list, 1000);
	addLast(&list, 2000);

	addAt(&list, 2, 1);
	addAt(&list, 0, 2);
	addAt(&list, 50, 3);
	printf("%d=====\n", size(&list));
	print(&list);
	addAt(&list, 11, 5);

	print(&list);

	n = size(&list);
	printf("%d\n", n);*/
}

/*
typedef struct _node {
	int data;
	struct _node *next;
} Node;

void print(Node *l) 
{
	Node *tmp = l;
	printf("[");
	while (tmp != NULL) {
		printf("%d", tmp->data);
		if (tmp->next != NULL) {
			printf(", ");
		}
		tmp = tmp->next;
	}
	printf("]\n");
}

void add(Node **l, int n) 
{
	Node *tmp;
	Node *newNode;
	if (*l == NULL) {
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = n;
		newNode->next = NULL;
		*l = newNode;
		return;
	}
	tmp = *l;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = n;
	newNode->next = NULL;

	tmp->next = newNode;
	return;	
}

int size(Node *l) 
{
	int sz = 0;
	Node *tmp;
	tmp = l;

	while (tmp != NULL) {
		tmp = tmp->next;
		sz++;
	}

	return sz;
}

main()
{
	Node *list = NULL;
	int n;
	n = size(list);
	printf("%d\n", n);

	add(&list, 7);
	add(&list, 10);
	add(&list, 20);
	add(&list, 30);

	
	//list = (Node *)malloc(sizeof(Node));
	//list->data = 7;
	//list->next = (Node *)malloc(sizeof(Node));
	//list->next->data = 5;
	//list->next->next = (Node *)malloc(sizeof(Node));
	//list->next->next->data = 4;
	//list->next->next->next = NULL;

	print(list);
	
	n = size(list);
	printf("%d\n", n);
} */