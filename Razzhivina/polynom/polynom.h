#pragma once

#include <string>
#include <iostream>
#include "instruction.h"

using namespace std;
 
struct Node {
	Node *pNext;
	double coef;			//коэффициент
	int deg;				//степень
};

class Polynom {
	Node *pFirst;
public:
	Polynom();
	Polynom(const Polynom& pol);
	Polynom(pol_string str);
	~Polynom();

	Polynom& operator= (const Polynom& pol);

	Polynom operator+(const Polynom& pol);
	Polynom operator*(const Polynom& pol);

	bool operator==(const Polynom& pol);
	bool operator!=(const Polynom& pol);

	Polynom MultByConst(double c);

	void Insert(double coef, int deg);
	void Annul();
	void Print();

	double Calculation(double x, double y, double z);

};

class pol_string {
	string str;
public:
	bool IsCorrect();
	string GetString()const { return str; };
	pol_string(string _str);
};

//class Polynom{
//	string polynom;
//	Node <Monom> pol;
//public:
//	Polynom(string _pol ="");
//	~Polynom();
//
//	bool IsOperand(char op);
//	bool IsOperatin(char op);
//
//	Polynom operator+(Polynom& pol);
//	Polynom operator-(Polynom& pol);
//	Polynom& operator=(Polynom &pol);
//
//	void PolynomINString();
//	void FillPolinom();
//
//	int Const(string tmp);
//
//	string GetPolinom() { return polynom; }
//};
//
