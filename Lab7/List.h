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
        in >> v.pData[i];
    }
    return in;
}


template<class T>
class List {
public:
// ------------------------- Constructors -------------------------- //
    List(int, T);

    List(const List<T>&);

    ~List();

// --------------------------- Overloads --------------------------- //
    List operator+(T list);

    T& operator[](int) const; //���������� ��������������

    explicit operator int() const;

    List& operator=(const List<T>&);

    //��� ��� �� ��������� ������������� ������, �� �� ����� �������
    //����������� (��� ������ ����������) ������ ������� �� ������ List
    //https://ru.stackoverflow.com/a/495222
    friend ostream& operator
    <<<T>(ostream&, const List<T>&);

    friend istream& operator>><T>(istream&, List<T>&);

private:
    int size = 0;   //������ ������
    T* data = nullptr;  //��������� �� ������ ��������� ������
};


template<class T>
List<T>::List(const int s, const T k) {
    size = s;
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = k;
    }
}

template<class T>
List<T>::List(const List<T>& list) {
    size = list.size;
    delete[] data;
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = list.data[i];
    }
}

template<class T>
List<T>::~List() {
    delete[] data;
    data = nullptr;
}

// --------------------------- Overloads --------------------------- //

template<class T>
List<T>::operator int() const {
    return size;
}

template<class T>
List<T> List<T>::operator+(const T list) {
    List<T> temp(size, list);
    for (int i = 0; i < size; ++i) {
        temp.data[i] = data[i] + list;
    }
    return temp;
}

template<class T>
T& List<T>::operator[](const int index) const {
    if (size > index) {
        return data[index];
    } else {
        cout << "\nError! Index > size\nExit..." << endl;
        exit(0);
    }
}

template<class T>
List<T>& List<T>::operator=(const List<T>& list) {
    if (this == &list) {
        return *this;
    }
    delete[] data;
    size = list.size;
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = list.data[i];
    }
    return *this;
}

/*
���������� ���� �� List.cpp � List.h ������� List.h �������
�������/�������������. ������������� ����� ��������������
List.cpp � List.inl (.inl �� ����. "inline" = "����������"),
� ����� ����������� List.inl �� ������ ����� ����� List.h.
��� ���� ��� �� ���������, ��� � ���������� ����� ���� �
������������ �����, �� ��� ��������� ������� ����.
 */
//#include "List.inl"