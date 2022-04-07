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

Money& Money::operator=(const Money& m) {
    if (this == &m) {
        return *this;
    }

    rubles = m.rubles;
    kopeks = m.kopeks;
    return *this;
}

Money& Money::operator++() {
    ++kopeks;
    if (kopeks >= 100) {
        long long tmp = rubles * 100 + kopeks;
        rubles = static_cast<long> (tmp / 100);
        kopeks = static_cast<int> (tmp % 100);
    }
    return *this;
}

Money Money::operator++(int) {
    Money tmp(*this);
    this->kopeks++;
    return tmp;
}

bool Money::operator<(const Money& rhs) const {
    long long lhsTmp = rubles * 100 + kopeks;
    long long rhsTmp = rhs.rubles * 100 + rhs.kopeks;
    return lhsTmp < rhsTmp;
}

bool Money::operator>(const Money& rhs) const {
    long long lhsTmp = rubles * 100 + kopeks;
    long long rhsTmp = rhs.rubles * 100 + rhs.kopeks;
    return lhsTmp > rhsTmp;
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

std::fstream& operator>>(std::fstream& fin, Money& m) {
    fin >> m.rubles;
    fin >> m.kopeks;
    return fin;
}

std::fstream& operator<<(std::fstream& fout, const Money& m) {
    fout << m.rubles << std::endl;
    fout << m.kopeks << std::endl;
    return fout;
}