#pragma once

#include "Object.h"

class Vector {
public:

// ------------------------- Constructors -------------------------- //
    explicit Vector(int);
    ~Vector();

// ---------------------------- Methods ---------------------------- //
    void Add(Object*);
    void Del();
    void Show();

// --------------------- Overloaded Functions ---------------------- //
    int operator()() const;

protected:
    Object** begin; //указатель на первый элемент вектора;
    int size;
    int current;    //текущая позиция
};

