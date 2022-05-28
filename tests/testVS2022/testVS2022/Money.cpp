#include "Money.h"
#include <iostream>
using namespace std;

//���������� �������� ������������
Money& Money::operator =(const Money& t)
{
	//�������� �� ����������������
	if (&t == this) return *this;
	rub = t.rub;
	kop = t.kop;
	return *this;
}
//���������� �������� ���������
bool Money::operator==(const Money& t) const
{
	return rub == t.rub && kop == t.kop;
}
//���������� ����������� �������� �����������
bool Money::operator!=(const Money& t) const
{
	return rub != t.rub && kop != t.kop;
}
//���������� �������� ������
bool Money::operator> (const Money& t) const
{
	return rub > t.rub || rub == t.rub && kop > t.kop;
}
//���������� �������� ������
bool Money::operator< (const Money& t) const
{
	return rub < t.rub || rub == t.rub && kop < t.kop;
}
//���������� �������� ��������
Money Money::operator+(const Money& t) const
{
	long temp1 = rub * 100 + kop;
	long temp2 = t.rub * 100 + t.kop;
	Money m;
	m.rub = (temp1 + temp2) / 100;
	m.kop = (temp1 + temp2) % 100;
	return m;
}
//���������� �������� �������
Money Money::operator/(int n) const
{
	long temp1 = rub * 100 + kop;
	temp1 = temp1 / n;
	Money m;
	m.rub = temp1 / 100;
	m.kop = temp1 % 100;
	return m;
}
//���������� �������� ���������
Money Money::operator*(const Money& t) const
{
	long temp1 = rub * 100 + kop;
	long temp2 = t.rub * 100 + t.kop;
	Money m;
	m.rub = (temp1 * temp2) / 10000;
	m.kop = (temp1 * temp2) % 10000 / 100;
	return m;
}
//���������� ���������� �������-�������� �����
istream& operator >>(istream& in, Money& t)
{
	cout << "rub? "; in >> t.rub;
	long temp1, temp2;
	cout << "kop? "; in >> temp2;
	//�������� ����� ������������, ���� ���� ����� 100 ������ - ������� � �����
	if (temp2 >= 100)
	{
		temp1 = temp2 / 100;
		t.rub += temp1;
		t.kop = temp2 % 100;
	}
	else t.kop = temp2;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator << (ostream& out, const Money& t)
{
	return (out << t.rub << "," << t.kop);
}