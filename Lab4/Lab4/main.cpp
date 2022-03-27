#include "Triad.h"
#include "Time.h"
#include <iostream>
using namespace std;

void F1(Triad &);
Triad F2();

int main() {
	setlocale(LC_CTYPE, "rus");
	
	// ----------- Операция ввода ------------
	Time t1;
	cin >> t1;
	cout << t1;

	// ------ Конструктор с параметрами ------
	cout << endl << "===================== Конструктор с параметрами =====================" << endl << endl;
	Time t2(32665, 43, 2);
	t2.Show();


	// -------- Операция присваивания --------
	cout << endl << "====== Операция присваивания с последующим выводом на экран. ========" << endl << endl;
	cout << "Создаётся объект класса Time и ему присваиваются значения\nсозданного ранее класса:" << endl;
	Time t3;
	t3 = t2;
	cout << t3;

	// -------- Операция подстановки ---------
	cout << endl << "============================ Подстановка ============================" << endl << endl;
	F1(t2);
	Triad triad;
	triad = F2();
	cout << triad;

	return 0;
}

void F1(Triad &t) {
	t.set_first(999);
	cout << t;
}

Triad F2() {
	Time t(213, 5, 32);
	return t;
}
