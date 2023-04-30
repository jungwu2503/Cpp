#include "Animal.h"

int Animal::N_ANIMAL = 0;

Animal::Animal()
{
	ms_name = "";
	m_weight = 0;
}

Animal::Animal(string name)
{
	N_ANIMAL++;
	ms_name = name;
	m_weight = 0;
}

Animal::~Animal()
{
}

void Animal::eat(int x)
{
	m_weight = m_weight + x;
}