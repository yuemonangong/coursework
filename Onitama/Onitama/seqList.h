#pragma once
#include <iostream>
using namespace std;

class IllegalSize {};
class OutOfBound {};

template <class elemType>
class seqList
{
private:
	elemType * data;
	int currentLength;
	int maxSize;
	void doubleSpace();
public:
	seqList(int initSize = 15);
	~seqList() { delete[] data; }
	void clear() { currentLength = 0; }
	int length() const { return currentLength; }
	void insert(const elemType &x, int i);
	void remove(int i);
	int search(const elemType &x) const;
	elemType visit(int i) const { return data[i]; }
	void traverse() const;
};

template <class elemType>
seqList<elemType>::seqList(int initSize)
{
	data = new elemType[initSize];
	if (!data) throw IllegalSize();
	maxSize = initSize;
	currentLength = 0;
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{
	elemType *tmp = data;
	maxSize *= 2;
	data = new elemType[maxSize];
	if (!data) throw IllegalSize();
	for (int i = 0; i<currentLength; ++i)
		data[i] = tmp[i];
	delete[] tmp;
}

template <class elemType>
void seqList<elemType>::insert(const elemType &x, int i)
{
	if (i > currentLength || i < 0) throw OutOfBound();
	if (currentLength == maxSize) doubleSpace();
	for (int j = currentLength; j>i; --j)
		data[j] = data[j - 1];
	data[i] = x;
	currentLength++;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
	if (i > currentLength || i < 0) throw OutOfBound();
	for (int j = i; j<currentLength - 1; ++j)
		data[j] = data[j + 1];
	currentLength--;
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const
{
	int i;
	for (i = 0; i<currentLength; ++i)
		if (data[i] == x) break;
	if (i == currentLength) return -1;
	else return i;
}

template <class elemType>
void seqList<elemType>::traverse() const
{
	for (int i = 0; i<currentLength; ++i)
		cout << data[i] << ' ';
	cout << endl;
}
