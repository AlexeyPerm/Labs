#include <iostream>
#include <cmath>
using namespace std;

//Вычислить выражение при а=100, b=0.001,
//((a - b)^4-(a^4 - 4a^3b + 6a^2b^2))/(b^4 - 4ab^3)

int main() {
	setlocale(LC_ALL, "Ru");
	float a = 100.0, b = 0.001, resultFloat;
	float numeratorFloat, denominatorFloat;

	numeratorFloat = (pow((a - b), 4) - (pow(a, 4) - 4 * pow(a, 3) * b + 6 * pow(a, 2) * pow(b, 2)));
	denominatorFloat = (pow(b, 4) - 4 * a * pow(b, 3));
	resultFloat = numeratorFloat / denominatorFloat;

	double a_dbl(100.0), b_dbl(0.001), resultDouble;
	double numeratorDouble, denominatorDouble;

	numeratorDouble = (pow((a_dbl - b_dbl), 4) - (pow(a_dbl, 4) - 4 * pow(a_dbl, 3) * b_dbl + 6 * pow(a_dbl, 2) * pow(b_dbl, 2)));
	denominatorDouble = (pow(b_dbl, 4) - 4 * a_dbl * pow(b_dbl, 3));
	resultDouble = numeratorDouble / denominatorDouble;

	cout << "Результат выражения при типе данных float:  " << resultFloat << endl;
	cout << "Результат выражения при типе данных double: " << resultDouble << endl;

	return 0;
}