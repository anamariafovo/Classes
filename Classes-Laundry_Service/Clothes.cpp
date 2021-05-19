#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"Clothes.h"
using namespace std;

vector<string> Program_names{ "Hot_washing", "Normal_washing", "Colored_washing", "Fine_washing" };

Clothes::Clothes(const string& name, const int& weight) : name{ name }, weight{ weight }, instruction{ Program::Normal }{

	if (name.size() <= 0)
		throw runtime_error("Name shouldn't be empty!");

	if (weight <= 0 || weight >= 5000)
		throw runtime_error("Weight not good!");
}

Clothes::Clothes(const string& name, const int& weight, const Program& instruction) : name{ name }, weight{ weight }, instruction{ instruction }{
	if (name.size() <= 0)
		throw runtime_error("Name shouldn't be empty!");

	if (weight <= 0 || weight >= 5000)
		throw runtime_error("Weight not good!");
}

bool Clothes::compatible(Program instruction) const {

	if (this->instruction > instruction)
		return false;

	return true;
}


int Clothes::getweight() {

	int l = 0;
	l += weight;
	return l;
}

ostream& Clothes::print(ostream& out) const {
	out << "[" << name << ", " << weight << " g, ";

	if (instruction == Program::Hot)
		out << Program_names.at(0) << "]";

	else if (instruction == Program::Normal)
		out << Program_names.at(1) << "]";

	else if (instruction == Program::Colored)
		out << Program_names.at(2) << "]";

	else if (instruction == Program::Fine)
		out << Program_names.at(3) << "]";

	return out;
}

ostream& operator<< (ostream& out, const Clothes& k) {
	return k.print(out);
}