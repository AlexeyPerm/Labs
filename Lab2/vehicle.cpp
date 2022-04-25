#include <iostream>
#include <string>
#include "vehicle.h"

// --------------------------- Setters ----------------------------- //
void Vehicle::set_brand(const std::string& brand) {
    this->brand = brand;
}

void Vehicle::set_model(const std::string& model) {
    this->model = model;
}

void Vehicle::set_cost(const int cost) {
    this->cost = cost;
}

// --------------------------- Getters ----------------------------- //
std::string Vehicle::get_brand() const {
    return brand;
}

std::string Vehicle::get_model() const {
    return model;
}

int Vehicle::get_cost() const {
    return cost;
}

// ------------------------- Constructors -------------------------- //
Vehicle::Vehicle() {
    brand = "";
    model = "";
    cost = 0;
}

Vehicle::Vehicle(const std::string& n, const std::string& s, const int& sg) {    //Конструктор с параметрами
    brand = n;
    model = s;
    cost = sg;
}

Vehicle::Vehicle(const Vehicle& E) {    //Конструктор копирования T::T(const T&) {...}
    brand = E.brand;
    model = E.model;
    cost = E.cost;
}

//------------------------- Other functions ------------------------- //
void Vehicle::show() const {
    std::cout << "brand: " << get_brand() << std::endl;
    std::cout << "model: " << get_model() << std::endl;
    std::cout << "cost: " << get_cost() << std::endl;
}