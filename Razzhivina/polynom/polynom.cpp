#include "polynom.h"
#include <cmath>

Polynom::Polynom(){
	Node *p = new Node;
	p->coef = 0;
	p->deg = 0;
	p->pNext = nullptr;
	pFirst = p;
}

Polynom::Polynom(const Polynom & pol){
	Node* p = new Node;
	pFirst = p;
	p->coef = 0;
	p->deg = 0;
	p->pNext = nullptr;
	Node* pp = pol.pFirst->pNext;
	for (pp; p != nullptr; pp = pp->pNext) {
		p->pNext = new Node;
		p = p->pNext;
		p->coef = pp->coef;
		p->deg = pp->deg;
		p->pNext = nullptr;
	}
}

Polynom::Polynom(pol_string _str){
	Node* p = new Node;
	p->coef = 0;
	p->deg = 0;
	p->pNext = nullptr;
	pFirst = p;
	string s_tmp = _str.GetString() + '+';
	if ((s_tmp[0] != '+') && (s_tmp[0] != '-'))
		s_tmp = '+' + s_tmp;
	int len = s_tmp.length();
	for (int i = 0; i != (len - 1); i++) {
		double k;
		if ((s_tmp[i + 1] != 'x') || (s_tmp[i + 1] != 'y') || (s_tmp[i + 1] != 'z')) {
			string temp;
			int j = s_tmp.find_first_of("xyz+-", i + 1);
			while (j > i) {
				temp = temp + s_tmp[i];
				i++;
			}
			k = stof(temp);
		}
		else {
			if (s_tmp[i] == '+')
				k = 1;
			else k = -1;
			i++;
		}
		int x = 0,
			y = 0,
			z = 0;
		for (int j = 0; j < 3; j++) {
			switch (s_tmp[i]){
			case 'x':
				x = s_tmp[i + 1] - '0';
				i = i + 2;
				break;
			case 'y':
				y = s_tmp[i + 1] - '0';
				i = i + 2;
				break;
			case 'z':
				z = s_tmp[i + 1] - '0';
				i = i + 2;
				break;
			}
		}
		int i_deg = x * 10000 + y * 100 + z;			//xxyyzz
		Insert(k, i_deg);
	}
	Annul();
}

Polynom::~Polynom(){
	while (pFirst != nullptr) {
		Node *p = pFirst;
		pFirst = p->pNext;
		delete p;
	}

}

Polynom & Polynom::operator=(const Polynom & pol){
	if (this != &pol) {
		Node *p = pFirst;
		p = p->pNext;
		pFirst->pNext = nullptr;
		while(p!=nullptr){
			Node* pp = p;
			p = pp->pNext;
			delete pp;
		}
		p = pFirst;
		Node* pp = pol.pFirst->pNext;
		for (pp; pp != nullptr; pp = pp->pNext) {
			p->pNext = new Node;
			p = p->pNext;
			p->coef = pp->coef;
			p->deg = pp->deg;
			p->pNext = nullptr;
		}
	}
	return *this;

	// TODO: вставьте здесь оператор return
}

Polynom Polynom::operator+(const Polynom & pol){
	Polynom tmp(*this);
	tmp = tmp + pol;
	return tmp;
	
}

Polynom Polynom::operator*(const Polynom & pol){
	Polynom tmp;
	Node *p = pFirst->pNext;
	for (p; p != nullptr; p = p->pNext) {
		Node* pp = pol.pFirst->pNext;
		for (pp; p != nullptr; pp = pp->pNext)
			tmp.Insert(p->coef*pp->coef, p->deg*pp->deg);
		tmp.Annul();
		p = p->pNext;
	}
	return tmp;

}

bool Polynom::operator==(const Polynom & pol){
	Node* p = pol.pFirst->pNext,
		*pp = pFirst->pNext;
	while ((p != nullptr) && (pp != nullptr)) {
		if (p->deg != pp->deg) 
			return false;
		else 
			if (p->coef != pp->coef)
				return false;
		p = p->pNext;
		pp = pp->pNext;
	}
	if (((p != nullptr) && (pp == nullptr)) || ((p == nullptr) && (pp != nullptr)))
		return false;
	return true;
}

bool Polynom::operator!=(const Polynom & pol){
	return !(*this == pol);
}

Polynom Polynom::MultByConst(double c){
	Polynom tmp(*this);
	Node* p = tmp.pFirst->pNext;
	for (p; p != nullptr; p = p->pNext)
		p->coef *= c;
	tmp.Annul();
	return tmp;
}

