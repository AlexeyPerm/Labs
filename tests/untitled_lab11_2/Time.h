#pragma once

#include <fstream>

class Time {
public:
// ------------------------- Constructors -------------------------- //
    Time() { min = 0, sec = 0; }
    Time(int m, int s) { min = m, sec = s; }
    Time(const Time& t) { min = t.min, sec = t.sec; }
    ~Time() = default;
// ---------------------- Getters / Setters ------------------------ //
    int getMin() const { return min; }
    int getSec() const { return sec; }
    void setMin(const int m) { this->min = m; }
    void setSec(const int s) { this->sec = s; }
// --------------------- Overloaded Functions ---------------------- //

    bool operator<(const Time& rhs) const;
    bool operator>(const Time& rhs) const;
    Time operator+(const Time& rhs) const;
    Time& operator=(const Time&);
    Time operator/(const int&) const;
    Time operator/(const Time& rhs) const;

    friend std::istream& operator>>(std::istream&, Time&);
    friend std::ostream& operator<<(std::ostream&, const Time&);

private:
    int min;
    int sec;
};
