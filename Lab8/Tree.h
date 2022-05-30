#pragma once

#include "Object.h"

class Tree {
protected:
    int      size;
    int      current;
    Object** begin;
public:
// ------------------------- Constructors -------------------------- //
    Tree();
    explicit Tree(const int& size);
    virtual ~Tree();
// ---------------------------- Methods ---------------------------- //
    void Del();
    void Show() const;
    void Add(Object* z = nullptr);
    void HandleEvent(const TEvent& e);
    void ShowElementNumber(const int& elemNum) const;
    int operator()() const { return current; }


};