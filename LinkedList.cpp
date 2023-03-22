#include "LinkedList.h"

ostream& operator<<(ostream& out, LinkedList &l)
{
	Node *tmp = l.header;
	out << "[";
	while (tmp != NULL) {
		out << tmp->data;
		if (tmp->next != NULL) out << ", ";
		tmp = tmp->next;
	}
	out << "]" << endl;
	return out;
}

LinkedList::LinkedList()
{
	header = NULL;
	count = 0;
}


LinkedList::~LinkedList()
{
}

void LinkedList::addFirst(int x)
{
	Node *newNode = new Node(x);

	count++;
	newNode->next = header;
	header = newNode;
}

void LinkedList::add(int x)
{
	Node *newNode = new Node(x);
	Node *tmp;

	if (count == 0) {
		header = newNode;
		count++;
		return;
	}

	tmp = header;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = newNode;
	count++;
	return;
}

void LinkedList::addLast(int x)
{
	add(x);
}

void LinkedList::addAt(int index, int x) 
{
	Node *newNode = new Node(x);
	Node *tmp;

	if (index == 0) {
		addFirst(x);
		return;
	}
	if (index > count) {
		cout << "Index가 List 사이즈를 벗어났습니다" << endl;
		return;
	}
	tmp = header;
	for (int i = 0; i < index-1; i++) {
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
	count++;
	return;
}

void LinkedList::addAllAt(LinkedList *list2, int index)
{
	Node *tmp;
	int pos;

	if (index > count) {
		cout << "Index가 List 사이즈를 벗어났습니다" << endl;
		return;
	}

	tmp = list2->header;
	pos = index;
	while (tmp != NULL) {
		addAt(pos++, tmp->data);
		tmp = tmp->next;
	}

	return;
}

void LinkedList::clear() 
{
	Node *tmp;
	Node *follow;
	
	tmp = header;
	follow = header;
	while (tmp != NULL) {
		follow = tmp;
		tmp = tmp->next;
		delete follow;
	}
	count = 0;
	header = NULL;
}

LinkedList* LinkedList::clone()
{
	LinkedList *copied;
	Node *tmp;

	if (count == 0) return NULL;

	copied = new LinkedList();

	tmp = header;
	while (tmp != NULL) {
		copied->add(tmp->data);
		tmp = tmp->next;
	}

	copied->count = count;
	return copied;
}

bool LinkedList::contains(int x)
{
	Node *tmp;

	tmp = header;
	while (tmp != NULL) {
		if (tmp->data == x) return true;
		tmp = tmp->next;
	}
	return false;
}

int LinkedList::element()
{
	if (header == NULL) {
		cout << "List is empty" << endl;
	}
	return header->data;
}

int LinkedList::get(int index)
{
	Node *tmp;
	int value;

	tmp = header;
	if (count == 0) {
		cout << "List is empty" << endl;
		return -1;
	}
	if (index == 0) {
		value = tmp->data;
		return value;
	}
	if (index > count-1) {
		cout << "Cannot get element" << endl;
		return -1;
	}

	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	value = tmp->data;
	return value;
}

int& LinkedList::operator[](int index)
{
	Node *tmp;
	int value;

	tmp = header;
	if (count == 0) {
		cout << "List is empty" << endl;
		exit(-1);
	}
	if (index == 0) {
		value = tmp->data;
		return tmp->data;
	}
	if (index > count-1) {
		cout << "Cannot get element" << endl;
		exit(-1);
	}

	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	return tmp->data;
}

int LinkedList::getFirst()
{
	Node *tmp;
	int value;

	if (count == 0) {
		cout << "List is empty" << endl;
		return -1;
	}
	tmp = header;
	value = tmp->data;
	return value;
}

int LinkedList::getLast()
{
	Node *tmp;
	int value;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return -1;
	}
	tmp = header;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	value = tmp->data;
	return value;
}

int LinkedList::indexOf(int x) 
{
	Node *tmp;
	int pos = 0;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return -1;
	}
	tmp = header;
	while (tmp != NULL) {
		if (tmp->data == x) {
			return pos;
		}
		pos++;
		tmp = tmp->next;
	}

	cout << "No such element" << endl;
	return -1;
}

