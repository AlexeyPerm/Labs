#pragma once

#include <ostream>
#include "Person.h"

#define DEBUG_STUDENT

#ifdef DEBUG_STUDENT
#include <iostream>
#endif //DEBUG_STUDENT

class Student : public Person {
public:
// ------------------------- Constructors -------------------------- //
    Student() : Person() { rate = .0; }

    Student(const Student&);
    Student(const std::string&, int, double);
#ifndef DEBUG_STUDENT
    ~Student() override = default;
#else
    ~Student() override {
        std::cout << "Destructor for " << this << std::endl;
    }
#endif //DEBUG_STUDENT

// --------------------- Overridden Functions ---------------------- //
    void Show() override;
    void Input() override;

// --------------------------- Getters ----------------------------- //
    double GetRate() const { return rate; }

// --------------------------- Setters ----------------------------- //
    void SetRate(const double& r) { rate = r; }

// --------------------- Overloaded Functions ---------------------- //
    Student& operator=(const Student&);

private:
    double rate;
};