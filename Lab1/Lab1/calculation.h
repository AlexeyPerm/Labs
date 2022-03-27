#pragma once
#include <iostream>
#include <iomanip>	//setprecision
#include <string>	//string
#include <algorithm>	//count

struct calculation {
private:
	double first{};	//Оклад
	int second{};	//Количество рабочий дней
	int daysInMonth = 31;	//Количество дней в месяце
	//Рекомендуется описывать как константные те методы, которые предназначены для получения значение полей. Павловская. стр. 181
	bool CheckCorrectInput(const std::string &) const;
	bool CheckCorrectInput(const double, const int, const int) const;

public:
	double summa() const;	//название метода согласно задания. 
	void Show() const;
	void Read();
	void Init(const double, const int, int);
};