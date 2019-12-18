#pragma once
#include "list.h"
#include "monom.h"
#include <sstream>

class Polinom {
	List <Monom> Pol;
public:
	Polinom(string _pol) { StringToPolinom(_pol); }
	void StringToPolinom(string _pol);
	void Sorting();

	bool IsVar(char _c);
	bool IsOperation(char _c);
	bool IsNum(char _c);

	bool operator!=(const Polinom& _pl);
	bool operator==(const Polinom& _pl);

	bool IsRight(string _pol);
	double Calculation(double _x, double _y, double _z);

	Polinom operator+(Polinom& _pl);
	Polinom operator-(Polinom& _pl);
	Polinom operator*(Polinom& _pl);
	Polinom operator*(double C);

	string Insc(double c) { ostringstream oss; oss << c; return oss.str(); }
	string GetPolinom();
};