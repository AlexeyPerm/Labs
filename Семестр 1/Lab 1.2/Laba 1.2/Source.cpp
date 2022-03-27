#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	double n, m, nn, mm;

	cout << "Введите число n и m: \n";
	cin >> nn >> mm;

	n = nn; 
	m = mm;
	cout << "Результат выражения n---m = " << (n---m) << endl;

	n = nn;
	m = mm;
	cout << "Результат выражения m-- < n = " << (m-- < n) << endl; 

	n = nn;
	m = mm;
	cout << "Результат выражения n++ > m = " << (n++ > m) << endl;

	return 0;
}