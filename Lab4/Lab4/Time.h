#pragma once

#include <fstream>
#include "Triad.h"

/*
��������� ���������� ������ � ����������� � �������� � ����. ������ �� ����������� � ������� ������� ��� ��.
https://habr.com/ru/post/546946/
https://habr.com/ru/post/246971/
https://docs.microsoft.com/en-us/cpp/preprocessor/token-pasting-operator-hash-hash?view=msvc-170
������� SET_GET_TIME, ��������� �������� VAL, ������� ��������� � �������� ������� � ��� ���������� � ��� ��.
� ������ ������ ��������� ����� ����:
void set_first(const x) { first = x; }
*/

#define SET_GET_TIME(VAL) \
    int  get_##VAL() const { return VAL; } \
    void set_##VAL(const int x) { VAL = x; }

class Time : public Triad {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    Time(int, int, int);

    //--- Setters and Getters ---
    SET_GET_TIME(hours);
    SET_GET_TIME(minutes);
    SET_GET_TIME(seconds);

    //������ ������������ ������ �������� ������: void foo() = delete;
    //��� �� ������ ���������� ����� ����������, ��� ������ �������.
    int get_first   () = delete;
    int get_second  () = delete;
    int get_third   () = delete;
    void set_first  (int) = delete;
    void set_second (int) = delete;
    void set_third  (int) = delete;

    //Override � �++ �� ���������� ��� ���������������. ������������ ��� ����� �������������
    int FirstAddOne  () override { return (++hours); }
    int SecondAddOne () override { return (++minutes); }
    int ThirdAddOne  () override { return (++seconds); }

    //-- Overloading operators  --
    Time& operator=(const Time&);
    friend std::istream& operator>>(std::istream& in, Time&);
    friend std::ostream& operator<<(std::ostream& out, const Time&);

    //----- Other Functions -----
    void AddMinutes(int);
    void AddSeconds(int);
    void Show() const override;
};
