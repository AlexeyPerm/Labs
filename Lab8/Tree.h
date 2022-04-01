#pragma once

#include "Object.h"

class Tree {
public:
// ------------------------- Constructors -------------------------- //
    Tree();
    explicit Tree(int);
    ~Tree();
// ---------------------------- Methods ---------------------------- //
    void Add(Object * z = nullptr);
    void Show () const;
    void Del();

protected:
    int size;
    int current;
    Object** begin;
};
