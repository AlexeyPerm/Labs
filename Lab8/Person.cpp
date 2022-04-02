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
    std::cout << "Age> ";
    std::cin >> tmp;
    while (!CheckCorrectInput(tmp)) {
        std::cout << "\nIncorrect input. Try again\n";
        std::cout << "Age> ";
        std::cin >> tmp;
    }
    age = std::stoi(tmp);
}

void Person::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        switch (e.command) {
            case cmGet: {
                std::cout << "Name = " << GetName() << std::endl;
            }
        }
    }
}

// --------------------- Overloaded Functions ---------------------- //

Person& Person::operator=(const Person& p) {
    if (this == &p) {
        return *this;
    }
    name = p.name;
    age = p.age;
    return *this;
}


bool Person::CheckCorrectInput(std::string& tmp, bool isInt) {
    //Индусский код
    if (isInt) {
        if (!(std::all_of(tmp.begin(), tmp.end(), isdigit))) {
            return false;
        }
        try {
            std::stoi(tmp);
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << " invalid_argument";
            return false;
        }
        catch (const std::out_of_range& e) {
            std::cout << e.what() << " out_of_range";
            return false;
        }
        if (std::stoi(tmp) <= 0) {
            return false;
        }
    } else {
        try {
            std::stod(tmp);
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << " invalid_argument";
            return false;
        }
        catch (const std::out_of_range& e) {
            std::cout << e.what() << " out_of_range";
            return false;
        }
        if (std::stod(tmp) <= 0) {
            return false;
        }
    }
    return true;
}




