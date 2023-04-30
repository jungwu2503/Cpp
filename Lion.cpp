#include "Lion.h"

int Lion::N_LION = 0;

ostream& operator<<(ostream& out, Lion& l)
{
	out << "Lion: " << l.ms_name << ", weight: " << l.m_weight << ", strength: " << l.m_teethStrength;
	return out;
}

Lion::Lion(string name)
	: Animal(name)
{
	N_LION++;
	m_weight = 5;
	m_teethStrength = 30;
}

Lion::~Lion()
{
}

void Lion::eat(int x)
{
	Animal::eat(0.1*x);
}