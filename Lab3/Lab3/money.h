#pragma once
#include <iostream>
#include <string>

#include <fstream>	//istream(), ostream()

class Money {
private:
	long rubles{};	//�����
	int kopeks{};	//�������
	long double totalRubleAndKopeks{};
	
public:
	Money();	//����������� �� ���������
	Money(long, int);	//����������� � �����������
	Money(const Money &);	//����������� �����������
	~Money() {};	//����������
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
	friend void ConvertRubleAndKopeksToTotal(Money &);	//���������� ����� � �������. ��� ������� ������ �������: 100,40 �. ��� -23,03 �.
};

