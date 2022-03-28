#pragma once

#include "istream"

using namespace std;

class Money {
public:
    Money() = default;

    Money(long r, int k);

    Money(const Money&);

    Money operator+(Money);

    Money& operator=(const Money&);

    friend ostream& operator<<(ostream&, const Money&);

    friend istream& operator>>(istream&, Money&);

private:
    long rubles;
    int kopeks;
};


