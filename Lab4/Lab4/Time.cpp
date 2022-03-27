#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;

//---------------- Constructors -----------------

Time::Time() {
	hours = minutes = seconds = 0;
}

Time::Time(int h, int m, int s) : Triad(h, m, s) {
	this->hours = h;
	this->minutes = m;
	this->seconds = s;
}

int Time::FirstAddOne() {
	return (++hours);
}

int Time::SecondAddOne() {
	return (++minutes);
}

int Time::ThirdAddOne() {
	return (++seconds);
}

void Time::Show() const {
	//пока не придумал способа задать параметры вывода setfill() и setw() на единожды на все значения. 
	cout << setfill('0') << setw(2) << hours << ":";
	cout << setfill('0') << setw(2) << minutes << ":";
	cout << setfill('0') << setw(2) << seconds << endl;
}

void Time::AddMinutes(int value) {
	if (value < 0) {
		cout << "Нельзя добавить отрицательное значение минут. Отмена операции AddMinutes() " << endl;
		return;
	}
	long totalMinutes{};
	totalMinutes = hours * 60 + minutes + value;	//преобразумем выражение в long и высчитываем значения кол-во минут в часах
	hours = totalMinutes / 60;
	minutes = totalMinutes % 60;
}

void Time::AddSeconds(int value) {
	if (value < 0) {
		cout << "Нельзя добавить отрицательное значение секунд. Отмена операции AddSeconds() " << endl;
		return;
	}
	long totalSeconds{};
	totalSeconds = static_cast <long> (hours * 3600 + minutes * 60 + seconds + value);
	hours = totalSeconds / 3600;
	minutes = totalSeconds / 60 % 60;
	seconds = totalSeconds % 60;
}

//---------------- Overloadings -----------------
Time &Time::operator=(const Time &other) {
	if (&other == this) {
		return *this;
	}
	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
	return *this;
}

istream &operator>>(istream &in, Time &T) {
	string tmp;
	bool flag = false;
	cout << "Введите часы \n>";
	in >> tmp;
	while (!Triad::InputValidation(tmp)) {
		cout << "Не корректное значение. Повторите ввод часов: \n>";
		in >> tmp;
	}
	T.hours = stoi(tmp);
//Это очень, очень плохая конструкция. Но мозгов хватило только на это.
	while (!flag) {
		cout << "Введите минуты \n>";
		in >> tmp;
		if (Triad::InputValidation(tmp)) {
			T.minutes = stoi(tmp);
			if (T.minutes >= 0 && T.minutes < 60) {
				flag = true;
				break;
			}
			else {
				cout << "Не корректное значение. Повторите ввод минут: \n>";
				flag = false;
			}
		}
		else {
			cout << "Не корректное значение. Повторите ввод минут: \n>";
			flag = false;
		}
	}


	flag = false;
	while (!flag) {
		cout << "Введите секунды \n>";
		in >> tmp;
		if (Triad::InputValidation(tmp)) {
			T.seconds = stoi(tmp);
			if (T.seconds >= 0 && T.seconds < 60) {
				flag = true;
				break;
			}
			else {
				cout << "Не корректное значение. Повторите ввод секунд: \n>";
				flag = false;
			}
		}
		else {
			cout << "Не корректное значение. Повторите ввод секунд: \n>";
			flag = false;
		}
	}

	return in;
}

ostream &operator << (ostream &out, const Time &T) {
	return (out << "Time: " << setfill('0') << setw(2) << T.hours << ":" << \
		setfill('0') << setw(2) << T.minutes << ":" << \
		setfill('0') << setw(2) << T.seconds << endl);
}
