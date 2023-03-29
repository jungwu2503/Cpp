#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
using namespace std;

class JString
{
	char *s;
	int length;
public:
	JString() {
		s = NULL; length = 0;
	}
	JString(JString &arg);
	JString(char *arg) {
		//cout << "JString(char *arg)" << endl;
		s = _strdup(arg);
		length = strlen(arg);
	}
	~JString() {
		//cout << "Bye" << endl;
		if (s) delete s;
		s = NULL;
	}
	void operator=(char *arg) {
		//cout << "operator=(char *arg)" << endl;
		length = strlen(arg);
		s = _strdup(arg);
	}
	void operator=(JString &arg) {
		//cout << "operator=(JString &arg)" << endl;
		length = arg.length;
		s = _strdup(arg.s);
	}
	JString operator+(JString &arg) {
		char tmp[BUFSIZ];
		strcpy_s(tmp, BUFSIZ, s);
		strcat_s(tmp, BUFSIZ, arg.s);
		return JString(&tmp[0]); 
		/*JString *p = new JString();
		p->length = length + arg.length;
		p->s = new char[p->length+1];
		strcpy_s(p->s, p->length+1, s);
		strcat_s(p->s, p->length+1, arg.s);
		return *p;*/
	}
	JString operator+(char *arg) {
		char tmp[BUFSIZ];
		strcpy_s(tmp, BUFSIZ, s);
		strcat_s(tmp, BUFSIZ, arg);
		return JString(&tmp[0]);
		/*JString *p = new JString();
		p->length = length + strlen(arg);
		p->s = new char[p->length+1];
		strcpy_s(p->s, p->length+1, s);
		strcat_s(p->s, p->length+1, arg);
		return *p;*/
	}
	bool operator>(JString &arg) {
		int cmp = strcmp(s, arg.s);
		if (cmp > 0) return true;
		return false;
	}
	bool operator<(JString &arg) {
		int cmp = strcmp(s, arg.s);
		if (cmp < 0) return true;
		return false;
	}
	bool operator==(JString &arg) {
		int cmp = strcmp(s, arg.s);
		if (cmp == 0) return true;
		return false;
	}
	char& operator[](int index) {
		return s[index];
	}
	friend ostream& operator<<(ostream& outs, JString &s);
};

JString::JString(JString &arg)
{
	//cout << "JString::JString(JString &arg)" << endl;
	length = arg.length;
	s = _strdup(arg.s);
}

ostream& operator<<(ostream& outs, JString &s)
{
	outs << s.s << "(" << s.length << ")";
	return outs;
}

istream& operator>>(istream& ins, JString &s)
{
	char buffer[BUFSIZ];
	ins >> buffer;
	s = buffer;
	return ins;
}

class Student {
public:
	JString name;
	int grade;
	Student() {
		name = "";
		grade = 0;
	}
	Student(char *s, int g) {
		name = s;
		grade = g;
	}
	Student(JString s, int g) {
		name = s;
		grade = g;
	}
};

void main()
{
	JString s1 = "Hello";
	JString s2 = s1;
	JString s3("Hi");
	JString s4(s3);
	char c;
	Student st[100];

	ifstream in("data.txt");
	int n;
	in >> n;

	cout << "n = " << n << endl;
	
	for (int i = 0; i < n; i++) {
		in >> st[i].name >> st[i].grade;
	}

	for (int i = 0; i < n; i++) {
		cout << st[i].name << " " << st[i].grade << endl;
	}

	/*
	list<JString> l;

	for (int i = 0; i < 3; i++) {
		JString name;
		cin >> name;
		l.push_back(JString(name));
	}

	//l.push_back(JString("KIM"));
	//l.push_back(JString("LEE"));
	//l.push_back(JString("PARK"));

	list<JString>::iterator it = l.begin();
	while (it != l.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;*/

	/*
	for (int i = 0; i < 3; i++) 
		cin >> st[i].name >> st[i].grade;

	for (int i = 0; i < 3; i++) 
		cout << st[i].name << " " << st[i].grade << endl;

	s1 = "kim";
	s2 = s1;

	c = s1[1];
	s1[2] = 'P';

	cout << c << " " << s1 << " " << s2 << " " << s3 << " " << s4 << endl;

	s3 = s1 + s2;
	
	s2 = s1 + "hello";

	s4 = s1 + "kim" + s2 + s3 + "lee";

	cout << c << " " << s1 << " " << s2 << " " << s3 << " " << s4 << endl;

	s1 = "hello";
	s2 = "hi";

	if (s1 > s2) {
		cout << "s1 is greater than s2" << endl;
	} else {
		cout << "s1 is less than s2" << endl;
	}*/

	/*char *p1;
	char *p2;

	p1 = _strdup("kim");
	//p2 = p1;	//shallow copy
	p2 = _strdup(p1);

	p1[1] = 'j';

	cout << p1 << " " << p2 << endl;*/

	/*char p1[10];
	char p2[10];

	strcpy_s(p1, "kim");
	strcpy_s(p2, p1);

	cout << p1 << " " << p2 << endl;*/

	/*char *p1;
	char *p2;


	p1 = "kim";
	p2 = p1;

	p1[1] = 'j';

	cout << p1 << " " << p2 << endl;*/
}