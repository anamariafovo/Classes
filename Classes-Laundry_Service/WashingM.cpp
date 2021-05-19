#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"Clothes.h"
#include"WashingM.h"

using namespace std;

WashingM::WashingM(int load) : load{ load } {

	if (load < 4000 || load > 50000)
		throw runtime_error("load nicht gut!");
}

void WashingM::loading(const vector<Clothes>& z) {

	//int l = 0;

	for (size_t i{ 0 }; i < z.size(); ++i)
		clothes.push_back(z.at(i));

}

void WashingM::washing(Program instruction) {

	int l = 0;

	for (size_t i{ 0 }; i < clothes.size(); ++i)
	{
		if (!clothes.at(i).compatible(instruction))
		{
			throw runtime_error("Not safe to wash!");
		}
		l += clothes.at(i).getweight();  //l += clothes.at(i).l += gewicht
		if (l > load)
		{
			//clothes.clear();
			throw runtime_error("load zu groess!");
		}
	}

	//cout << "Washing succeded!" << endl;
	clothes.clear();
}

ostream& WashingM::print(ostream& out) const {

	out << "[" << load << " g " << "{";
	for (size_t i{ 0 }; i < clothes.size(); ++i)
	{
		out << clothes.at(i);
		if (i < clothes.size() - 1)
			out << ", ";
	}
	out << "}";
	out << "]";

	return out;
}

ostream& operator<< (ostream& out, const WashingM& m) {

	return m.print(out);
}