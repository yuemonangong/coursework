#pragma once
#include <string>
#include<cstdlib>
#include<ctime>
#include "card.h"
#include "seqList.h"
#define MAXINT 20

using namespace std;
class area
{
private:
	string name;
	seqList<card> content;
	int maxSize;
	int currentSize;
public:
	area(string n = "", int ms = MAXINT);
	~area();
	bool addCard(const card &c);
	bool removeCard(const card &c);
	bool isAvailable() const;
	bool isEmpty() const;
	bool isContained(const card &c) const;
	void display() const;
	card selectRanCard() const;
	int getCardNum() const { return currentSize; }
	string visitCardName(int i) const { return content.visit(i).getname(); } //i>=0 && i<currentLength
};

