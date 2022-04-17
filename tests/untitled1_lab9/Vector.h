#pragma once

#include <ostream>

const int MAX_SIZE = 30;

class Vector {
public:
// ------------------------- Constructors -------------------------- //
    Vector() { size = 0, begin = nullptr; }
    explicit Vector(int);
    Vector(const Vector&);
    Vector(int, const int*);
    ~Vector();
// --------------------- Overloaded Functions ---------------------- //
    Vector operator--();  //удаление элемента
    int operator[](const int&);    //доступ по индексу
    Vector operator+(const int&);  //добавление элемента
    Vector& operator=(const Vector&);

    friend std::ostream& operator<<(std::ostream&, const Vector&);
    friend std::istream& operator>>(std::istream&, Vector&);
private:
    int size;   //текущий размер
    int* begin; //указатель на начало массива
};
