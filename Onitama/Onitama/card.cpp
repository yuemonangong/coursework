#include "card.h"



card::card(string n)
{
	name = n;
}

bool card::operator==(const card & c) const
{
	return (name == c.name);
}


card::~card()
{
}

string card::getname() const
{
	return name;
}

ostream & operator<<(ostream & os, const card & c)
{
	os << c.name;
	return os;
}
