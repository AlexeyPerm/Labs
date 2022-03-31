#pragma once
#include "Object.h"
#include "string"

class Car : public Object {
public:

// ------------------------- Constructors -------------------------- //
    Car();
    Car(const Car&);
    Car(const std::string&, int, int);

// --------------------- Overridden Functions ---------------------- //
    ~Car() override;
    void Show() override;
    void Input() override;
    void HandleEvent(const TEvent & e) override;

// --------------------------- Getters ----------------------------- //
    std::string GetMark() const { return mark; }
    int GetCyl() const { return cyl; }
    int GetPower() const { return power; }

// --------------------------- Setters ----------------------------- //
    void Setmark(std::string m) { mark = m; }
    void SetCyl(int c) { cyl = c; }
    void SetPower(int p) { power = p; }

// --------------------- Overloaded Functions ---------------------- //
    Car& operator=(const Car&);

protected:
    std::string mark;
    int cyl;
    int power;
};