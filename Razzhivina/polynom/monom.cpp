#include "monom.h"


Monom::Monom(double _coef , int _degX, int _degY, int _degZ){
	coef = _coef;
	degX = _degX;
	degY = _degY;
	degZ = _degZ;
}

Monom::Monom(const Monom & _m){
	coef = _m.coef;
	degX = _m.degX;
	degY = _m.degY;
	degZ = _m.degZ;
}

void Monom::SetData(double _coef, int dX, int dY, int dZ){
	coef = _coef;
	degX = dX;
	degY = dY;
	degZ = dZ;
}

bool Monom::operator==(const Monom & _m){
	if ((coef == _m.coef) && (degX == _m.degX) && (degY == _m.degY) && (degZ == _m.degZ))
		return true;
	else return false;
}

bool Monom::operator!=(const Monom & _m)
{   if (*this==_m) 
		return false;
	else return true; 
}

bool Monom::operator<(const Monom & _m){
	return !(*this > _m);
}

bool Monom::operator>(const Monom & _m){
	if ((degX > _m.degX) || (degY > _m.degY) || (degZ > _m.degZ))
		return true;
	else return false;
}

bool Monom::LikeMonom(const Monom & _m){
	if ((degX != _m.degX) || (degY != _m.degY) || (degZ != _m.degZ))
		return false;
	else return true;
}

Monom & Monom::operator=(const Monom & _m){
	if (*this != _m) {
		coef = _m.coef;
		degX = _m.degX;
		degY = _m.degY;
		degZ = _m.degZ;
	}
	return *this;
	// TODO: вставьте здесь оператор return
}

Monom & Monom::operator*(const Monom & _m){
	Monom tmp(coef, degX, degY, degZ);
	tmp.coef *= _m.coef;
	tmp.degX *= _m.degX;
	tmp.degY *= _m.degY;
	tmp.degZ *= _m.degZ;
	return tmp;
	// TODO: вставьте здесь оператор return
}