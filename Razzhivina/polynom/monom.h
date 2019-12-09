#pragma once

#include <iostream>
using namespace std;

struct Monom {
	int coef,
		pow;
	int GetCoef() { return coef; }
	int GetPow() { return pow; }

	Monom(int _coef = 0, int _pow = 0) {
		coef = _coef; 
		pow = _pow;
	}
	Monom operator+(const Monom &mon) {
		if (pow != mon.pow)
			throw "ошибка operator+ в monom.h";
		Monom tmp;
		tmp.coef = coef + mon.coef;
		tmp.pow = pow;
		return tmp;
	}
	Monom operator-(const Monom &mon) {
		if (pow != mon.pow)
			throw "ошибка operator- в monom.h";
		Monom tmp;
		tmp.coef = coef - mon.coef;
		tmp.pow = pow;
		return tmp;
	}

	Monom& operator=(const Monom &mon) {
		coef = mon.coef;
		pow = mon.pow;
		return *this;
	}

	bool operator==(const Monom &mon) {
		if ((coef == mon.coef) && (pow == mon.pow))
			return true;
		else return false;
	}

	friend ostream& operator<<(ostream& _ostr, const Monom& mon);
};

ostream& operator<<(ostream& _ostr, Monom& mon) {
	_ostr << mon.GetCoef();
	_ostr << "x" << (mon.GetPow() / 100);
	_ostr << "y" << (mon.GetPow() % 100/10);
	_ostr << "z" << (mon.GetPow() / 100);
	return _ostr;
}