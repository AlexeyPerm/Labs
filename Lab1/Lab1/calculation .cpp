#include "calculation.h"
using namespace std;


bool calculation::CheckCorrectInput(const std::string &input) const{
	if (input[0] == '-') {	//Проверка на ввод отриц. числа.
		cout << "Введёное значение должно быть больше нуля: \n> ";
		return false;
	}

	//std::count возвращает кол-во символов (точек) в введёной строке. Использую std:: на всякий случай, 
	//так как в main.cpp используется переменная с именемем count.
	if (std::count(input.begin(), input.end(), '.') > 1) {
		cout << "Некорректное значение. Повторите ввод: \n> ";
		return false;
	}

	//static_cast<int> - преобразование типа. Читал в книге, что это более безопасно, чем int (value).
	//Преобразование используется, потому что компилятор ругается на несоответствие типов, так как
	//length() возвращает size_t (Павловская. стр. 237). Использую, потому что интересно, что будет. 
	for (int i = 0; i < static_cast<int> (input.length()); i++) {
		if (!(isdigit(input[i]) || input[i] == '.')) {
			cout << "Некорректное значение. Повторите ввод: \n> ";
			return false;
		}
	}

	return true;
}

bool calculation::CheckCorrectInput(const double F, const int S, const int D) const {
	if (F < 0) {
		cout << "Не корректное значение оклада.\n";
		return false;
	}
	else if (D < 0 || D > 31 || D < 28) {
		cout << "Не корректное значение количества рабочих дней \n";
		return false;
	}
	else if (D < 0 || S > D) {
		cout << "Не корректное значение дней месяца ";
		return false;
	}
	return true;
}

void calculation::Show() const {
	cout << "Salary = " << first << endl;
	cout << "Working Days = " << second << endl;
	cout << "Days in Month = " << daysInMonth << endl;
}

void calculation::Read() {
	//Если включается русская локализация, то разделителем дробной и целой части должна быть запятая, а не точка. 
	//Из-за этого stod() обнуляет дробную часть. Поэтому переводим нумерацию в англ. вариант, где разделителем является точка. 
	setlocale(LC_NUMERIC, "eng");
	cout << "Оклад: \n> ";
	string a{};
	cin >> a;
	while (!CheckCorrectInput(a)) {
		cin >> a;
	}
	first = stod(a);
	//calculation::daysInMonth = 0;

	string b{};	//second. Количество отработанных дней
	string c{};	//daysInMonth
	bool correctInput = false;	//флаг проверки корректности ввода. 

	while (!correctInput) {

		cout << "Количество отработанных дней: \n> ";
		cin >> b;
		while (!CheckCorrectInput(b)) {
			cin >> b;
		}
		second = stoi(b);

		cout << "Количество дней в месяце: \n> ";
		cin >> c;
		while (!CheckCorrectInput(c)) {
			cin >> c;
		}
		daysInMonth = stoi(c);

		if (second > daysInMonth) {
			cout << "Количество отработанных дней не может быть больше количества дней в месяце. Повторите ввод.\n";
		}
		else if (daysInMonth > 31 || daysInMonth < 28) {
			cout << "Не корректное значение количества дней в месяце. Повторите ввод\n";
		}
		else {
			correctInput = true;
		}
	}
}

void calculation::Init(const double F, const int S, int const daysInMonth) {
	if (CheckCorrectInput(F, S, daysInMonth)) {
		first = F;
		second = S;
		calculation::daysInMonth = daysInMonth;
	}
	else {	//В условии задания, если функция make_calculation() принимает ошибочные параметры, то программа выводит сообщения и завершает работу
		cout << "\nExit...\n";
		exit(0);
	}
}

double calculation::summa() const {
	return first / daysInMonth * second;
}
