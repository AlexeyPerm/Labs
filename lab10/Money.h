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
    Money& operator++();
    Money operator++(int);
    Money& operator=(const Money&);
    bool operator<(const Money&) const;
    bool operator>(const Money&) const;

// --------------------------- Getters ----------------------------- //
    long getRubles() const { return rubles; }
// --------------------------- Setters ----------------------------- //
    void setRubles(const long& r) { rubles = r; }

    friend std::fstream& operator>>(std::fstream&, Money&);
    friend std::istream& operator>>(std::istream&, Money&);
    friend std::ostream& operator<<(std::ostream&, const Money&);
    friend std::fstream& operator<<(std::fstream&, const Money&);

private:
    long rubles;
    int kopeks;
};


