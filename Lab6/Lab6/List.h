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
    //������ ������������� ��� ����������� �������� ����������
    //������, ��� �����-�� ������ ���������:
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
    Iterator last() { return end; }        //���������� ��������� �� ������ �������
    Iterator first() { return begin; }    //���������� ��������� �� ��������� �������
// ---------------------------- Methods ---------------------------- //
    void erase();    //�������� ��������� ������.
    void pushElem(int elem);
    int  getSize () const { return size; }
    void setSize (const int s) { size = s; }
private:
    int  size;    //������ �������
    int* data;        //��������� �� ������
    Iterator begin;
    Iterator end;
};