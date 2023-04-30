#pragma once
#include "animal.h"
class Elephant :
	public Animal
{
	static int N_ELEPHANT;
	double m_trunkLength;
public:
	Elephant(string name);
	~Elephant();
	virtual void eat(int x);
	void foo() {
		cout << "Elephant::foo()" << endl;
	}
	virtual void hoo() {
		cout << "Elephant::hoo()" << endl;
	}
	static int Get_N() { return N_ELEPHANT; }
	virtual int getClassID() { return ID_ELEPHANT; }
	friend ostream& operator<<(ostream& outs, Elephant& e);
};

