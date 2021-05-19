#ifndef Clothes_H
#define Clothes_H

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;

enum class Program { Hot, Normal, Colored, Fine };
extern vector<string> Program_names;

class Clothes {

	string name;
	int weight;
	Program instruction;

public:

	Clothes(const string&, const int&);
	Clothes(const string&, const int&, const Program&);
	bool compatible(Program) const;  //==> ???
	int getweight();
	ostream& print(ostream&) const;
};

ostream& operator<< (ostream&, const Clothes&);

#endif

