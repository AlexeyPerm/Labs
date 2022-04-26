#pragma once

#include <string>

class Vehicle {

public:
// ------------------------- Constructors -------------------------- //
    Vehicle();                    //Конструктор по умолчанию
    Vehicle(const Vehicle&);    //Конструктор копирования
    Vehicle(const std::string&, const std::string&, const int&);    //Конструктор с параметрами
    ~Vehicle() = default;       //Деструктор
// --------------------------- Setters ----------------------------- //
    void set_cost(int);
    void set_brand(const std::string&);
    void set_model(const std::string&);
// --------------------------- Getters ----------------------------- //
    int get_cost() const;
    std::string get_brand() const;
    std::string get_model() const;

    void show() const;
private:
    int cost;
    std::string brand;
    std::string model;
};
