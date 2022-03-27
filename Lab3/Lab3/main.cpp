#include "money.h"
//#define DEBUG


int main() {
	setlocale(LC_ALL, "ru");
#ifndef DEBUG
	cout << endl << "=================== Конструктор по умолчанию. Параметры обнулены ===================" << endl << endl;
	Money zero;
	cout << "Экземпляр класса: \"zero\"."<< endl;
	zero.show();
	cout << endl << "Используем сеттеры для изменения значений: " << endl;
	cout << "zero.set_ruble(19)" << endl << "zero.set_kopeks(44);" << endl << endl;
	zero.set_ruble(19);
	zero.set_kopeks(44);
	zero.show();
	cout << endl << "Используем геттеры для получения значений: " << endl;
	cout << "zero.get_ruble();" << endl << "zero.get_kopeks();" << endl;
	cout << zero.get_ruble() << endl;
	cout << zero.get_kopeks();

	cout << endl << "===================== Конструктор с параметрами =====================" << endl << endl;
	Money first(66, 99);
	cout << "Money first(66, 99);" << endl;
	cout << "Экземпляр класса: \"first\"." << endl;
	first.show();

	cout << endl << "===================== Перегруженые операторы ввода и вывода =====================" << endl << endl;
	Money second;
	cout << "Экземпляр класса: \"second\"."<< endl;
	cin >> second;
	cout << second;

	cout << endl << "===================== Перегруженые операторы присваивания =====================" << endl << endl;
	Money third;
	cout << "\"third\" = \"second\"." << endl;
	cout << "Экземпляр класса: \"third\" присваивает значения экземпляра \"second\"."<< endl;
	third = second;
	third.show();

	cout << endl << "===================== Перегруженые оператор префиксного инкремента =====================" << endl << endl;
	cout << "До применения префиксного инкремента:" << endl;
	zero.set_ruble(-1);
	zero.set_kopeks(0);
	zero.show();
	cout << "После применения префиксного инкремента:" << endl;
	++zero;
	zero.show();
	cout << endl;
	cout << "До применения префиксного инкремента:" << endl;
	zero.set_ruble(1);
	zero.set_kopeks(99);
	zero.show();
	cout << "После применения постфиксного инкремента:" << endl;
	zero++;
	zero.show();

	cout << endl << "===================== Перегруженые операторы сравнения > и < =====================" << endl << endl;
	cout << "Первый объект: " << zero;
	cout << "Второй объект: " << second;
	if (zero > second) {
		cout << "Первый объект больше второго: true ";
	}
	else {
		cout << "Первый объект больше второго: false ";
	}

	cout << endl << "===================== Перегруженые операторы сравнения > и < =====================" << endl << endl;
	cout << "Первый объект: " << zero;
	cout << "Второй объект: " << second;
	if (zero < second) {
		cout << "Первый объект меньше второго: true ";
	}
	else {
		cout << "Первый объект меньше второго: false ";
	}

#endif // DEBUG

#ifdef DEBUG
	Money x(1,2);
	x.show();
	
#endif // DEBUG


	return 0;
	}