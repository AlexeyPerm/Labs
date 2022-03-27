#include <cmath>
#include <iostream>
using namespace std;

// cos(x) - x^3 = 0

double f(double z) {
	return pow(cos(z), 1.0 / 3);
}

int main() {
	setlocale(LC_ALL, "rus");
	int iterCount = 1;
	double x = 1.0, eps = 0.0001;
	x = f(x);
	cout << "Номер итерации: " << iterCount << ",  x(" << iterCount << ") = "  << x << endl;
	while (fabs(x - f(x)) >= eps) {
		x = f(x);
		++iterCount;
		cout << "Номер итерации: " << iterCount << ",  x(" << iterCount << ") = " << x << endl;
	}
	cout << endl << "========= Результат вычислений методом итераций =========" << endl;
	cout << "Заданная точность: " << eps << endl;
	cout << "x = " << x << endl;
	cout << "Количество итераций: " << iterCount << endl;

	return 0;
}