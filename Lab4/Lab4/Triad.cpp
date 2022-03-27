#include "Triad.h"
#include <algorithm>	//all_of()
#include <iostream>
using namespace std;

//---------------- Constructors -----------------
Triad::Triad() {
	first = second = third = 0;
}

Triad::Triad(int first, int second, int third) {
	this->first  = first;
	this->second = second;
	this->third  = third;
}

Triad::Triad(const Triad &T) {
	first  = T.first;
	second = T.second;
	third  = T.third;
}


//------------------- Setters -----------------
void Triad::set_first(const int f) {
	first = f;
}

void Triad::set_second(const int s) {
	second = s;
}

void Triad::set_third(const int t) {
	third = t;
}

//------------------- Getters -------------------
int Triad::get_first() const {
	return first;
}

int Triad::get_second() const {
	return second;
}

int Triad::get_third() const {
	return third;
}

//---------------- Overloadings -----------------
Triad &Triad::operator=(const Triad &other) {
	if (&other == this) {
		return *this;
	}
	this->first  = other.first;
	this->second = other.second;
	this->third  = other.third;
	return *this;
}

ostream &operator<<(ostream &out, const Triad &T) {
	return (out << "first = " << T.first << ", second = " << T.second << ", third = " << T.third << endl);
}

istream &operator >> (istream &in, Triad &T) {
	string tmp;
	cout << "Введите first \n>";
	in >> tmp;
	while (!Triad::InputValidation(tmp)) {
		cout << "Не корректное значение. Повторите ввод first: \n>";
		in >> tmp;
	}
	T.first = stoi(tmp);

	cout << "Введите second \n>";
	in >> tmp;
	while (!Triad::InputValidation(tmp)) {
		cout << "Не корректное значение. Повторите ввод second: \n>";
		in >> tmp;
	}
	T.second = stoi(tmp);

	cout << "Введите third \n>";
	in >> tmp;
	while (!Triad::InputValidation(tmp)) {
		cout << "Не корректное значение. Повторите ввод third: \n>";
		in >> tmp;
	}
	T.third = stoi(tmp);

	return in;
}

//--------------- Other functions ---------------
void Triad::Show() const {
	cout << "first = " << first << ", second = " << second << ", third = " << third << endl;
}

int Triad::FirstAddOne() {
	return (++first);
}

int Triad::SecondAddOne() {
	return (++second);
}

int Triad::ThirdAddOne() {
	return (++third);
}

bool Triad::InputValidation(const string &s) {
	if (s[0] == '-' || !(all_of(s.begin(), s.end(), isdigit))) {
			return false;
	}
	try {
		int tmp = stoi(s);
	}
	catch (const invalid_argument &e) {
		cout << e.what() << "\nНекорректное значение.";
		return false;
	}
	catch (const out_of_range &e) {
		cout << e.what() << "\nВведите число поменьше.";
		return false;
	}
	return true;
}