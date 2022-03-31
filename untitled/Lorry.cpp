#include "Lorry.h"
#include <iostream>

// ------------------------- Constructors -------------------------- //
Lorry::Lorry(const std::string M, const int C, const int P, const int L) : Car(M, C, P) {
    load = L;
}

Lorry::Lorry(const Lorry& lorry) : Car(lorry) {    //делегируем конструктор для исключения дублирования кода.
    load = lorry.load;
}

// --------------------- Overridden Functions ---------------------- //
void Lorry::Show() {
    Car::Show();
    std::cout << "Load: " << load << std::endl;
}

void Lorry::Input() {
    Car::Input();
    std::cout << "Load> ";
    std::cin >> load;
}

Lorry& Lorry::operator=(const Lorry& lorry) {
    if (this == &lorry) {
        return *this;
    }
    mark = lorry.mark;
    cyl = lorry.cyl;
    power = lorry.power;
    load = lorry.load;
    return *this;
}

// --------------------- Overloaded Functions ---------------------- //

