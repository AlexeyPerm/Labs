#pragma once

#include <fstream>

class Money {
public:
// ------------------------- Constructors -------------------------- //
    Money() { rubles = 0, kopeks = 0; }
    Money(long, int);
    Money(const Money&);
    ~Money() = default;
// ---------------------- Getters / Setters ------------------------ //
    long getRubles() const { return rubles; }
    int getKopeks()  const { return kopeks; }
    void setRubles(const long r) { rubles = r; }
    void setKopeks(const int  k) { kopeks = k; }
// --------------------- Overloaded Functions ---------------------- //
    Money& operator=(const Money& rhs);
    Money& operator=(const int& n);   //конвертируем число в объект класса
    Money operator+(const Money& rhs) const;
    Money& operator+=(const Money& rhs);
    Money operator-(const Money& rhs) const;
    Money& operator-=(const Money& rhs);
    Money operator/(const int& n) const;
    bool operator<(const Money& rhs) const; 
	bool operator>(const Money& rhs) const;
    bool operator==(const Money& rhs) const;

    friend std::istream& operator>>(std::istream&, Money&);
    friend std::ostream& operator<<(std::ostream&, const Money&);

private:
    int kopeks;
    long rubles;
};