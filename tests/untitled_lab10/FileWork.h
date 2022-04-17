#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>

int makeFile(const char* fName)
{
    std::fstream stream(fName, std::ios::out | std::ios::trunc);
    if (!stream) {      //Ошибка при открытии файла
        return -1;
    }

    int n;  //количество записываемых объектов Person;
    std::cout << "Enter the number of person> ";
    std::cin >> n;
    Person p;
    for (int i = 0; i < n; ++i) {
        std::cin >> p;
        stream << p << "\n";
    }
    stream.close();
    return n;
}

int printFile(const char* fName)
{
    std::fstream stream(fName, std::ios::in);
    if (!stream) {
        return -1;
    }
    Person p;
    int i = 0;
    while (stream >> p) {
        std::cout << p << std::endl;
        i++;
    }
    stream.close();
    return i;
}

int delObjectFromFile(const char* fName, const int& k)
{
    std::fstream tmp("temp", std::ios::out);
    std::fstream stream(fName, std::ios::in);
    if (!stream) {
        return -1;
    }
    int i = 0;  //номер считываемого элемента
    Person p;
    while (stream >> p) {
        if (stream.eof()) {
            break;
        }
        i++;
        if (i!=k) {
            tmp << p;
        }
    }
    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
    return i;
}

int addObjectToFile(const char* fName, const int& k, const Person& pp)
{
    std::fstream tmp("temp", std::ios::out);        //запись
    std::fstream stream(fName, std::ios::in);       //чтение
    if (!stream) {
        return -1;
    }

    Person p;
    int i = 0;  //номер считываемого элемента
    int l = 0;  //количество добавленных элементов
    while (stream >> p) {
        if (stream.eof()) {
            break;
        }
        ++i;
        if (i==k) {
            tmp << pp;
            ++l;
        }
        tmp << p;
    }
    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
    return l;
}

int addObjectToEndFile(const char* fName, Person& p)
{
    std::fstream stream(fName, std::ios::app);
    if (!stream) {
        return -1;
    }
    stream << p;
    return 1;
}

int changeFileInStream(const char* fName, const int& k, const Person& tempPerson)
{
    std::fstream tmp("temp", std::ios::out);
    std::fstream stream(fName, std::ios::in);
    if (!stream) {
        return -1;
    }
    Person p;
    int i = 0;  //номер изменяемой записи
    int l = 0;
    while (stream >> p) {
        if (stream.eof()) {
            tmp << p;
            break;
        }
        ++i;
        if (i==k) {
            tmp << tempPerson;
            l++;
        }
        else {
            tmp << p;
        }
    }
    stream.close();
    tmp.close();
    remove(fName);
    rename("temp", fName);
    return l;
}