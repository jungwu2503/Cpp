#include <iostream>
using namespace std;

#include <list>
#include <time.h>
#include "Lion.h"
#include "Elephant.h"

int add(int x, int y) {
	return x + y;
}

void main()
{
	//list<Animal *> *cage = new list<Animal *>();
	list<Animal *> cage;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++) {
		int rnd = rand();
		int remainder = rnd % 1000;
		char name[10];
		sprintf(name, "animal%d", remainder);
		if (rnd % 2 == 0) cage.push_back(new Lion(name));
		else cage.push_back(new Elephant(name));
	}

	list<Animal *>::iterator i;

	for (int day = 0; day < 365; day++) {
		for (i = cage.begin(); i != cage.end(); i++) {
			Animal *animal = *i;
			//animal->foo();		// static binding
			//animal->hoo();		// dynamic binding
			int food = 0;
			if (animal->getClassID() == ID_LION) {
				food = rand()%100;
			} else if (animal->getClassID() == ID_ELEPHANT) {
				food = rand()%10000;
			}
			animal->eat(food);
		}
	}	

	for (i = cage.begin(); i != cage.end(); i++) {
		Animal *animal = *i;

		if (animal->getClassID() == ID_LION) {
			cout << (Lion&)(*animal) << endl;
		} else if (animal->getClassID() == ID_ELEPHANT) {
			cout << (Elephant&)(*animal) << endl;
		}
	}

	/*
	Lion l1("l1");
	Lion l2("l2");
	Lion l3("l3");
	Elephant e1("e1");
	Elephant e2("e2");

	//Animal animal[10];	//static binding
	Animal* animal[10];		//dynamic binding
	int nCount = 10;

	animal[0] = &l1;
	animal[1] = &l2;
	animal[2] = &e1;
	animal[3] = &l3;
	animal[4] = &e2;
	nCount = 5;

	for (int i = 0; i < nCount; i++) {
		//animal[i].foo();  // static binding
		//animal[i].hoo();  // static binding
		animal[i]->foo();	// static binding
		animal[i]->hoo();	// dynamic binding
	}

	cout << l1 << endl;
	cout << e1 << endl;

	cout << "n of animals = " << Animal::Get_N() << endl;
	cout << "n of lions = " << Lion::Get_N() << endl;
	cout << "n of elephants = " << Elephant::Get_N() << endl;

	string s;

	s = "123";

	int n = 10;

	cout << add(n, stoi(s)) << endl;

	//n = n + stoi(s);

	//cout << n << endl;
	*/
}