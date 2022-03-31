#include "Car.h"
#include <iostream>
#include <string>
#include <algorithm>

// ------------------------- Constructors -------------------------- //
Car::Car() {
    mark = "";
    cyl = 0;
    power = 0;
}

Car::Car(const std::string& m, const int c, const int p) : mark(m), cyl(c), power(p) {};

Car::Car(const Car& car) {
    mark = car.mark;
    cyl = car.cyl;
    power = car.power;
}

// --------------------- Overridden Functions ---------------------- //
void Car::Show() {
    std::cout << std::endl;
    std::cout << "Mark: " << mark << std::endl;
    std::cout << "Cylinders: " << cyl << std::endl;
    std::cout << "Power: " << power << std::endl;
}

Car::~Car() = default;


void Car::Input() {
    std::cout << "Mark> ";
    std::cin >> mark;

    std::string tmp;    //временная переменная для хранения введённых числовых значений
    std::cout << "Cylinders> ";
    std::cin >> tmp;
    while (!CheckCorrectInput(tmp)) {
        std::cout << "\nIncorrect input. Try again\n";
        std::cout << "Cylinders> ";
        std::cin >> tmp;
    }
    cyl = stoi(tmp);

    std::cout << "Power> ";
    std::cin >> tmp;
    while (!CheckCorrectInput(tmp)) {
        std::cout << "\nIncorrect input. Try again\n";
        std::cout << "Power> ";
        std::cin >> tmp;
    }
    power = stoi(tmp);
}

void Car::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        switch (e.command) {
            case cmGet: {
                std::cout << "Mark = " << GetMark() << std::endl;
            }
        }
    }
}

// --------------------- Overloaded Functions ---------------------- //
Car& Car::operator=(const Car& car) {
    if (this == &car) {
        return *this;
    }
    mark = car.mark;
    cyl = car.cyl;
    power = car.power;
    return *this;
}

bool Car::CheckCorrectInput(std::string& tmp) {
    if(!(all_of(tmp.begin(), tmp.end(), isdigit))){
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

