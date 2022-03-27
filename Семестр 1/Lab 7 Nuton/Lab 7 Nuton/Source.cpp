#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	//Исходное уравнение
	return cos(x) - pow(x, 3);
}

double f1(double x) {
	//Первая производная
	return -sin(x) - 3 * pow(x, 2);
}
double f2(double x) {
	//Вторая производная. Нужна для проверки условия на сходимость функции f(x) * f2(x) > 0;
	//Не используется, так как пока нет необходимости. 
	return -cos(x) - 6 * x;
}

int main() {
	//Искать корни уравнения будем на промежутке [0;3].
	setlocale(LC_ALL, "rus");
	double x = 3, eps = 1E-4;
	int iterCount = 0;
	do {
 		x = x - (f(x)) / (f1(x));
		++iterCount;
	cout << "Номер итерации: " << iterCount << ",  x(" << iterCount << ") = " << x << endl;
	} while (fabs(f(x)) >= eps);

	cout << endl << endl << "========= Результат вычислений методом Ньютона =========" << endl;
	cout << "Заданная точность: " << eps << endl;
	cout << "x = " << x << endl;
	cout << "Количество итераций: " << iterCount << endl;

	return 0;
}