#pragma once

class Iterator {
    friend class List;    //������ ��� �������� ���������� ��� ������ List.

public:
// ------------------------- Constructors -------------------------- //
    Iterator() { current = nullptr; }    //������ ������� ���������
    explicit Iterator(int* const c) : current(c) {};
    Iterator(const Iterator& it) { current = it.current; }

// --------------------------- Overloads --------------------------- //
    Iterator& operator++();         //���������� �������� � ���������� �������� ����������
    Iterator  operator++(int);      //���������� �������� � ���������� �������� ����������
    Iterator& operator--();         //���������� �������� � ����������� �������� ����������
    Iterator  operator--(int);      //���������� �������� � ����������� �������� ����������
    Iterator& operator-=(int n);    //���������� �������� ����� � �������� � ������� n;
    Iterator  operator-(int n);     //���������� �������� ����� � �������� � ������� n;
    int& operator*() { return *current; }    //���������� �������, �� ������� � ������ ������ ��������� ��������.
    bool operator==(const Iterator& it) const { return current == it.current; }
    bool operator!=(const Iterator& it) const { return current != it.current; }

private:
    int* current;       //��������� �� ������� �������.
};