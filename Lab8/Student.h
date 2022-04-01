#pragma once

#include <ostream>
#include "Person.h"

class Student : public Person {
public:
// ------------------------- Constructors -------------------------- //
    Student();
    Student(const Student&);
    Student(const std::string&, int, double);
    ~Student() override;
// --------------------- Overridden Functions ---------------------- //
    void Show() override;
    void Input() override;
// --------------------------- Getters ----------------------------- //
   double GetRate() const;
// --------------------------- Setters ----------------------------- //
    void SetRate(double r);
// --------------------- Overloaded Functions ---------------------- //
    Student& operator=(const Student&);

private:
    double rate;

};