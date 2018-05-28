#include "area.h"



area::area(string n, int ms)
{
	name = n;
	maxSize = ms;
	currentSize = 0;
}

area::~area()
{
}

bool area::addCard(const card & c)
{
	if (currentSize == maxSize) return false;
	if (content.search(c) != -1) return false;
	content.insert(c, content.length());
	currentSize++;
	return true;
}

bool area::removeCard(const card & c)
{
	int index = content.search(c);
	if (index == -1) return false;
	content.remove(index);
	currentSize--;
	return true;
}

bool area::isAvailable() const
{
	return !(maxSize == currentSize);
}

bool area::isEmpty() const
{
	return currentSize == 0;
}

bool area::isContained(const card & c) const
{
	return (content.search(c) != -1);
}

void area::display() const
{
	cout << name << ": ";
	content.traverse();
}

card area::selectRanCard() const
{
	srand(time(NULL));
	if (currentSize == 0) return card();
	return content.visit(rand()%currentSize);
}
