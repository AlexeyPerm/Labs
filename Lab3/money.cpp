#include "Money.h"
#include <iostream>

// ------------------------- Constructors -------------------------- //
Money::Money(const long r, const int k) {
    if (k >= 100) {
        long long tmp = r * 100 + k;
        rubles = static_cast<long> (tmp / 100);
        kopeks = static_cast<int>  (tmp % 100);
    }
    else {
        rubles = r;
        kopeks = k;
    }
}

Money::Money(const Money& m) {
    rubles = m.rubles;
    kopeks = m.kopeks;
}

// --------------------- Overloaded Functions ---------------------- //
Money& Money::operator=(const Money& rhs) {
    if (this == &rhs) {
        return *this;
    }
    rubles = rhs.rubles;
    kopeks = rhs.kopeks;
    return *this;
}

bool Money::operator<(const Money& rhs) const {
    return rubles < rhs.rubles || (rubles == rhs.rubles && kopeks < rhs.kopeks);
}

bool Money::operator>(const Money& rhs) const {
    return rubles > rhs.rubles || (rubles == rhs.rubles && kopeks > rhs.kopeks);
}

std::ostream& operator<<(std::ostream& out, const Money& m) {
    std::cout << m.rubles << ",";
    if (m.kopeks < 10) {
        std::cout << "0";
    }
    std::cout << m.kopeks;
    return out;
}

std::istream& operator>>(std::istream& in, Money& m) {
    std::cout << "Rubles>";
    in >> m.rubles;
    std::cout << "Kopecks>";
    in >> m.kopeks;
    if (m.kopeks >= 100) {
        long long tmp = static_cast<long long> (m.rubles * 100) + m.kopeks;
        m.rubles = static_cast<long> (tmp / 100);
        m.kopeks = static_cast<int> (tmp % 100);
    }
    return in;
}

Money& Money::operator++() {
    long long tmp = rubles * 100 + kopeks;
    tmp++;
    rubles = static_cast<long> (tmp / 100);
    kopeks = static_cast<int> (tmp % 100);
    return *this;
}

Money Money::operator++(int) {
    long long tmp = rubles * 100 + kopeks;
    tmp++;
    Money m(rubles, kopeks);
    rubles = static_cast<long> (tmp / 100);
    kopeks = static_cast<int> (tmp % 100);
    return m;
}

void Money::print() const {
    std::cout << rubles << ",";
    if (kopeks < 10) {
        std::cout << "0";
    }
    std::cout << kopeks;
}