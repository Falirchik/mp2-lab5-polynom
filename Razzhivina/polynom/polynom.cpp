#include "polynom.h"


Polynom::Polynom(string _pol){
}

Polynom::~Polynom(){
}

bool Polynom::IsOperand(char op){
	return false;
}

bool Polynom::IsOperatin(char op){
	return false;
}

Polynom Polynom::operator+(Polynom & pol){
	return Polynom();
}

Polynom Polynom::operator-(Polynom & pol){
	return Polynom();
}

Polynom & Polynom::operator=(Polynom & pol){
	// TODO: вставьте здесь оператор return
}

void Polynom::PolynomINString(){
}

void Polynom::FillPolinom(){
}

int Polynom::Const(string tmp){
	return 0;
}
