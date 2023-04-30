#pragma once

#include <iostream>
using namespace std;

#include <string>

#define ID_ANIMAL		(0)
#define ID_LION			(1)
#define ID_ELEPHANT		(2)

class Animal
{
	static int N_ANIMAL;
protected:
	string ms_name;
	int m_weight;
public:
	Animal();
	Animal(string name);
	~Animal();
	virtual void eat(int x);
	void foo() {
		cout << "Animal::foo()" << endl;
	}
	virtual void hoo() {
		cout << "Animal::hoo()" << endl;
	}
	static int Get_N() { return N_ANIMAL; }
	virtual int getClassID() { return ID_ANIMAL; }
};
