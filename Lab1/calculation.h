#pragma once
#include <string>    //string

struct calculation
{
public:
    double summa() const;    //название метода согласно заданию.
    void Show() const;
    void Read();
    void Init(double, int, int);

private:
    double first{};    //Оклад
    int second{};    //Количество рабочий дней
    int daysInMonth = 31;    //Количество дней в месяце
    //Рекомендуется описывать как константные те методы, которые предназначены для получения
    //значение полей. Павловская. стр. 181
    static bool CheckCorrectInput(const std::string&);
    static bool CheckCorrectInput(double, int, int);
};