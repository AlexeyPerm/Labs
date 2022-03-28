#include "Money.h"
#include "iostream"


Money::Money(const Money& m) {
    rubles = m.rubles;
    kopeks = m.kopeks;
}

Money::Money(long r, int k) {
    if (k >= 100) {
        long long tmp = r * 100 + k;
        rubles = static_cast<long> (tmp / 100);
        kopeks = static_cast<int> (tmp % 100);
    } else {
        rubles = r;
        kopeks = k;
    }
}

Money& Money::operator=(const Money& m) {
    if (this == &m) {
        return *this;
    }

    rubles = m.rubles;
    kopeks = m.kopeks;
    return *this;
}

Money Money::operator+(Money m) {
    long long x = rubles * 100 + kopeks;
    long long xm = m.rubles * 100 + m.kopeks;
    x += xm;
    long mTemp1 = static_cast<long> (x / 100);
    long mTemp2 = static_cast<int> (x % 100);
    Money mTemp(mTemp1,mTemp2 );
    return mTemp;
//    rubles = static_cast<long> (tmp / 100);
//    kopeks = static_cast<int> (tmp % 100);

}

ostream& operator<<(ostream& out, const Money& m) {
    cout << m.rubles << ",";
    if (m.kopeks < 10) {
        cout << "0";
    }
    cout << m.kopeks;
    return out;
}

istream& operator>>(istream& in, Money& m) {
    cout << "ruble >";
    in >> m.rubles;
    cout << "kopeks >";
    in >> m.kopeks;
    return in;
}


