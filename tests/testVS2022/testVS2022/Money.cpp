#include "Money.h"
#include <iostream>
using namespace std;

//перегрузка операции присваивания
Money& Money::operator =(const Money& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	rub = t.rub;
	kop = t.kop;
	return *this;
}
//перегрузка операции равенства
bool Money::operator==(const Money& t) const
{
	return rub == t.rub && kop == t.kop;
}
//перегрузка постфиксной операции неравенства
bool Money::operator!=(const Money& t) const
{
	return rub != t.rub && kop != t.kop;
}
//перегрузка операции больше
bool Money::operator> (const Money& t) const
{
	return rub > t.rub || rub == t.rub && kop > t.kop;
}
//перегрузка операции меньше
bool Money::operator< (const Money& t) const
{
	return rub < t.rub || rub == t.rub && kop < t.kop;
}
//перегрузка операции сложения
Money Money::operator+(const Money& t) const
{
	long temp1 = rub * 100 + kop;
	long temp2 = t.rub * 100 + t.kop;
	Money m;
	m.rub = (temp1 + temp2) / 100;
	m.kop = (temp1 + temp2) % 100;
	return m;
}
//перегрузка операции деления
Money Money::operator/(int n) const
{
	long temp1 = rub * 100 + kop;
	temp1 = temp1 / n;
	Money m;
	m.rub = temp1 / 100;
	m.kop = temp1 % 100;
	return m;
}
//перегрузка операции умножения
Money Money::operator*(const Money& t) const
{
	long temp1 = rub * 100 + kop;
	long temp2 = t.rub * 100 + t.kop;
	Money m;
	m.rub = (temp1 * temp2) / 10000;
	m.kop = (temp1 * temp2) % 10000 / 100;
	return m;
}
//перегрузка глобальной функции-операции ввода
istream& operator >>(istream& in, Money& t)
{
	cout << "rub? "; in >> t.rub;
	long temp1, temp2;
	cout << "kop? "; in >> temp2;
	//проверка ввода пользователя, если ввел более 100 копеек - перевод в рубли
	if (temp2 >= 100)
	{
		temp1 = temp2 / 100;
		t.rub += temp1;
		t.kop = temp2 % 100;
	}
	else t.kop = temp2;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator << (ostream& out, const Money& t)
{
	return (out << t.rub << "," << t.kop);
}