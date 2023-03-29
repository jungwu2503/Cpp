#include <iostream>
using namespace std;
#include "LinkedList.h"

Iterator::Iterator(LinkedList *list) {
	tmp = list->header;
	listOrg = list;
	endPtr = NULL;
}

Iterator::Iterator(LinkedList *list, Node *ptr) {
	tmp = list->header;
	listOrg = list;
	endPtr = ptr;
}

int Iterator::operator*() {
	return tmp->data;
}

void Iterator::operator++() {
	listOrg->startFlag = false;
	tmp = tmp->next;
}

void Node::insert(Node *chain)
{
	this->prev = chain->prev;
	this->next = chain;
	chain->prev->next = this;
	chain->prev = this;
}

void Node::append(Node *chain)
{
	this->prev = chain;
	this->next = chain->next;
	chain->next->prev = this;
	chain->next = this;
}

void Node::remove()
{
	//printf("node->data = %d\n", node->data);
	this->prev->next = this->next;
	this->next->prev = this->prev;
	delete this;
}

LinkedList::LinkedList()
{
	this->header = NULL;
	this->count = 0;
	this->startFlag = true;
}

LinkedList::~LinkedList() 
{
	Node *tmp;
	if (this->header == NULL) return;
	while (this->header->next != this->header) {
		tmp = this->header->next;
		tmp->remove();
	}
	this->header->remove();
}

void LinkedList::addFirst(int x)
{
	add(x);
	this->header = this->header->prev;
}

void LinkedList::add(int x) 
{
	Node *tmp;

	this->count = this->count + 1;
	if (this->header == NULL) {
		this->header = new Node(x);
		return;
	}
	tmp = new Node(x);
	tmp->insert(this->header);
}

void LinkedList::addLast(int x)
{
	add(x);
}

void LinkedList::addAt(int index, int x) 
{
	Node *tmp;
	Node *newNode;
	int i;

	if (index == 0) {
		addFirst(x);
		return;
	}
	tmp = this->header;
	this->count = this->count + 1;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	newNode = new Node(x);
	newNode->insert(tmp);
}

void LinkedList::addAllAt(LinkedList *l, int index)
{
	Node *tmp;
	Node *tmp2;
	Node *newNode;
	int listCount;
	int i;

	if (index > count-1) {
		cout << "Invalid index" << endl;
		return;
	}
	tmp = this->header;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	tmp2 = l->header;
	listCount = l->count;
	while (listCount-- > 0) {
		newNode = new Node(tmp2->data);
		newNode->insert(tmp);
		tmp2 = tmp2->next;
		this->count++;
	}
	if (index == 0) {
		for (i = 0; i < l->count; i++) {
			tmp = tmp->prev;
		}
		this->header = tmp;
	}
}

void LinkedList::print() 
{
	Node *tmp;
	
	if (this->header == NULL) {
		cout << "[]" << endl;
		return;
	}
	tmp = this->header;
	cout << "[" << tmp->data;
	while (tmp->next != this->header) {
		tmp= tmp->next;
		cout << " " << tmp->data;
	}
	cout << "]" << endl;
}

int LinkedList::size()
{
	return this->count;
}

void LinkedList::clear()
{
	Node *tmp;
	if (this->header == NULL) return;
	while (this->header->next != this->header) {
		tmp = this->header->next;
		tmp->remove();
	}
	this->header = NULL;
	this->count = 0;
}

LinkedList *LinkedList::clone()
{
	LinkedList *newList;
	Node *tmp;
	Node *newNode;
	int i;

	newList = new LinkedList();

	tmp = this->header;
	for (i = 0; i < this->count; i++) {
		newList->add(tmp->data);
		tmp = tmp->next;
	}
	newList->count = this->count;

	return newList;
}

bool LinkedList::contains(int x) 
{
	int i;
	Node *tmp;

	tmp = header;
	for (i = 0; i < count; i++) {
		if (tmp->data == x) return true;
		tmp = tmp->next;
	}

	return false;
}

int LinkedList::get(int index) 
{
	int i;
	Node *tmp;

	if (header == NULL) return -1;
	tmp = header;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	return tmp->data;
}

int LinkedList::getFirst() 
{
	if (header == NULL) return -1;
	return header->data;
}

int LinkedList::getLast() 
{
	if (header == NULL) return -1;
	return header->prev->data;
}

int LinkedList::indexOf(int x) 
{
	Node *tmp;
	int pos;
	int i;

	if (header == NULL) return -1;
	tmp = header;
	pos = 0;
	for (i = 0; i < count; i++) {
		if (tmp->data == x) return pos;
		tmp = tmp->next;
		pos++;
	}
	return -1;
}

int LinkedList::lastIndexOf(int x)
{
	Node *tmp;
	int pos;
	int i;
	int value = -1;

	if (header == NULL) return value;
	pos = 0;
	tmp = header;
	for (i = 0; i < count; i++) {
		if (tmp->data == x) value = pos;
		tmp = tmp->next;
		pos++;
	}

	return value;
}

int LinkedList::element() 
{
	if (header == NULL) return -1;
	return header->data;
}

void LinkedList::set(int index, int x) 
{
	Node *tmp;
	int i;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	tmp = header;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	tmp->data = x;
}

void LinkedList::removeData(int x)
{
	Node *tmp;
	Node *toDelete;
	int i;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	if (header->data == x) {
		if (count == 1) {
			toDelete = header;
			header = NULL;
			count = 0;
			delete toDelete;
			return;
		}
		toDelete = header;
		header = header->next;
		count = count - 1;
		toDelete->remove();
		return;
	}
	tmp = header;
	for (i = 0; i < count; i++) {
		if (tmp->data == x) {
			count = count - 1;
			toDelete = tmp;
			tmp->remove();
			return;
		}
		tmp = tmp->next;
	}

	cout << "No such element" << endl;	
}

void LinkedList::removeAt(int index)
{
	Node *tmp;
	Node *toDelete;
	int i;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	if (index > count-1) {
		cout << "Index error" << endl;
		return;
	}
	if (index == 0) {
		if (count == 1) {
			toDelete = header;
			header = NULL;
			count = 0;
			delete toDelete;
			return;
		}
		toDelete = header;
		header = header->next;
		count = count - 1;
		toDelete->remove();
		return;
	}
	tmp = header;
	count = count - 1;
	for (i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	tmp->remove();
}

int *LinkedList::toArray() // toArray 문제있을수 있음
{
	int *arr;
	Node *tmp;
	int i;

	arr = new int[count];
	tmp = header;

	for (i = 0; i < count; i++) {
		arr[i] = tmp->data;
		tmp = tmp->next;
		//cout << arr[i] << "xxxxx";
	}

	return arr;
}