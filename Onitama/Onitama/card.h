#pragma once
#include <string>
#include <iostream>

using namespace std;

class card
{
	friend ostream &operator<<(ostream &os, const card &c);
private:
	string name;
public:
	card(string n = "");
	bool operator==(const card &c) const;
	~card();
	string getname() const;
};

