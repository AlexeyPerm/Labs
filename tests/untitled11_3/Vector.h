#pragma once

#include <iostream>
#include <vector>

template<class T>
class Vector {
public:
// ------------------------- Constructors -------------------------- //
    explicit Vector(int);
    Vector() { len = 0; }
    ~Vector() = default;
// --------------------------- Methods ----------------------------- //
    int getLen() const { return len; }
    T average() const;
    void print() const;
    void add(const int& pos, const T& el);

private:
    int len;
    std::vector<T> v;
};

template<class T>
Vector<T>::Vector(const int n) {
    for (int i = 0; i < n; ++i) {
        int a = (std::rand() % 60);
        int b = (std::rand() % 60);
        T t(a, b);
        v.push_back(t);
    }
    len = v.size();
}

template<class T>
void Vector<T>::print() const {
    for (const auto& item: v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template<class T>
T Vector<T>::average() const {
    long long s = 0;  //сумма всех элементов
    int n = v.size();
    for (const auto& item: v) {
        s += item.getMin() * 60 + item.getSec();
    }
    long long tmp = s / n;
    T t;
    t.setMin(static_cast<int> (tmp / 60));
    t.setSec(static_cast<int> (tmp % 60));
    return t;
}

template<class T>
void Vector<T>::add(const int& pos, const T& el) {
    v.insert(v.begin() + pos, el);
}
