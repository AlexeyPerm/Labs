#pragma once

#include <fstream>
#include <string>

class Triad {
protected:
    int first;
    int second;
    int third;
    static bool InputValidation(const std::string&);

public:
    Triad() { first = second = third = 0; }    //Конструктор по умолчанию
    Triad(int f, int s, int t) : first(f), second(s), third(t) {};    //Конструктор с параметрами
    Triad(const Triad&);    //Конструктор копирования
    ~Triad() = default;    //Деструктор
    virtual void Show() const;

    //--------- Setters ---------

    void set_first(int f) { first = f; }
    void set_second(int s) { second = s; }
    void set_third(int t) { third = t; }

    //--------- Getters ---------

    int get_first() const { return first; }
    int get_second() const { return second; }
    int get_third() const { return third; }

    //-- Operators overloading --
    Triad& operator=(const Triad&);
    friend std::ostream& operator<<(std::ostream& out, const Triad&);
    friend std::istream& operator>>(std::istream& in, Triad&);

    //----- Other Functions -----
    virtual int FirstAddOne() { return (++first); }
    virtual int SecondAddOne() { return (++second); }
    virtual int ThirdAddOne() { return (++third); }
};