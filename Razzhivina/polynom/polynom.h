#pragma once

#include <string>
#include <iostream>


using namespace std;
 
struct Node {
	Node *pNext;
	double coef;										//коэффициент
	int deg;											//степень
};

class Pol_str {
	string str;											//строка полином
public:
	Pol_str(string _str);				
	bool IsCorrect();									//проверка на корректность
	string GetString()const { return str; };			//получить строку
};

class Polynom {
	Node *pFirst;
public:
	Polynom();
	Polynom(const Polynom& pol);
	Polynom(Pol_str _str);
	~Polynom();

	Polynom& operator= (const Polynom& pol);

	Polynom operator+(const Polynom& pol);
	Polynom operator*(const Polynom& pol);

	bool operator==(const Polynom& pol);
	bool operator!=(const Polynom& pol);

	Polynom MultByConst(double c);						//умножение на константу

	void Insert(double coef, int deg);
	void Annul();
	void Print();

	double Calculation(double x, double y, double z);

};

