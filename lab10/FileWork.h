#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>

int makeFile(const char* fName)
{
    std::fstream stream(fName, std::ios::out | std::ios::trunc);
    if (!stream)
    {      //Ошибка при открытии файла
        return -1;
    }
    int n;  //количество записываемых объектов Money;
    std::cout << "Enter the number of Money> ";
    std::cin >> n;
    Money money;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> money;
        stream << money << "\n";
    }
    stream.close();
    return n;
}

int printFile(const char* fName)
{
    std::fstream stream(fName, std::ios::in);
    if (!stream)
    {
        return -1;
    }
    Money money;
    int i = 0;
    while (stream >> money)
    {
        std::cout << money << std::endl;
        i++;
    }
    stream.close();
    return i;

}

int removeObjectFromFile(const char* fName, const int& k)
{
    std::fstream tmp("temp", std::ios::out);
    std::fstream stream(fName, std::ios::in);
    if (!stream)
    {
        return -1;
    }
    int i = 0;  //номер считываемого элемента
    Money money;
    while (stream >> money)
    {
        if (stream.eof())
        {
            break;
        }
        i++;
        if (i != k)
        {
            tmp << money;
        }
    }
    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
    return i;
}

int addObjectToFile(const char* fName, const int& k, const Money& newMoney)
{
    std::fstream tmp("temp", std::ios::out);        //запись
    std::fstream stream(fName, std::ios::in);       //чтение
    if (!stream)
    {
        return -1;
    }
    Money money;
    int i = 0;  //номер считываемого элемента
    int l = 0;  //количество добавленных элементов
    while (stream >> money)
    {
        if (stream.eof())
        {
            break;
        }
        ++i;
        if (i == k)
        {
            tmp << newMoney;
            ++l;
        }
        tmp << money;
    }
    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
    return l;
}

int addObjectToEndFile(const char* fName, Money& money)
{
    std::fstream stream(fName, std::ios::app);
    if (!stream)
    {
        return -1;
    }
    stream << money;
    return 1;
}

int changeFileInStream(const char* fName, const int& k, const Money& tmpMoney)
{
    std::fstream tmp("temp", std::ios::out);
    std::fstream stream(fName, std::ios::in);
    if (!stream)
    {
        return -1;
    }
    Money money;
    int i = 0;  //номер изменяемой записи
    int l = 0;
    while (stream >> money)
    {
        if (stream.eof())
        {
            tmp << money;
            break;
        }
        ++i;
        if (i == k)
        {
            tmp << tmpMoney;
        } else
        {
            tmp << money;
        }
    }
    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
    return l;
}

int removeObjectsGreaterThanValue(const char* fName, const long value)
{
    std::fstream tmp("temp", std::ios::out);        //запись
    std::fstream stream(fName, std::ios::in);       //чтение
    if (!stream)
    {
        return -1;
    }
    Money money;
    int i = 0;  //номер изменяемой записи
    while (stream >> money)
    {
        if (stream.eof())
        {
            break;
        }
        if (money.getRubles() < value ){
            tmp << money;
        }
    }

    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
        

    return 1;
}