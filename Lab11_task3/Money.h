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
    Money& operator=(const Money&);
    Money& operator=(const int&);   //присваиваем объекту число.
    bool operator<(const Money& rhs) const;
//    bool operator>(const Money& rhs) const;
    Money operator+(const Money& rhs) const;
//    Money operator/(const Money& rhs) const;
    Money operator/(const int&) const;
// ---------------------- Getters / Setters ------------------------ //
//    int getKopeks() const { return kopeks; }
//    long getRubles() const { return rubles; }
//    void setKopeks(const int& k) { kopeks = k; }
//    void setRubles(const long& r) { rubles = r; }
// --------------------- Overloaded Functions ---------------------- //
    friend std::istream& operator>>(std::istream&, Money&);
    friend std::ostream& operator<<(std::ostream&, const Money&);

private:
    int kopeks;
    long rubles;
};