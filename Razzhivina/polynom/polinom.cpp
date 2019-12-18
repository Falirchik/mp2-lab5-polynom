#include "polinom.h"
//#include <math>

//using namespace std;

void Polinom::StringToPolinom(string _pol){
	Pol.DelAll();
	Monom tmp_m(0,-1,-1,-1);
	Pol.InFict(tmp_m);
	string tmp;
	double coef = 1;
	int degX = 0,
		degY = 0,
		degZ = 0,
		sign = 0,
		size = _pol.size();
	for (int i = 0; i < size;) {
		for (; _pol[i] == ' ';)
			i++;
		if ((IsOperation(_pol[i])) && (i < size)) {
			if (_pol[i] == '+')
				sign = 1;
			if (_pol[i] == '-')
				sign = -1;
		}
		while ((IsNum(_pol[i])) && (i< size)) {
			tmp += _pol[i];
			i++;
		}
		while ((IsVar(_pol[i])) && (i < size))
			switch (_pol[i]) {
			case 'x': {
				if (_pol[i + 1] != '^') {
					degX = 1;
					i++;
				}
				else {
					i += 2;
					for (; ((!IsVar(_pol[i])) && (!IsOperation(_pol[i])) && (i < size));) {
						degX = degX * 10 + (_pol[i] - '0'); i++;
					}
				}
				continue;
			}
			case 'y': {
				if (_pol[i + 1] != '^') {
					degX = 1;
					i++;
				}
				else {
					i += 2;
					for (; ((!IsVar(_pol[i])) && (!IsOperation(_pol[i])) && (i < size));) {
						degY = degY * 10 + (_pol[i] - '0'); i++;
					}
				}
				continue;
			}
			case 'z': {
				if (_pol[i + 1] != '^') {
					degX = 1;
					i++;
				}
				else {
					i += 2;
					for (; ((!IsVar(_pol[i])) && (!IsOperation(_pol[i])) && (i < size));) {
						degZ = degZ * 10 + (_pol[i] - '0'); i++;
					}
				}
				continue;
			}
			}
		if (tmp == "")
			coef = 1 * sign;
		else  coef = sign * stoi(tmp);
		tmp_m.SetData(coef, degX, degY, degZ);
		if (!Pol.IsEmpty())
			Pol.InLast(tmp_m);
		else Pol.InFirst(tmp_m);
		tmp_m.Clean();
	}
	if (!Pol.IsEmpty())
		Sorting();
}

