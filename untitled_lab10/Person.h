#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Person {
public:
// ------------------------- Constructors -------------------------- //
    Person() { name = "", age = 0; };

    Person(std::string name, int age) : name(name), age(age) {};

    Person(const Person& p) { name = p.name, age = p.age; }

    ~Person() = default;
// --------------------- Overloaded Functions ---------------------- //

    Person& operator=(const Person&);
    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend std::istream& operator>>(std::istream&, Person&);
    friend std::fstream & operator << (std::fstream&, const Person&);
    friend std::fstream & operator >> (std::fstream&, Person&);
private:
    std::string name;
    int age;
};
