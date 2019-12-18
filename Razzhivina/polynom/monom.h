#pragma once

#include <iostream>
#include <string>
using namespace std;

class Monom {
	double coef;			//коэффициент при мономе
	int degX,				//степени
		degY,
		degZ;
		//degs;				//свернутая степень
public:
	Monom(double coef = 0, int degX = -1, int degY=-1,int degZ = -1/*,int degs = -1*/);
	Monom(const Monom& _m);

	double GetCoef() { return coef; }
	/*int GetDegs() { return degs; }*/
	int GetDegX() { return degX; }
	int GetDegY() { return degY; }
	int GetDegZ() { return degZ; }

	void Clean() { coef = degX = degY = degZ = 0; }
	void SetCoef(double _coef) { coef = _coef; };
	void SetData(double _coef, int dX, int dY, int dZ);

	bool operator== (const Monom& _m);
	bool operator!= (const Monom& _m);
	bool operator< (const Monom& _m);
	bool operator> (const Monom& _m);
	bool LikeMonom(const Monom& _m);

	Monom& operator=(const Monom& _m);
	Monom& operator*(const Monom& _m);	
};