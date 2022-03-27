#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	//�������� ���������
	return cos(x) - pow(x, 3);
}

double f1(double x) {
	//������ �����������
	return -sin(x) - 3 * pow(x, 2);
}
double f2(double x) {
	//������ �����������. ����� ��� �������� ������� �� ���������� ������� f(x) * f2(x) > 0;
	//�� ������������, ��� ��� ���� ��� �������������. 
	return -cos(x) - 6 * x;
}

int main() {
	//������ ����� ��������� ����� �� ���������� [0;3].
	setlocale(LC_ALL, "rus");
	double x = 3, eps = 1E-4;
	int iterCount = 0;
	do {
 		x = x - (f(x)) / (f1(x));
		++iterCount;
	cout << "����� ��������: " << iterCount << ",  x(" << iterCount << ") = " << x << endl;
	} while (fabs(f(x)) >= eps);

	cout << endl << endl << "========= ��������� ���������� ������� ������� =========" << endl;
	cout << "�������� ��������: " << eps << endl;
	cout << "x = " << x << endl;
	cout << "���������� ��������: " << iterCount << endl;

	return 0;
}