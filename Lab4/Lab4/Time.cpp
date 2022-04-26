#include "Time.h"
#include <iostream>
#include <iomanip>

//---------------- Constructors -----------------
Time::Time() : Triad() {
    hours = minutes = seconds = 0;
}

Time::Time(const int h, const int m, const int s) : Triad(h, m, s) {
    this->hours   = h;
    this->minutes = m;
    this->seconds = s;
}

void Time::Show() const {
    //���� �� �������� ������� ������ ��������� ������ setfill() � setw() �� �������� �� ��� ��������.
    std::cout << std::setfill('0') << std::setw(2) << hours << ":";
    std::cout << std::setfill('0') << std::setw(2) << minutes << ":";
    std::cout << std::setfill('0') << std::setw(2) << seconds << std::endl;
}

void Time::AddMinutes(const int value) {
    if (value < 0) {
        std::cout << "������ �������� ������������� �������� �����. ������ �������� AddMinutes() " << std::endl;
        return;
    }
    long totalMinutes{};
    totalMinutes =
            hours * 60 + minutes + value;    //������������ ��������� � long � ����������� �������� ���-�� ����� � �����
    hours   = totalMinutes / 60;
    minutes = totalMinutes % 60;
}

void Time::AddSeconds(const int value) {
    if (value < 0) {
        std::cout << "������ �������� ������������� �������� ������. ������ �������� AddSeconds() " << std::endl;
        return;
    }
    long totalSeconds;
    totalSeconds = hours * 3600 + minutes * 60 + seconds + value;
    hours   = totalSeconds / 3600;
    minutes = totalSeconds / 60 % 60;
    seconds = totalSeconds % 60;
}

//---------------- Overloadings -----------------
Time& Time::operator=(const Time& other) {
    if (&other == this) {
        return *this;
    }
    this->hours   = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
    return *this;
}

std::istream& operator>>(std::istream& in, Time& T) {
    std::string tmp;
    bool flag = false;
    std::cout << "������� ���� \n>";
    in >> tmp;
    while (!Triad::InputValidation(tmp)) {
        std::cout << "�� ���������� ��������. ��������� ���� �����: \n>";
        in >> tmp;
    }
    T.hours = stoi(tmp);
//��� �����, ����� ������ �����������. �� ������ ������� ������ �� ���.
    while (!flag) {
        std::cout << "������� ������ \n>";
        in >> tmp;
        if (Triad::InputValidation(tmp)) {
            T.minutes = stoi(tmp);
            if (T.minutes >= 0 && T.minutes < 60) {
                flag = true;
                break;
            }
            else {
                std::cout << "�� ���������� ��������. ��������� ���� �����: \n>";
                flag = false;
            }
        }
        else {
            std::cout << "�� ���������� ��������. ��������� ���� �����: \n>";
            flag = false;
        }
    }


    flag = false;
    while (!flag) {
        std::cout << "������� ������� \n>";
        in >> tmp;
        if (Triad::InputValidation(tmp)) {
            T.seconds = stoi(tmp);
            if (T.seconds >= 0 && T.seconds < 60) {
                flag = true;
                break;
            }
            else {
                std::cout << "�� ���������� ��������. ��������� ���� ������: \n>";
                flag = false;
            }
        }
        else {
            std::cout << "�� ���������� ��������. ��������� ���� ������: \n>";
            flag = false;
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Time& T) {
    return (out << "Time: " << std::setfill('0') << std::setw(2) << T.hours << ":" << \
        std::setfill('0') << std::setw(2) << T.minutes << ":" << \
        std::setfill('0') << std::setw(2) << T.seconds << std::endl);
}
