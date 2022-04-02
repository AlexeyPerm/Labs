#pragma once

#include "Object.h"

class Tree {
public:
// ------------------------- Constructors -------------------------- //
    Tree();
    explicit Tree(int);
    ~Tree();
// ---------------------------- Methods ---------------------------- //
    void Del();
    void Show() const;
    void Add(Object* z = nullptr);
    void ShowElementNumber(const int&) const;
// --------------------- Overridden Functions ---------------------- //
    void HandleEvent(const TEvent& e);
// --------------------- Overloaded Functions ---------------------- //
    int operator()() const { return current; }

protected:
    int size;
    int current;
    Object** begin;
};