void Polynom::Insert(double _coef, int _deg){
	Node* p = new Node,
		*pp = pFirst;
	p->coef = _coef;
	p->deg = _deg;
	for (pp; pp->pNext != nullptr; pp = pp->pNext) {
		Node* _pp = pp->pNext;
		if (_deg <= _pp->deg) {
			p->pNext = pp->pNext;
			pp->pNext = p;
			break;
		}
	}
	if (pp->pNext == nullptr) {
		pp->pNext = p;
		p->pNext = nullptr;
	}
}

void Polynom::Annul(){
	Node* p = pFirst,
		*pp = p->pNext;
	if (pp != nullptr) {
		while (pp->pNext!=nullptr) {
			if (pp->deg != pp->pNext->deg) {
				if (pp->coef == 0) {
					Node* _pp = pp;
					p->pNext = _pp->pNext;
					pp = pp->pNext;
					delete _pp;
				}
				else {
					p = pp;
					pp = pp->pNext;
				}
			}
			else {
				Node* _pp = pp->pNext;
				pp->coef += _pp->coef;
				pp->pNext = _pp->pNext;
				delete _pp;
			}
		}
		if (pp->coef == 0) {
			p->pNext = nullptr;
			delete pp;
		}
	}
}

void Polynom::Print(){
	Node* p = pFirst;
	p = p->pNext;
	string tmp;
	for (p; p != nullptr; p = p->pNext) {
		int dx = p->deg / 10000,
			dy = (p->deg % 10000) / 100,
			dz = p->deg % 100;
		if (p->coef > 0)
			tmp += "+";
		if ((dx + dy + dz) == 0)
			tmp += to_string(p->coef);
		else {
			if ((p->coef != -1) && (p->coef != 1))
				tmp +=to_string(p->coef);
			else
				if (p->coef == -1)
					tmp += "-";
		}
		if (dx != 0) {
			tmp += "x";
			tmp += to_string(dx);
		}
		if (dy != 0) {
			tmp += "y";
			tmp +=to_string(dy);
		}
		if (dz != 0) {
			tmp += "z";
			tmp += to_string(dz);
		}
	}
	if (tmp.length() == 0)
		tmp = '0';
	if (tmp[0] == '+')
		tmp.erase(0, 1);
	cout << tmp;
}

double Polynom::Calculation(double x, double y, double z){
	double res = 0;
	Node* p = pFirst->pNext;
	for (p; p != nullptr; p = p->pNext) {
		int _x = p->deg / 10000,
			_y = (p->deg % 10000) / 100,
			_z = p->deg % 100;
		double tmp = pow(x, _x)*pow(y, _y)*pow(z, _z);
		res = res + tmp * p->coef;

	}
	return res;
}

bool pol_string::IsCorrect(){
	int len = str.length();
	if (len == 0)
		return false;
	int count = 0,
		sim = 0,
		k[3] = { 0,0,0 },
		f = 0;
	str = str + '+';
	string reasonable = "0123456789.-+xyz";
	if (str[0] == '.')
		return false;
	for (int i = 0; i < len; i++) {
		if (reasonable.find(str[i]) == string::npos)
			return false;
		for (int j = 0; j < 3; j++) {
			if ((str[i] == reasonable[j]) && (f == 0)) {
				if (k[j] == 1)
					return false;
				k[j]++;
				f = 1;
				count = 0;
				sim = 0;
				break;
			}
			if (f == 1) {
				if ((str[i] >= '0') || (str[i])<='9') {
					string tmp = "xyz+-";
					if (tmp.find(str[i + 1]) == string::npos)
						return false;
					else f = 0;
				}
				else return false;
			}
		}
		if ((str[i] == '+') || (str[i] == '-')) {
			if (sim <= 0) {
				k[0] = 0;
				k[1] = 0;
				k[2] = 0;
				sim++;
			}
			else return false;
		}
		if ((str[i] >= '0') && (str[i] <= '9'))
			sim = 0;
		if (str[i] == '.') {
			if (count <= 0)
				if ((str[i - 1] >= '0') || (str[i - 1]) <= '9')
					count++;
				else false;
			else return false;
		}
	}
	if ((str[len - 1] == '+') || (str[len - 1] == '-'))
		return false;
	str.erase(len);
	return true;
}

pol_string::pol_string(string _str){
	if (!IsCorrect())
		throw "ошибка: неверный полином";
	
	int tmp = _str.length();
	for (int i = 0; i < tmp; i++)
		if (_str[i] != ' ')
			str += _str[i];
}
