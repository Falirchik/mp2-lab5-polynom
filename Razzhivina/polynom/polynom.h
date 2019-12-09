#pragma once
#include "Node.h"
#include "monom.h"
#include <cstring>

class Polynom{
	string polynom;
	Node <Monom> pol;
public:
	Polynom(string _pol ="");
	~Polynom();

	bool IsOperand(char op);
	bool IsOperatin(char op);

	Polynom operator+(Polynom& pol);
	Polynom operator-(Polynom& pol);
	Polynom& operator=(Polynom &pol);

	void PolynomINString();
	void FillPolinom();

	int Const(string tmp);

	string GetPolinom() { return polynom; }
};

