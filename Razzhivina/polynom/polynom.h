#pragma once

#include <string>
#include <iostream>


using namespace std;
 
struct Node {
	Node *pNext;
	double coef;										//�����������
	int deg;											//�������
};

class Pol_str {
	string str;											//������ �������
public:
	Pol_str(string _str);				
	bool IsCorrect();									//�������� �� ������������
	string GetString()const { return str; };			//�������� ������
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

	Polynom MultByConst(double c);						//��������� �� ���������

	void Insert(double coef, int deg);
	void Annul();
	void Print();

	double Calculation(double x, double y, double z);

};

