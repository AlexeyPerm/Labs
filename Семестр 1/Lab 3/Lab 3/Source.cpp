#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	int k(10), n(20);
	double a(0.1), b(1.0);
	double eps(0.0001);
	double step = (b - a) / k; //��� ��������� x �� �������
	double y, x;

	//x = a, ��� ��� ������ ��� ��� a = 0.1. ����� x ���������� �� �������� step = 0.9
	for (x = a; x <= b; x += step) {
		y = cos(sin(x)) * pow(M_E, cos(x)); //����������� ������ �������� �������

		//����������� �������� SN
		double SN = 1.0;    //� ������ ��������� ���������� �������� SN = 1.
		unsigned int fact_n(1);        //� ������ ��������� ���������� �������� ���������� ����� n � 1.
		for (int i = 1; i <= n; i++) {
			fact_n *= i;
			SN += cos(x * i) / fact_n;
		}

		//����������� �������� SE       
		fact_n = 1;         //� ������ ��������� ���������� �������� ���������� ����� n � 1.
		int j = 1;
		double tempValue(1.0), SE(1.0);
		while (fabs(tempValue) > eps) {
			fact_n *= j;
			tempValue = cos(x * j) / fact_n;
			SE += tempValue;
			j++;
		}

		std::cout << std::fixed << std::setprecision(2) <<  //��� ������� x � ����� ��������� ������ 2 ����� ����� �������
			"X=" << x << '\t' << std::setprecision(8) <<     //��� ������� ������������ �������� � ����� ��������� 8 ���� ����� �������
			"SN=" << SN << '\t' <<
			"SE=" << SE << '\t' <<
			"Y=" << y << std::endl;
	}
	return 0;
}