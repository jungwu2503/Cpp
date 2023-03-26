#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T>
ostream& operator<<(ostream& out, list<T> &l1)
{
	list<T>::iterator it = l1.begin();
	while (it != l1.end()) {
		out << *it << " ";
		it++;
	}
	out << endl;
	return out;
}

#define NAME	(0)
#define GRADE	(1)

class Student 
{
	static int method;
	string name;
	int grade;
public:
	Student() 
	{
		name = "";
		grade = 0;
	}
	Student(string n, int g)
	{
		name = n;
		grade = g;
	}
	bool operator>(Student other)
	{
		if (method == NAME)
			return name > other.name;
		if (method == GRADE)
			return grade > other.grade;
	}
	bool operator<(Student other)
	{
		if (method == NAME)
			return name < other.name;
		if (method == GRADE)
			return grade < other.grade;
	}
	static void sortBy(int m)
	{
		method = m;
	}
	friend ostream& operator<<(ostream& out, Student &l1);
};

int Student::method = NAME;

ostream& operator<<(ostream& out, Student &st)
{
	out << st.name << ", " << st.grade << " ;";
	return out;
}


void main()
{
	list<Student> st;

	st.push_back(Student("kim", 20));
	st.push_back(Student("park", 50));
	st.push_back(Student("lee", 70));
	st.push_back(Student("oh", 30));
	st.push_back(Student("choi", 40));

	cout << st;

	Student::sortBy(NAME);

	st.sort();
	cout << st;

	Student::sortBy(GRADE);

	st.sort();
	cout << st;

	/*
	list<string> l2;

	l2.push_back(string("kim"));
	l2.push_back(string("lee"));
	l2.push_back(string("park"));
	l2.push_back(string("kwon"));
	l2.push_back(string("oh"));

	cout << l2;

	l2.sort();
	cout << l2;*/

	/*list<int> l1;

	for (int i = 0; i < 10; i++) l1.push_back(rand()%100);
	cout << l1;

	l1.sort();
	cout << l1;*/

	/*
	list<int>::iterator it = l1.begin();
	while (it != l1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;*/
}