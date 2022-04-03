#pragma once

#include <iostream>
#include <initializer_list>


class List {
public:
// ------------------------- Constructors -------------------------- //
    List();
    explicit List(int);
    List(const List&);
    List(const std::initializer_list<int>&);
    ~List();

// --------------------------- Getters ----------------------------- //
    int getCurrent() const { return *current; }
// --------------------- Overloaded Functions ---------------------- //
    int& operator[](int) const;
    List& operator-(int);
    explicit operator int() const;
    List& operator=(const List&);
    friend std::istream& operator>>(std::istream&, List&);
    friend std::ostream& operator<<(std::ostream&, const List&);
private:
    int size;
    int* arr;
    int* current;
};
