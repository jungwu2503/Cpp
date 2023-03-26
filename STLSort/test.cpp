#include <iostream>
using namespace std;
#include <time.h>
#include <string>



int compareInt(const void *x, const void *y) // 값 읽기만
{
	int *p = (int *)x;
	int *q = (int *)y;

	return *p - *q;
}

int compareCharPointer(const void *x, const void *y)
{
	char *p = *(char **)x;
	char *q = *(char **)y;

	return strcmp(p, q);
}

int compareString(const void *x, const void *y)
{
	string p = *(string *)x;
	string q = *(string *)y;

	if (p > q) return 1;
	else if (p < q) return -1;
	else return 0;
}

int compareStringPointer(const void *x, const void *y)
{
	string *p = *(string **)x;
	string *q = *(string **)y;

	if (*p > *q) return 1; //dereferencing 안하면 주소값 sorting
	else if (*p < *q) return -1;
	else return 0;
}

class Student 
{
	static int method;
	string name;
	int score;
public:
	Student()
	{
		name = "";
		score = 0;
	}
	Student(string name, int score) 
	{
		this->name = name;
		this->score = score;
	}
	static void sortBy(int m) {
		method = m;
	}
	friend ostream& operator<<(ostream& out, Student &st);
	friend int compareStudent(const void *x, const void *y);
};

#define NAME	(0)
#define SCORE	(1)
int Student::method = NAME;

int compareStudent(const void *x, const void *y)
{
	Student p = *(Student *)x;
	Student q = *(Student *)y;

	if (Student::method == NAME) {
		if (p.name > q.name) return 1;
		else if (p.name < q.name) return -1;
		else return 0;
	}
	else if (Student::method == SCORE) {
		return p.score - q.score;
	}
}

ostream& operator<<(ostream& out, Student &st)
{
	out << st.name << ", " << st.score << "; ";
	return out;
}

void main()
{
	Student st[5];

	st[0] = Student("kim", 30);
	st[1] = Student("lee", 50);
	st[2] = Student("park", 10);
	st[3] = Student("kwon", 70);
	st[4] = Student("oh", 40);

	for (int i = 0; i < 5; i++) cout << st[i] << " ";
	cout << endl;

	Student::sortBy(NAME);
	qsort(st, 5, sizeof(Student), compareStudent);

	for (int i = 0; i < 5; i++) cout << st[i] << " ";
	cout << endl;

	Student::sortBy(SCORE);
	qsort(st, 5, sizeof(Student), compareStudent);

	for (int i = 0; i < 5; i++) cout << st[i] << " ";
	cout << endl;

	/*
	string* x[5];

	x[0] = new string("kim");
	x[1] = new string("lee");
	x[2] = new string("oh");
	x[3] = new string("park");
	x[4] = new string("kwon");

	for (int i = 0; i < 5; i++) cout << *x[i] << " ";
	cout << endl;

	qsort(x, 5, sizeof(string*), compareStringPointer);

	for (int i = 0; i < 5; i++) cout << *x[i] << " ";
	cout << endl;*/

	/*
	string x[5];

	x[0] = string("kim");
	x[1] = string("lee");
	x[2] = string("oh");
	x[3] = string("park");
	x[4] = string("kwon");

	for (int i = 0; i < 5; i++) cout << x[i] << " ";
	cout << endl;

	qsort(x, 5, sizeof(string), compareString);

	for (int i = 0; i < 5; i++) cout << x[i] << " ";
	cout << endl;*/

	/*
	char* x[5];

	x[0] = "kim";
	x[1] = "lee";
	x[2] = "oh";
	x[3] = "park";
	x[4] = "kwon";

	for (int i = 0; i < 5; i++) cout << x[i] << " ";
	cout << endl;

	qsort(x, 5, sizeof(char*), compareCharPointer);

	for (int i = 0; i < 5; i++) cout << x[i] << " ";
	cout << endl;*/

	/* int x[10];

	srand((int)time(NULL)); //seeding - time, process id

	for (int i = 0; i < 10; i++) {
		x[i] = rand() % 100; // pseudo random number
	}

	for (int i = 0; i < 10; i++) cout << x[i] << " ";
	cout << endl;

	qsort(x, 10, sizeof(int), compareInt);

	for (int i = 0; i < 10; i++) cout << x[i] << " ";
	cout << endl; */
}