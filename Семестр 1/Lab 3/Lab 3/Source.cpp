#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	int k(10), n(20);
	double a(0.1), b(1.0);
	double eps(0.0001);
	double step = (b - a) / k; //шаг аргумента x из услови€
	double y, x;

	//x = a, так как первый шаг при a = 0.1. ƒалее x измен€етс€ на значение step = 0.9
	for (x = a; x <= b; x += step) {
		y = cos(sin(x)) * pow(M_E, cos(x)); //¬ысчитываем точное значение функции

		//¬ысчитываем значение SN
		double SN = 1.0;    //с каждой итерацией возвращаем значение SN = 1.
		unsigned int fact_n(1);        //с каждой итерацией возвращаем значение факториала числа n в 1.
		for (int i = 1; i <= n; i++) {
			fact_n *= i;
			SN += cos(x * i) / fact_n;
		}

		//¬ысчитываем значение SE       
		fact_n = 1;         //с каждой итерацией возвращаем значение факториала числа n в 1.
		int j = 1;
		double tempValue(1.0), SE(1.0);
		while (fabs(tempValue) > eps) {
			fact_n *= j;
			tempValue = cos(x * j) / fact_n;
			SE += tempValue;
			j++;
		}

		std::cout << std::fixed << std::setprecision(2) <<  //дл€ каждого x в цикле выводитс€ только 2 цифры после зап€той
			"X=" << x << '\t' << std::setprecision(8) <<     //дл€ каждого последующего значени€ в цикле выводитс€ 8 цифр после зап€той
			"SN=" << SN << '\t' <<
			"SE=" << SE << '\t' <<
			"Y=" << y << std::endl;
	}
	return 0;
}