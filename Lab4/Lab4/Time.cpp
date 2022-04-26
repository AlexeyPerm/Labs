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
    //пока не придумал способа задать параметры вывода setfill() и setw() на единожды на все значения.
    std::cout << std::setfill('0') << std::setw(2) << hours << ":";
    std::cout << std::setfill('0') << std::setw(2) << minutes << ":";
    std::cout << std::setfill('0') << std::setw(2) << seconds << std::endl;
}

void Time::AddMinutes(const int value) {
    if (value < 0) {
        std::cout << "Нельзя добавить отрицательное значение минут. Отмена операции AddMinutes() " << std::endl;
        return;
    }
    long totalMinutes{};
    totalMinutes =
            hours * 60 + minutes + value;    //преобразумем выражение в long и высчитываем значения кол-во минут в часах
    hours   = totalMinutes / 60;
    minutes = totalMinutes % 60;
}

void Time::AddSeconds(const int value) {
    if (value < 0) {
        std::cout << "Нельзя добавить отрицательное значение секунд. Отмена операции AddSeconds() " << std::endl;
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
    std::cout << "Введите часы \n>";
    in >> tmp;
    while (!Triad::InputValidation(tmp)) {
        std::cout << "Не корректное значение. Повторите ввод часов: \n>";
        in >> tmp;
    }
    T.hours = stoi(tmp);
//Это очень, очень плохая конструкция. Но мозгов хватило только на это.
    while (!flag) {
        std::cout << "Введите минуты \n>";
        in >> tmp;
        if (Triad::InputValidation(tmp)) {
            T.minutes = stoi(tmp);
            if (T.minutes >= 0 && T.minutes < 60) {
                flag = true;
                break;
            }
            else {
                std::cout << "Не корректное значение. Повторите ввод минут: \n>";
                flag = false;
            }
        }
        else {
            std::cout << "Не корректное значение. Повторите ввод минут: \n>";
            flag = false;
        }
    }


    flag = false;
    while (!flag) {
        std::cout << "Введите секунды \n>";
        in >> tmp;
        if (Triad::InputValidation(tmp)) {
            T.seconds = stoi(tmp);
            if (T.seconds >= 0 && T.seconds < 60) {
                flag = true;
                break;
            }
            else {
                std::cout << "Не корректное значение. Повторите ввод секунд: \n>";
                flag = false;
            }
        }
        else {
            std::cout << "Не корректное значение. Повторите ввод секунд: \n>";
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
