#pragma once

#include "istream"
#include "iostream"

using namespace std;

template<class T>
class List;

template<class T>
ostream& operator<<(ostream& out, const List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        out << v.data[i] << endl;
    }
    return out;
}

template<class T>
istream& operator>>(istream& in, List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        in >> v.data[i];
    }
    return in;
}


template<class T>
class List {
public:
// ------------------------- Constructors -------------------------- //
    List(int, T);

    [[maybe_unused]] List(const List<T>&);

    ~List();

// --------------------------- Overloads --------------------------- //
    List operator+(T list);

    T& operator[](int) const; //���������� ��������������

    explicit operator int() const;

    List& operator=(const List<T>&);

    //��� ��� �� ��������� ������������� ������, �� �� ����� �������
    //����������� (��� ������ ����������) ������ ������� �� ������ List
    //https://ru.stackoverflow.com/a/495222
    friend ostream& operator<<<T>(ostream&, const List<T>&);

    friend istream& operator>><T>(istream&, List<T>&);

private:
    int size = 0;   //������ ������
    T* data = nullptr;  //��������� �� ������ ��������� ������
};

/*
���������� ���� �� List.cpp � List.h ������� List.h �������
�������/�������������. ������������� ����� ��������������
List.cpp � List.inl (.inl �� ����. "inline" = "����������"),
� ����� ����������� List.inl �� ������ ����� ����� List.h.
��� ���� ��� �� ���������, ��� � ���������� ����� ���� �
������������ �����, �� ��� ��������� ������� ����.
 */
#include "List.inl"