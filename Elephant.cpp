#include "Elephant.h"

int Elephant::N_ELEPHANT = 0;

ostream& operator<<(ostream& out, Elephant& e)
{
	out << "Elephant: " << e.ms_name << ", weight: "
			<< e.m_weight << ", length: " << e.m_trunkLength;
	return out;
}

Elephant::Elephant(string name)
	: Animal(name)
{
	N_ELEPHANT++;
	m_weight = 100;
	m_trunkLength = 1.0;
}

Elephant::~Elephant()
{
}

void Elephant::eat(int x)
{
	Animal::eat(0.01*x);
}