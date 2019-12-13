#include "polynom.h"

int main() {
	PrintInstruction();
	string tmp;
	double res;
	Polynom resulr;
	try {
		cout << "Введите полином: ";
		cin >>tmp;
		pol_string str_1(tmp);
		Polynom pol1(str_1);
		cout << endl;

		cout << "Введите полином для сложения: ";
		cin >> tmp;
		pol_string str_2(tmp);
		Polynom pol2(str_2);
		resulr = pol1 + pol2;
		resulr.Print();

		cout << endl;
		cout << "Введите полином для умножения: ";
		cin >> tmp;
		pol_string str_3(tmp);
		Polynom pol3(str_3);
		resulr = pol1 * pol3;
		resulr.Print();
		
		double c;
		cout << endl;
		cout << "Введите константу для умножения: ";
		cin >> c;
		resulr = pol1.MultByConst(c);
		resulr.Print();

		double x, y, z;
		cout << endl;
		cout << "Введите значение x, y, z: ";
		cin >> x >> y >> z;
		res = pol1.Calculation(x, y, z);
	}

	catch (const char*str) {
		cout << str << endl;
	}
	system("pause");
	return 0;
}