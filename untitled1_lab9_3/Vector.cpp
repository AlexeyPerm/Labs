#include "Vector.h"
#include "Error.h"
#include <iostream>

// ------------------------- Constructors -------------------------- //
Vector::Vector(const int s) {
    if (s > MAX_SIZE) {
        throw MaxSizeError();
    }
    size = s;
    begin = new int[s];
    for (int i = 0; i < size; ++i) {
        begin[i] = 0;
    }
}

Vector::Vector(int s, const int* arr) {
    if (s > MAX_SIZE) {
        throw MaxSizeError();
    }
    size = s;
    begin = new int[size];
    for (int i = 0; i < size; ++i) {
        begin[i] = arr[i];
    }
}

Vector::Vector(const Vector& v) {
    size = v.size;
    begin = new int[size];
    for (int i = 0; i < size; ++i) {
        begin[i] = v.begin[i];
    }
}

Vector::~Vector() {
    if (begin) {
        delete[] begin;
    }
}

// --------------------- Overloaded Functions ---------------------- //
Vector& Vector::operator=(const Vector& v) {
    if (this == &v) {
        return *this;
    }
    size = v.size;
    begin = new int[size];
    for (int i = 0; i < size; ++i) {
        begin[i] = v.begin[i];
    }
    return *this;
}

int Vector::operator[](const int& i) {
    if (i < 0) {
        throw IndexError1(); //если индекс i < 0, то бросаем исключение
    }
    if (i >= size) {
        throw IndexError2();
    }
    return begin[i];
}

Vector Vector::operator+(const int& a) {
//Если при добавлении размер станет больше максимального, то бросаем исключение.
    if (size + 1 == MAX_SIZE) {
        throw 4;
    }
    Vector temp(size + 1, begin);
    temp.begin[size] = a;
    return temp;
}

Vector Vector::operator--() {
//Если вектор пуст, то вбрасываем исключение
    if (!size) {
        throw EmptySizeError();
    }
    if (size == 1) {
        size = 0;
        delete[] begin;
        begin = nullptr;
        return *this;
    }
    Vector temp(size, begin);   //передаём размер и весь массив во временный объект temp
    delete[] begin;
    --size;
    begin = new int[size];
    for (int i = 0; i < size; ++i) {
        begin[i] = temp.begin[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    if (!v.size) {
        out << "Empty array\n";
    } else {
        for (int i = 0; i < v.size; ++i) {
            out << v.begin[i] << std::endl;
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v) {
    for (int i = 0; i < v.size; ++i) {
        std::cout << ">";
        in >> v.begin[i];
    }
    return in;
}