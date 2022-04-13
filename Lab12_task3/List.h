#pragma once

#include <vector>
#include <stack>
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
    explicit List(const int& n);
//Использую список инициализации ввиду того, что лень вручную постоянно заполнять значениями каждый объект класса
    List(const std::initializer_list<T>&);
    ~List() = default;
// ---------------------------- Methods ---------------------------- //
    void print();
    T minElement ();
    T average() const;
    void subtractMinElement();
    void addItemToBeginStack(T& elem) ;
    int  getSize() const { return size; }
    void delByElemNumber (const int& number);
// --------------------------- Overloads --------------------------- //
    friend std::istream& operator>><T>(std::istream&, List<T>&);
    friend std::ostream& operator
    <<<T>(std::ostream&, const List<T>&);

private:
    int size;   //размер списка
    std::multiset<Money> mset;
    std::multiset<Money>::iterator it;

};

// ------------------------- Constructors -------------------------- //
template<class T>
List<T>::List(const int& n) {
    T a;
    for (int i = 0; i < n; ++i) {
        //std::cin >> a;    //заменил генерацией случайных чисел.
        mset.insert(a);
    }
    size = mset.size();
}

//Принимает список объектов <T> и заполняем ими вектор.
template<class T>
List<T>::List(const std::initializer_list<T>& list) {
    for (auto& item: list) {
        mset.insert(item);
    }
    size = list.size();
}

// ---------------------------- Methods ---------------------------- //

void print(){

}