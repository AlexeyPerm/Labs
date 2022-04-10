#pragma once

#include <vector>
#include <istream>
#include <ostream>
#include <iostream>
#include <initializer_list>

template<class T>
class List;

template<class T>
std::ostream& operator<<(std::ostream& out, const List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        out << v.data[i] << std::endl;
    }
    return out;
}

template<class T>
std::istream& operator>>(std::istream& in, List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        in >> v.data[i];
    }
    return in;
}

template<class T>
class List {
public:
// ------------------------- Constructors -------------------------- //
    List() { size = 0; }
    explicit List(const int&);
//Использую список инициализации ввиду того, что лень вручную постоянно заполнять значениями каждый объект класса
    List(const std::initializer_list<T>&);
    ~List() = default;
// ---------------------------- Methods ---------------------------- //

    T average() const;
    void print() const;
    int getSize() const { return size; }
    T minElement() const;
    void addItemToBeginVector(T& elem);
    void removeElementByIndex(const int& index);
// --------------------------- Overloads --------------------------- //

    friend std::istream& operator>><T>(std::istream&, List<T>&);
    friend std::ostream& operator
    <<<T>(std::ostream&, const List<T>&);

private:
    int size;   //размер списка
    std::vector<T> v;    //указатель на массив элементов списка
};

// ------------------------- Constructors -------------------------- //
template<class T>
List<T>::List(const int& s) {
    T a;
    for (int i = 0; i < s; ++i) {
        //std::cin >> a;
        v.push_back(a);
    }
    size = v.size();
}
//Принимает список объектов <T> и заполняем ими вектор.
template<class T>
List<T>::List(const std::initializer_list<T>& list) {
    for (auto& item: list) {
        v.push_back(item);
    }
    size = list.size();
}

// ---------------------------- Methods ---------------------------- //
template<class T>
void List<T>::print() const {
    for (const auto& item: v) {
        std::cout << item << "  ";
    }
    std::cout << std::endl;
}

template<class T>
T List<T>::average() const {
    T m;
    m = 0;
    for (const auto& item: v) {
        m = m + item;
    }
    T a;
    a = m / v.size();
    return a;
}

template<class T>
void List<T>::addItemToBeginVector(T& elem) {
    v.insert(v.begin(), elem);
}

template<class T>
void List<T>::removeElementByIndex(const int& index) {
    v.erase(v.begin() + index);
}
template<class T>
T List<T>::minElement() const {
    T minElem = v[0];
    for (const auto& item: v) {
        if (item < minElem) {
            minElem = item;
        }
    }
    return minElem;
}

