#include <iostream>
using namespace std;

void f(double, double);
void f(int, int, int, int);

int main() {
	f(1000.11, 999.01);
	cout << endl;
	f(17, 19, 22, 64);
	return 0;
}

void f(int a, int b, int c, int d) {
	cout << a << "/" << b << " - " << c << "/" << d << " = ";
	cout << (a * d - b * c) << "/" << (b * d);
}

void f(double a, double b) {
	cout << a << " - " << b << " = " << a - b;
}