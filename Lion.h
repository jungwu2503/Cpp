#pragma once
#include "animal.h"
class Lion :
	public Animal
{
	static int N_LION;
	double m_teethStrength;
public:
	Lion(string name);
	~Lion();
	virtual void eat(int x);
	void foo() {
		cout << "Lion::foo()" << endl;
	}
	virtual void hoo() {
		cout << "Lion::hoo()" << endl;
	}
	static int Get_N() { return N_LION; }
	virtual int getClassID() { return ID_LION; }
	friend ostream& operator<<(ostream& outs, Lion& l);
};
