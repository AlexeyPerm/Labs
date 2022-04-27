#pragma once

#include "iostream"
#include <initializer_list>
#include "Iterator.h"

class List {
public:
// ------------------------- Constructors -------------------------- //
    List();
    explicit List(int size);
    List(const List&);
    List(int size, int k);
    //—писок инициализации дл€ возможности создани€ экземпл€ра
    //класса, как какой-то массив элементов:
    // List l{1, 2, 345, 567, 2};
    List(const std::initializer_list<int>&);
    ~List();
// --------------------------- Overloads --------------------------- //
    int& operator[](int) const;
    List& operator=(const List&);
    explicit operator int() const;
    friend std::istream& operator>>(std::istream&, List&);
    friend std::ostream& operator<<(std::ostream&, const List&);
// --------------------------- Iterators --------------------------- //
    Iterator last() { return end; }        //возвращает указатель на первый элемент
    Iterator first() { return begin; }    //возвращает указатель на последний элемент
// ---------------------------- Methods ---------------------------- //
    void erase();    //ќчистить созданные массив.
    void pushElem(int elem);
    int  getSize () const { return size; }
    void setSize (const int s) { size = s; }
private:
    int  size;    //размер массива
    int* data;        //указатель на массив
    Iterator begin;
    Iterator end;
};