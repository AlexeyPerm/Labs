#include "Money.h"
#include <iostream>

// ------------------------- Constructors -------------------------- //

Money::Money(const long r, const int k) {
    if (k >= 100) {
        long long tmp = r * 100 + k;
        rubles = static_cast<long> (tmp / 100);
        kopeks = static_cast<int> (tmp % 100);
    } else {
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
//    long long lhsTmp = rubles * 100 + kopeks;
//    long long rhsTmp = rhs.rubles * 100 + rhs.kopeks;
//    return lhsTmp < rhsTmp;
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

Money Money::operator+(const Money& rhs) const {
    Money m;
    if ((kopeks + rhs.kopeks) >= 100) {
        m.rubles = rubles + rhs.rubles + 1;
        m.kopeks = (kopeks + rhs.kopeks) % 100;
    } else {
        m.rubles = rubles + rhs.rubles;
        m.kopeks = kopeks + rhs.kopeks;
    }
    return m;
}

Money& Money::operator+=(const Money& rhs) {
    if ((kopeks + rhs.kopeks) >= 100) {
        rubles = rubles + rhs.rubles + 1;
        kopeks = (kopeks + rhs.kopeks) % 100;
    } else {
        rubles = rubles + rhs.rubles;
        kopeks = kopeks + rhs.kopeks;
    }
    return *this;
}


Money Money::operator-(const Money& rhs) const {
    Money m;
    if ((kopeks - rhs.kopeks) < 0) {
        m.rubles = rubles - rhs.rubles - 1;
        m.kopeks = 100 + (kopeks - rhs.kopeks);
    } else {
        m.rubles = rubles - rhs.rubles;
        m.kopeks = kopeks - rhs.kopeks;
    };
    return m;
}

Money& Money::operator-=(const Money& rhs) {
    if ((kopeks - rhs.kopeks) < 0) {
        rubles = rubles - rhs.rubles - 1;
        kopeks = 100 + (kopeks - rhs.kopeks);
    } else {
        rubles = rubles - rhs.rubles;
        kopeks = kopeks - rhs.kopeks;
    };
    return *this;
}

Money Money::operator/(const int& n) const {
    long long tmp = (static_cast<long long> (rubles * 100) + kopeks) / n;
    Money m;
    m.rubles = static_cast<long> (tmp / 100);
    m.kopeks = static_cast<int> (tmp % 100);
    return m;
}

Money& Money::operator=(const int& n) {
    long long tmp = static_cast<long long> (rubles * 100) + kopeks + n;
    rubles = static_cast<long> (tmp / 100);
    kopeks = static_cast<int> (tmp % 100);
    return *this;
}
bool Money::operator==(const Money& rhs) const {
    return (rubles == rhs.rubles && kopeks == rhs.kopeks);
}
