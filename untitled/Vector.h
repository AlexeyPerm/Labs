#pragma once

#include "Object.h"
#include "Event.h"

class Vector {
public:
// ------------------------- Constructors -------------------------- //
    Vector();
    explicit Vector(int);
    ~Vector();

// --------------------- Overridden Functions ---------------------- //
    void HandleEvent(const TEvent& e);

// ---------------------------- Methods ---------------------------- //
    void Add(Object* z = nullptr);
    void Show() const;
    void Del();

// --------------------- Overloaded Functions ---------------------- //
    int operator()() const;

protected:
    Object** begin; //указатель на первый элемент вектора;
    int size;
    int current;    //текущая позиция
};

