#pragma once

#include <fstream>

class Money
{
public:
// ------------------------- Constructors -------------------------- //
    Money() = default;
    Money(long, int);
    Money(const Money&);
    ~Money() = default;
// --------------------- Overloaded Functions ---------------------- //
    Money& operator++();
    Money operator++(int);
    Money& operator=(const Money&);
    bool operator<(const Money&) const;
    bool operator>(const Money&) const;
    
    friend std::istream& operator>>(std::istream&, Money&);
    friend std::ostream& operator<<(std::ostream&, const Money&);
private:
    long rubles;
    int kopeks;
};