void Polinom::Sorting(){
	Polinom tmp_p("");
	Monom tmp_m;
	double pCoef;
	for (; !Pol.IsEnd();) {
		tmp_m = Pol.GetData();
		if (!(tmp_p.Pol.IsEmpty())) {
			if (!tmp_p.Pol.IsEmpty()) {
				tmp_p.Pol.CurrInFirst();
				Monom tmp_mm = tmp_p.Pol.GetData();
				Monom mon(1, 0, 0, 0);
				while ((tmp_mm > mon) && (!tmp_p.Pol.IsLast()) && (tmp_mm > tmp_m)) {
					tmp_p.Pol.StepForward();
					tmp_mm = tmp_p.Pol.GetData();
				}
				if (!tmp_p.Pol.IsEnd()) {
					tmp_p.Pol.InCurr(tmp_m);
					Pol.DelFirst();
				}
				else if ((tmp_mm.LikeMonom(tmp_m))) {
					pCoef = tmp_mm.GetCoef() + tmp_m.GetCoef();
					tmp_m.SetCoef(pCoef);
					tmp_p.Pol.SetData(tmp_m);
					Pol.DelFirst();
				}
				else if (tmp_p.Pol.IsEnd()) {
					tmp_p.Pol.InLast(tmp_m);
					Pol.DelFirst();
				}
			}
		}
		else {
			tmp_p.Pol.InFirst(tmp_m);
			Pol.DelFirst();
		}
	}
	*this = tmp_p;
}

	bool Polinom::IsVar(char _c){
		if ((_c == 'x') || (_c == 'y') || (_c == 'z'))
			return true;
		else return false;
	}

	bool Polinom::IsOperation(char _c){
		if ((_c == '+') || (_c == '-'))
			return true;
		else return false;
	}

	bool Polinom::IsNum(char _c){
		if ((_c >= '0') || (_c <= '9'))
			return true;
		else return false;
	}

	bool Polinom::operator!=(const Polinom & _pl){
		Polinom tmp = _pl;
		Monom tmp1, tmp2;
		for (tmp.Pol.CurrInFirst(); !tmp.Pol.IsLast(); tmp.Pol.StepForward()) {
			tmp1 = Pol.GetData();
			tmp2 = tmp.Pol.GetData();
			if (tmp1 != tmp2)
				return true;
		}
		return false;
	}

	bool Polinom::operator==(const Polinom & _pl){
		return (!(*this!=_pl));
	}

	bool Polinom::IsRight(string _pl) {
		int size = _pl.size(),
			VarMon[3] = { 0,0,0 },
			workMon=0;
		string allowed = "xyz.0123456789+-^";
		bool flag2;
		bool flag1 = flag2= false;



		if (size == 0)
			return false;
		if (_pl[0] == allowed[3])
			return false;
		else {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < 3; j++) {
					if ((_pl[i] == allowed[j]) && (!flag1))
						if (VarMon[j] == 1)
							return false;
					VarMon[j]++;
					flag1 = flag2 = true;
					workMon = 0;
					break;
				}
				if (flag1) {
					if (_pl[1] == '^') {
						i++;
						if ((_pl[i] >= '0') || (_pl[i] <= '9')) {
							string tmp = "xyz+-";
							int miss = 0;
							for (int m = 0; m < 5; m++)
								if (_pl[i + 1] != tmp[m])
									miss++;
							if (miss == 5)
								return false;
							else flag1 = false;
						}
						else return false;
					}
					else return false;
				}
			}
			if ((_pl[size - 1] == '+') || (_pl[size - 1] == '-'))
				return false;
			return true;
		}
	}

	double Polinom::Calculation(double _x, double _y, double _z){
		double X = _x,
			Y = _y,
			Z = _z,
			dx,dy,dz,
			res=0,
			_coef;
		Monom tmp;
		for (Pol.CurrInFirst(); !Pol.IsEnd(); Pol.StepForward()) {
			tmp = Pol.GetData();
			_coef = tmp.GetCoef();
			dx = tmp.GetDegX();
			dy = tmp.GetDegY();
			dz = tmp.GetDegZ();
			res += (_coef*pow(X, dx)*pow(Y, dy)*pow(Z, dz));
		}
		return res;
	}

	Polinom Polinom::operator+(Polinom & _pl){
		Monom tmp_m1, tmp_m2;
		Polinom res("");
		double _coef;
		Pol.CurrInFirst();
		_pl.Pol.CurrInFirst();
		while (!Pol.IsEnd()) {
			tmp_m1 = Pol.GetData();
			tmp_m2 = _pl.Pol.GetData();
			if (tmp_m1.LikeMonom(tmp_m2)) {
				_coef = tmp_m1.GetCoef() + tmp_m2.GetCoef();
				if (_coef != 0) {
					tmp_m1.SetCoef(_coef);
					res.Pol.InLast(tmp_m1);
				}
				Pol.StepForward();
				_pl.Pol.StepForward();
			}
			else if (tmp_m2 > tmp_m1) {
				res.Pol.InLast(tmp_m2);
				_pl.Pol.StepForward();
			}
			else {
				res.Pol.InLast(tmp_m1);
				Pol.StepForward();
			}
		}
		for (; !_pl.Pol.IsEnd();) {//полиному во втором мономе?
			res.Pol.InLast(tmp_m2);
			_pl.Pol.StepForward();
			tmp_m2 = _pl.Pol.GetData();
		}
		return res;
		
	}

	Polinom Polinom::operator-(Polinom & _pl)	{
		Polinom tmp1 = *this,
			tmp2 = _pl*(-1);
		tmp1 = tmp1 + tmp2;
		return tmp1;
	}

	Polinom Polinom::operator*(Polinom & _pl){
		Polinom res("");
		_pl.Pol.CurrInFirst();
		Pol.CurrInFirst();
		Monom tmp1, tmp2, tmp3;
		while (!Pol.IsEnd()) {
			tmp1 = Pol.GetData();
			while (!_pl.Pol.IsEnd()) {
				tmp2 = _pl.Pol.GetData();
				tmp3 = tmp1 * tmp2;
				res.Pol.InLast(tmp3);
				_pl.Pol.StepForward();
			}
			_pl.Pol.CurrInFirst();
			Pol.StepForward();
		}
		res.Sorting();
		return res;
	}

	Polinom Polinom::operator*(double C){
		Polinom tmp_p = *this;
		double _coef;
		Monom tmp_m;
		while (!tmp_p.Pol.IsEnd()) {
			tmp_m = tmp_p.Pol.GetData();
			_coef = C * tmp_m.GetCoef();
			tmp_m.SetCoef(_coef);
			tmp_p.Pol.SetData(tmp_m);
		}
		return tmp_p;
	}

	string Polinom::GetPolinom(){
		string res = "";
		int x, y, z;
		double _coef;
		Monom tmp_m;
		if (!Pol.IsEmpty()) {
			for (Pol.CurrInFirst(); !Pol.IsEnd(); Pol.StepForward()) {
				tmp_m = Pol.GetData();
				_coef = tmp_m.GetCoef();
				x = tmp_m.GetDegX();
				y = tmp_m.GetDegY();
				z = tmp_m.GetDegZ();
				if (_coef > 0) 
					res += '+';
				string mon = "";
				if ((x == 0) && (y != 0) && (z != 0))
					mon = Insc(_coef) + "y^" + Insc(y) + "z^" + Insc(z);
				else if ((x != 0) && (y == 0) && (z != 0))
					mon = Insc(_coef) + "x^" + Insc(x) + "z^" + Insc(z);
				else if ((x != 0) && (y != 0) && (z == 0))
					mon = Insc(_coef) + "x^" + Insc(x) + "y^" + Insc(y);
				else if ((x == 0) && (y == 0) && (z != 0))
					mon = Insc(_coef) + "z^" + Insc(z);
				else if ((x != 0) && (y == 0) && (z == 0))
					mon = Insc(_coef) + "x^" + Insc(x);
				else if ((x == 0) && (y != 0) && (z == 0))
					mon = Insc(_coef) + "y^" + Insc(y);
				else if((x != 0) && (y != 0) && (z != 0))
					mon= Insc(_coef) + "x^" + Insc(x) + "y^" + Insc(y) + "z^" + Insc(z);
				else if ((x == 0) && (y == 0) && (z == 0))
					mon = Insc(_coef);
				res += mon;
			}
		}

		return res;
	}
