#include "List.h"

// ------------------------- Constructors -------------------------- //


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

