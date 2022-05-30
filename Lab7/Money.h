#pragma once

#include <fstream>

class Money {
public:
// ------------------------- Constructors -------------------------- //
    Money() { rubles = 0, kopeks = 0; }
    Money(long r, int k);
    Money(const Money&);
    ~Money() = default;
// ---------------------- Getters / Setters ------------------------ //
    long getRubles() const { return rubles; }
    int  getKopeks() const { return kopeks; }
    void setRubles(const long r) { rubles = r; }
    void setKopeks(const int  k)  { kopeks = k; }
// --------------------- Overloaded Functions ---------------------- //
    Money& operator=(const Money& rhs);
    bool operator<(const Money& rhs) const;
    bool operator>(const Money& rhs) const;
    Money& operator++();
    Money  operator++(int);
    Money  operator+(const Money&) const;

    friend std::istream& operator>>(std::istream& in, Money& m);
    friend std::ostream& operator<<(std::ostream& out, const Money& m);

    void print() const;

private:
    int  kopeks;
    long rubles;
};