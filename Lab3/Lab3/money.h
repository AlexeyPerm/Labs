#pragma once
#include <iostream>
#include <string>
#include <algorithm>	//replace()
#include <iomanip>	//setw(), setfill()
#include <fstream>	//istream(), ostream()
using namespace std;

class Money {
private:
	long ruble{};	//Рубли
	int kopeks{};	//Копейки
	long double totalRubleAndKopeks{};
	
public:
	Money();	//Конструктор по умолчанию
	Money(const long, const int);	//Конструктор с параметрами
	Money(const Money &);	//Конструктор копирования
	~Money() {};	//Деструктор
	void show() const;

	//--------- Setters ---------
	void set_ruble(const long);
	void set_kopeks(const int);

	//--------- Getters ---------
	long get_ruble()  const;
	int  get_kopeks() const;

	//-- Operators overloading --
	bool   operator < (const Money &) const;
	bool   operator > (const Money &) const;
	Money &operator ++ ();
	Money  operator ++ (int);
	Money &operator = (const Money &);

	//---- Friend Functions -----
	friend istream &operator >> (istream &, Money &);
	friend ostream &operator << (ostream &, Money &);
	friend bool CorrectInput(string &, const string &, Money &);
	friend void ConvertRubleAndKopeksToTotal(Money &);	//объединяем рубли и копейки. Для примера выходе получим: 100,40 р. или -23,03 р.
};

