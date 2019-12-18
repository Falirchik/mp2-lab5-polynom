#pragma once
#include <iostream>
#include <clocale>
using namespace std;

void PrintInstraction() {
	cout << "������� ����� ��������:" << endl;
	cout << "I\t" << "������� ��� x, y, z �� 0 �� 10" << endl;
	cout << "II\t" << "������� �������� ����������� ������� (������ ���������� �������)" << endl;
	cout << "III\t" << "������� ������ ����� ����� '^'" << endl;
	cout << "IV\t" << "����� ������� ����� ����� (.), � �� ������� (,)" << endl;
	cout << "IV\t" << "������: 2x^3y^4z^5+6x^7-8z^9" << endl;
	cout << "V\t" << "��� ������ ������ ���� ������� ��������������� �����" << endl;
}

void PrintMenu() {
	cout << "\t\t����:" << endl;
	cout << "0\t�������� ����" << endl;//��������
	cout << "1\t������ ������ �������" << endl;//��������
	cout << "2\t������ ������ �������" << endl;//��������
	cout << "3\t������� ��������" << endl;//��������
	cout << "4\t������� ��������" << endl;//��������
	cout << "5\t��������� ��������" << endl;//��������
	cout << "6\t��������� �������� �� ���������" << endl;//��������
	cout << "7\t����� �������� � �����" << endl;//��������
	cout << "8\t������� ������ �������" << endl;//��������
	cout << "9\t������� ������ �������" << endl;//��������
	cout << "10\t���������� ������" << endl;
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
			cout << "������� ������ �������: ";
			cin >> pol1;
			cout << endl;
			break;
		}
		case 2: {
			cout << "������� ������ �������: ";
			cin >> pol2;
			cout << endl;
			break;
		}

		case 3: {
			cout << "�������� ���������:" << endl;
			Polinom tmp1(pol1),
				tmp2(pol2);
			pPlus = tmp1 + tmp2;
			cout << pPlus.GetPolinom() << endl;
			break;
		}
		case 4: {
			cout << "�������� ���������:" << endl;
			cout << "�� ������ �������� �������� ������?" << endl;
			cout << "1. �� �������" << endl;
			cout << "2. �� �������" << endl;
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
			cout << "������������ ���������:" << endl;
			Polinom tmp1(pol1),
				tmp2(pol2);
			pMult = tmp1 * tmp2;
			cout << pMult.GetPolinom() << endl;
			break;
		}
		case 6: {
			cout << "������������ ��������� �� ���������:" << endl;
			cout << "����� ������ ��������?:" << endl;
			cout << "1. ������" << endl;
			cout << "2. ������" << endl;
			cin >> pointIn;
			int C;
			cout << "������� ���������: ";
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
			cout << "���������� �������� � �����:" << endl;
			cout << "����� ������� ����� ������� ��� ���������� �������� � �����?" << endl;
			cout << "1. ������" << endl;
			cout << "2. ������" << endl;
			cin >> pointIn;
			cout << "������� �������� x, y, z" << endl;
			cin >> x >> y >> z;
			switch (pointIn) {
			case 1: {
				Polinom tmp(pol1);
				cout << "�������� �������� � ����� (" << x << ',' << y << ',' << z << ") = "<<tmp.Calculation(x,y,z)<<endl;
				break;
			}
			case 2: {
				Polinom tmp(pol2);
				cout << "�������� �������� � ����� (" << x << ',' << y << ',' << z << ") = " << tmp.Calculation(x, y, z) << endl;
				break;
			}
			}
			break;

		}
		case 8: {
			cout << "������ �������:" <<pol1<< endl;
			break;
		}
		case 9: {
			cout << "������ �������:" << pol2<<endl;
			break;
		}
		
		}
	}
}