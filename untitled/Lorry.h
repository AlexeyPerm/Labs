#pragma once

#include "Car.h"

class Lorry : public Car {
public:
    Lorry() { load = 0; }

public:
// ------------------------- Constructors -------------------------- //
    Lorry(const Lorry&);
    Lorry(std::string, int, int, int);

// --------------------- Overridden Functions ---------------------- //
    void Show() override ;
    void Input() override;

// --------------------------- Getters ----------------------------- //
    int GetLoad() const { return load; }

// --------------------------- Setters ----------------------------- //
    void SetLoad(int l) { load = l; }

// --------------------- Overloaded Functions ---------------------- //

    Lorry& operator=(const Lorry&);
protected:
    int load;

};



