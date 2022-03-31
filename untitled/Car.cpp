#include "Car.h"
#include <iostream>

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
    std::cout;
    std::cout << "Mark: " << mark << std::endl;
    std::cout << "Cylinders: " << cyl << std::endl;
    std::cout << "Power: " << power << std::endl;
}

Car::~Car() = default;


void Car::Input() {
    std::cout << "Mark> ";
    std::cin >> mark;
    std::cout << "Cylinders> ";
    std::cin >> cyl;
    std::cout << "Power> ";
    std::cin >> power;
}

void Car::HandleEvent(const TEvent& e) {
    if(e.what == evMessage){
        switch (e.command) {
            case cmGet:{
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

