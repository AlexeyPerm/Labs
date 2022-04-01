#pragma once
#include "Person.h"

class Student : public Person{
public:
// ------------------------- Constructors -------------------------- //

    Student();
    Student(const double &);
    ~Student() override;

// --------------------- Overridden Functions ---------------------- //

// --------------------------- Getters ----------------------------- //

// --------------------------- Setters ----------------------------- //
// --------------------- Overloaded Functions ---------------------- //

private:
    double rate;

};