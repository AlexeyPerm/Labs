#pragma once

#include <fstream>

class Money {
public:
// ------------------------- Constructors -------------------------- //
    Money() { rubles = 0, kopeks = 0; }
    Money(long, int);
    Money(const Money&);
    ~Money() = default;
// --------------------- Overloaded Functions ---------------------- //
    Money& operator=(const Money& rhs);
    Money& operator=(const int& n);   //конвертируем число в объект класса
    bool operator<(const Money& rhs) const;
    Money operator+(const Money& rhs) const;
    Money& operator+=(const Money& rhs);
    Money operator-(const Money& rhs) const;
    Money& operator-=(const Money& rhs);
    Money operator/(const int& n) const;
// --------------------- Overloaded Functions ---------------------- //
    friend std::istream& operator>>(std::istream&, Money&);
    friend std::ostream& operator<<(std::ostream&, const Money&);

private:
    int kopeks;
    long rubles;
};