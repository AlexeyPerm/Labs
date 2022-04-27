#pragma once

#include <ostream>
#include "Person.h"

class Student : public Person {
public:
// ------------------------- Constructors -------------------------- //
    Student() : Person() { rate = .0; }
    Student(const Student&);
    Student(const std::string&, int, double);
    ~Student() override = default;
// --------------------- Overridden Functions ---------------------- //
    void Show()  override;
    void Input() override;
// ----------------------- Getters/Setters ------------------------- //
    double GetRate() const { return rate; }
    void SetRate(const double& r) { rate = r; }
// --------------------- Overloaded Functions ---------------------- //
    Student& operator=(const Student&);

private:
    double rate;
};