#include "Time.h"
#include <iostream>

// --------------------- Overloaded Functions ---------------------- //
Time& Time::operator=(const Time& rhs) {
    if (this == &rhs) {
        return *this;
    }
    min = rhs.min;
    sec = rhs.sec;
    return *this;
}

std::istream& operator>>(std::istream& in, Time& t) {
    std::cout << "Minutes: ";
    in >> t.min;
    std::cout << "Seconds: ";
    in >> t.sec;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    if (t.min < 10) {
        out << "0";
    }
    out << t.min << ":";
    if (t.sec < 10) {
        out << "0";
    }
    out << t.sec;
    return out;
}

bool Time::operator<(const Time& rhs) const {
    if (min < rhs.min) {
        return true;
    }
    if (min == rhs.min && sec < rhs.sec) {
        return true;
    }
    return false;
}

bool Time::operator>(const Time& rhs) const {
    if (min > rhs.min) {
        return true;
    }
    if (min == rhs.min && sec > rhs.sec) {
        return true;
    }
    return false;
}
Time Time::operator+(const Time& rhs) const {
    int temp1 = min * 60 + sec;
    int temp2 = rhs.min * 60 + rhs.sec;
    Time t;
    t.min = (temp1 + temp2) / 60;
    t.sec = (temp1 + temp2) % 60;
    return t;
}
Time Time::operator/(const Time& rhs) const {
    int temp1 = min * 60 + sec;
    int temp2 = rhs.min * 60 + rhs.sec;
    Time t;
    t.min = (temp1 / temp2) / 60;
    t.sec = (temp1 / temp2) % 60;
    return t;
}
Time Time::operator/(const int& rhs) const {
    int temp1 = min * 60 + sec;
    Time t;
    t.min = (temp1 / rhs) / 60;
    t.sec = (temp1 / rhs) % 60;
    return t;
}
