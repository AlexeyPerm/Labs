#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>

int makeFile(const char* fName)
{
    std::fstream stream(fName, std::ios::out | std::ios::trunc);
    if (!stream)
    {
        return -1;  //Ошибка при открытии файла
    }
    int n;          //количество записываемых объектов Money;
    std::cout << "Enter the number of objects> ";
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
    int i = 0;      //номер считываемого элемента
    int l = 0;      //количество добавленных элементов
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
            ++l;
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

int removeObjectsGreaterThanValue(const char* fName, const long& value)
{
    std::fstream tmp("temp", std::ios::out);        //запись
    std::fstream stream(fName, std::ios::in);       //чтение
    if (!stream)
    {
        return -1;
    }
    Money money;
    int l = 0;      //количество внесённых изменений
    while (stream >> money)
    {
        if (stream.eof())
        {
            if (money.getRubles() < value)
            {
                tmp << money;
                ++l;
            }
            break;
        }
        if (money.getRubles() < value)
        {
            tmp << money;
            ++l;
        }
    }
    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
    return l;
}

int halfObjectInFileByValue()
{


    return 1;
}

int addMultipleObjectsInFiles(const char* fName, const int& elementsCount, const int& elemIndex)
{
    std::fstream tmp("temp", std::ios::out);        //запись
    std::fstream stream(fName, std::ios::in);       //чтение
    if (!stream)
    {
        return -1;
    }
    int i = 0;  //счётчик элементов
    int l = 0;
    Money m;
    while (stream >> m)
    {
        if (stream.eof())
        {
            break;
        }
        ++i;
        if (i == elemIndex)
        {
            for (int j = 0; j < elementsCount; ++j)
            {
                std::cin >> m;
                tmp << m;
                ++l;
            }
        }
        tmp << m;

    }
    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
    return l;

}
