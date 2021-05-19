#ifndef WashingM_H
#define WashingM_H

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"Clothes.h"

using namespace std;

class WashingM {

	int load;
	vector<Clothes> clothes;

public:
	WashingM(int);
	void loading(const vector<Clothes>&);
	void washing(Program);
	//int getweight();
	ostream& print(ostream&) const;
};

ostream& operator<< (ostream&, const WashingM&);

#endif

