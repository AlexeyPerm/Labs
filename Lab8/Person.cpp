#include "Person.h"
#include <iostream>
#include <algorithm>
#include <string>

// ------------------------- Constructors -------------------------- //
Person::Person(const std::string& name, const int age) {
    this->name = name;
    this->age = age;
}

Person::Person(const Person& p) {
    name = p.name;
    age = p.age;
}

Person::~Person() = default;

// --------------------- Overridden Functions ---------------------- //

void Person::Show() {
    std::cout << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}

void Person::Input() {
    std::cout << "Name> ";
    std::cin >> name;

    std::string tmp;    //временная переменная для хранения введённых числовых значений
    std::cout << "Name> ";
    std::cin >> tmp;
    while (!CheckCorrectInput(tmp)) {
        std::cout << "\nIncorrect input. Try again\n";
        std::cout << "Name> ";
        std::cin >> tmp;
    }
    name = stoi(tmp);
}

// --------------------------- Setters ----------------------------- //
void Person::SetName(const std::string& n) {
    name = n;
}

void Person::SetAge(const int& a) {
    age = a;
}

// --------------------- Overloaded Functions ---------------------- //

Person& Person::operator=(Person& p) {
    if (this == &p) {
        return *this;
    }
    name = p.name;
    age = p.age;
    return *this;
}


bool Person::CheckCorrectInput(std::string& tmp) {
    if (!(all_of(tmp.begin(), tmp.end(), isdigit))) {
        return false;
    }
    try {
        stoi(tmp);
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << " invalid_argument";
        return false;
    }
    catch (const std::out_of_range& e) {
        std::cout << e.what() << " out_of_range";
        return false;
    }
    if (stoi(tmp) <= 0) {
        return false;
    }
    return true;
}



