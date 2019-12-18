#pragma once
#include <iostream>
#include <clocale>
using namespace std;

void PrintInstraction() {
	cout << "Правила ввода полинома:" << endl;
	cout << "I\t" << "Степени при x, y, z от 0 до 10" << endl;
	cout << "II\t" << "Вводить сточными английскими буквами (нижний английский регистр)" << endl;
	cout << "III\t" << "Степень вводим после знака '^'" << endl;
	cout << "IV\t" << "Дроби вводить через точку (.), а не запятую (,)" << endl;
	cout << "IV\t" << "Пример: 2x^3y^4z^5+6x^7-8z^9" << endl;
	cout << "V\t" << "Для выбора пункта меню введите соответствующую цифру" << endl;
}

void PrintMenu() {
	cout << "\t\tМеню:" << endl;
	cout << "0\tПоказать меню" << endl;//прописан
	cout << "1\tВвести первый полином" << endl;//прописан
	cout << "2\tВвести второй полином" << endl;//прописан
	cout << "3\tСложить полиномы" << endl;//прописан
	cout << "4\tВычесть полиномы" << endl;//прописан
	cout << "5\tУмножение полинома" << endl;//прописан
	cout << "6\tУмножение полинома на константу" << endl;//прописан
	cout << "7\tНайти значение в точке" << endl;//прописан
	cout << "8\tВывести первый полином" << endl;//прописан
	cout << "9\tВывести второй полином" << endl;//прописан
	cout << "10\tЗавершение работы" << endl;
}

void WorkMenu() {
	int point = 11, pointIn = 0,
		x, y, z;
	string pol1="", pol2 = "";
	Polinom pPlus(""), pSub(""), pMult(""), pMultConst("");
	while (point != 10) {
		cin >> point;
		switch (point) {
		default: break;
		case 0: {
			PrintMenu();
			break; 
		}
		case 1: {
			cout << "Введите первый полином: ";
			cin >> pol1;
			cout << endl;
			break;
		}
		case 2: {
			cout << "Введите второй полином: ";
			cin >> pol2;
			cout << endl;
			break;
		}

		case 3: {
			cout << "Сложение полиномов:" << endl;
			Polinom tmp1(pol1),
				tmp2(pol2);
			pPlus = tmp1 + tmp2;
			cout << pPlus.GetPolinom() << endl;
			break;
		}
		case 4: {
			cout << "Разность полиномов:" << endl;
			cout << "Из какого полинома вычитать второй?" << endl;
			cout << "1. Из первого" << endl;
			cout << "2. Из второго" << endl;
			cin >> pointIn;
			switch (pointIn) {
			case 1: {
				Polinom tmp1(pol1),
					tmp2(pol2);
				pSub = tmp1 - tmp2;
				cout << pSub.GetPolinom() << endl;
				break;
			}
			case 2: {
				Polinom tmp1(pol1),
					tmp2(pol2);
				pSub = tmp2 - tmp1;
				cout << pSub.GetPolinom() << endl;
				break;
			}
			}
			break;
		}
		case 5: {
			cout << "Произведение полиномов:" << endl;
			Polinom tmp1(pol1),
				tmp2(pol2);
			pMult = tmp1 * tmp2;
			cout << pMult.GetPolinom() << endl;
			break;
		}
		case 6: {
			cout << "Произведение полиномов на константу:" << endl;
			cout << "Какой плином умножать?:" << endl;
			cout << "1. Первый" << endl;
			cout << "2. Второй" << endl;
			cin >> pointIn;
			int C;
			cout << "Введите константу: ";
			cin >> C;
			cout << endl;
			switch (pointIn) {
			case 1: {
				Polinom tmp(pol1);
				pMultConst = tmp*C;
				cout << pMultConst.GetPolinom() << endl;
				break;
			}
			case 2: {
				Polinom tmp(pol2);
				pMultConst = tmp * C;
				cout << pMultConst.GetPolinom() << endl;
				break;
			}
			}
			break;
		}
		case 7: {
			cout << "Вычисление полинома в точке:" << endl;
			cout << "Какой полином нужно выбрать для вычисления значения в точке?" << endl;
			cout << "1. Первый" << endl;
			cout << "2. Второй" << endl;
			cin >> pointIn;
			cout << "Введите значения x, y, z" << endl;
			cin >> x >> y >> z;
			switch (pointIn) {
			case 1: {
				Polinom tmp(pol1);
				cout << "Значение полинома в точке (" << x << ',' << y << ',' << z << ") = "<<tmp.Calculation(x,y,z)<<endl;
				break;
			}
			case 2: {
				Polinom tmp(pol2);
				cout << "Значение полинома в точке (" << x << ',' << y << ',' << z << ") = " << tmp.Calculation(x, y, z) << endl;
				break;
			}
			}
			break;

		}
		case 8: {
			cout << "Первый полином:" <<pol1<< endl;
			break;
		}
		case 9: {
			cout << "Второй полином:" << pol2<<endl;
			break;
		}
		
		}
	}
}