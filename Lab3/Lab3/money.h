#pragma once
#include <iostream>
#include <string>

#include <fstream>	//istream(), ostream()

class Money {
private:
	long rubles{};	//Рубли
	int kopeks{};	//Копейки
	long double totalRubleAndKopeks{};
	
public:
	Money();	//Конструктор по умолчанию
	Money(long, int);	//Конструктор с параметрами
	Money(const Money &);	//Конструктор копирования
	~Money() {};	//Деструктор
	void show() const;

	//--------- Setters ---------
	void set_ruble(long);
	void set_kopeks(int);

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
	friend std::istream &operator >> (std::istream &, Money &);
	friend std::ostream &operator << (std::ostream &, const Money &);
	friend bool CorrectInput(std::string &, const std::string &, Money &);
	friend void ConvertRubleAndKopeksToTotal(Money &);	//Объединяем рубли и копейки. Для примера выходе получим: 100,40 р. или -23,03 р.
};

