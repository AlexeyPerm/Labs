#pragma once

#include "Object.h"
#include <iostream>

class Vector {
public:
    Vector();
    explicit Vector(int s);
    Vector(const Vector&);
    ~Vector();
    void Add(Object*);
    friend std::ostream& operator<<(std::ostream& out, const Vector& V);

private:
    int cur;
    int size;
    Object** begin; //��������� ���� Object �� ����� �������, ��� ����� ��������� ������� �������.
};