int LinkedList::lastIndexOf(int x) 
{
	Node *tmp;
	int pos;
	int value = -1;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return value;
	}
	tmp = header;
	pos = 0;
	while (tmp != NULL) {
		if (tmp->data == x) value = pos;
		tmp = tmp->next;
		pos++;
	}
	if (value == -1) cout << "No such element" << endl;
	
	return value;
}

void LinkedList::offer(int x) 
{
	add(x);
}

void LinkedList::offerFirst(int x) 
{
	addFirst(x);
}

void LinkedList::offerLast(int x) 
{
	addLast(x);
}

int LinkedList::peek() 
{
	if (header == NULL) {
		cout << "List is empty" << endl;
		return -1;
	}
	return header->data;
}

int LinkedList::peekFirst()
{
	return peek();
}

int LinkedList::peekLast()
{
	Node *tmp;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return -1;
	}
	tmp = header;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	return tmp->data;
}

int LinkedList::poll()
{
	return getFirst();
}

int LinkedList::pollFirst()
{
	return getFirst();
}
	
int LinkedList::pollLast()
{
	return getLast();
}

int LinkedList::remove() 
{
	Node *tmp;
	int value = -1;
	
	if (header == NULL) {
		cout << "List is empty" << endl;
		return value;
	}
	if (count == 1) {
		value = header->data;
		header = NULL;
		count = 0;
		return value;
	}
	tmp = header;
	value = header->data;
	header = tmp->next;
	count--;
	delete tmp;
	return value;
}

int LinkedList::removeAt(int index)
{
	Node *tmp;
	Node *follow;
	int value = -1;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return value;
	}
	if (count == 1 && index == 0) {
		value = header->data;
		header = NULL;
		count = 0;
		return value;
	}
	if (index == 0) {
		value = header->data;
		tmp = header->next;
		header = tmp;
		count--;
		return value;
	}
	if (index > count-1) {
		cout << "Incorrect index" << endl;
		return value;
	}
	tmp = header;
	for (int i = 0; i < index; i++) {
		follow = tmp;
		tmp = tmp->next;
	}
	value = tmp->data;
	follow->next = tmp->next;
	count--;
	delete tmp;
	return value;
}

int LinkedList::remove(int x)
{
	Node *tmp;
	Node *follow;
	int pos = 0;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return -1;
	}
	if (header->data == x) {
		header = header->next;
		count--;
		return pos;
	}
	tmp = header;
	while (tmp != NULL) {
		if (tmp->data == x) {
			follow->next = tmp->next;
			count--;
			delete tmp;
			return pos;
		}
		follow = tmp;
		tmp = tmp->next;
		pos++;
	}
	cout << "No such element" << endl;
	return -1;
}

int LinkedList::removeFirst()
{
	int value = -1;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return value;
	}
	value = header->data;
	header = header->next;
	count--;
	return value;
}

int LinkedList::removeLast()
{
	Node *tmp;
	Node *follow;
	int value = -1;

	if (header == NULL) {
		cout << "List is empty" << endl;
		return value;
	}
	if (count == 1) {
		value = header->data;
		header = NULL;
		count = 0;
		return value;
	}
	tmp = header;
	while (tmp->next != NULL) {
		follow = tmp;
		tmp = tmp->next;
	}
	count--;
	value = tmp->data;
	follow->next = NULL;
	delete tmp;
	return value;
}

void LinkedList::set(int index, int x)
{
	Node *tmp;
	
	if (header == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	if (index > count-1) {
		cout << "Incorrect index" << endl;
		return;
	}
	tmp = header;
	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	tmp->data = x;
	return;
}

int *LinkedList::toArray()
{
	int* arr = (int *)malloc(sizeof(int) * count);
	Node *tmp;

	tmp = header;
	for (int i = 0; i < count; i++) {
		arr[i] = tmp->data;
		tmp = tmp->next;
	}

	return arr;
}