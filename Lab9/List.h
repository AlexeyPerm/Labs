#pragma once

#include <iostream>
#include <initializer_list>


class List {
public:
// ========================= Constructors ========================== //
    List();
    List(const List&);
    explicit List(int);
    List(const std::initializer_list<int>&);
    ~List();
// =========================== Getters ============================= //
    int getCurrent() const { return *current; }
// ===================== Overloaded Functions ====================== //

    List& operator-(int);
    int& operator[](int) const;
    List& operator=(const List&);
    explicit operator int() const;
    friend std::istream& operator>>(std::istream&, List&);
    friend std::ostream& operator<<(std::ostream&, const List&);
private:
    int  size;
    int* arr;
    int* current;
};
