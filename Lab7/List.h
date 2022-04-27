#pragma once

#include <iomanip>
#include <istream>
#include <iostream>

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
    List() { size = 0; data = new T[size]; }
    explicit List(const int s) { size = s; data = new T[size]; }
    List(int, T);
    List(const List<T>&);
    ~List();

// --------------------------- Overloads --------------------------- //
    List operator+(T list);
    T& operator[] (int) const; //перегрузка индексирования
    explicit operator int() const;
    List& operator=(const List<T>&);

//Так как мы объявляем специализацию другом, то мы можем вынести
//определение (или только объявление) общего шаблона до класса List
//https://ru.stackoverflow.com/a/495222
    friend ostream& operator<<<T>(ostream&, const List<T>&);
    friend istream& operator>><T>(istream&, List<T>&);

    void erase();
    void print() const;
    int getSize() const { return size; }
private:
    int size;   //размер списка
    T*  data;  //указатель на массив элементов списка
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
    size   = list.size;
    delete[] data;
    data   = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = list.data[i];
    }
}

template<class T>
List<T>::~List() {
    delete[] data;
    data   = nullptr;
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
    }
    else {
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

template<class T>
void List<T>::print() const {
    for (int i = 0; i < size; ++i) {

        std::cout << std::fixed << std::setprecision(2) << data[i] << "  ";
    }
    std::cout << std::endl;
}

template<class T>
void List<T>::erase() {
    delete[] data;
    data = nullptr;     //присваивает nullptr, чтобы не было висячих указателей.
    size = 0;
}