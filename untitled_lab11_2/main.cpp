#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Time.h"

typedef std::vector<Time> Vec;

auto makeVector(int) -> Vec;
auto max(const Vec&) -> int;
auto min(const Vec&) -> int;
auto division(Vec&) -> void;
auto average(const Vec&) -> Time;
auto delVector(Vec&, int) -> void;
auto printVector(const Vec&) -> void;
auto addVector(Vec&, int, const Time&) -> void;

int main() {
    std::srand(std::time(nullptr));
    try {
        Vec v;
        auto vi = v.begin();
        constexpr int n = 10;   //количество элементов
        v = makeVector(n);
        printVector(v);

        std::cout << "\nAverage : " << std::endl;
        Time el = average(v);
        std::cout << el;
        std::cout << "\nEnter position number: ";
        int pos;
        std::cin >> pos;
        if (pos > v.size()) {
            throw 1;
        }
        addVector(v, pos, el);
        printVector(v);
        std::cout << "\nMaximum element: ";
        int nMax = max(v);
        std::cout << nMax;
        std::cout << "\nRemove min element: " << std::endl;
        delVector(v, nMax);
        printVector(v);
        //делим каждый элемент на минимальное значение вектора

    }
    catch (int) {
        std::cout << "Error!!!" << std::endl;
    }

    return 0;
}


Vec makeVector(const int n) {
    Vec v;
    for (int i = 0; i < n; ++i) {
        int a = (std::rand() % 60);
        int b = (std::rand() % 60);
        Time t(a, b);
        v.push_back(t);
    }
    return v;
};

void printVector(const Vec& v) {
    for (const auto& i: v) {
        std::cout << i << std::endl;
    }
}

Time average(const Vec& v) {
    int s = 0;  //сумма всех элементов
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        s += v[i].getMin() * 60 + v[i].getSec();
    }
    int tmp = s / n;
    Time t;
    t.setMin(tmp / 60);
    t.setSec(tmp % 60);
    return t;
}

void addVector(Vec& v, const int position, const Time& element) {
    v.insert(v.begin() + position, element);
};

int min(const Vec& v) {
    //Time m = v[0];
    int m = v[0].getMin() * 60 + v[0].getSec();
    int n = 0;  //номер элемента
    int tmp = 0;
    for (int i = 0; i < v.size(); ++i) {
        tmp = v[i].getMin() * 60 + v[i].getSec();   //вычисляем кол-во секунд в каждом элементе вектора
        if (tmp < m) {
            m = tmp;
            n = i;
        }
    }
    Time t;
    t.setMin(m / 60);
    t.setSec(m % 60);
    return n;
}

void delVector(Vec& v, const int position) {
    v.erase(v.begin() + position);
}

int max(const Vec& v) {
    int m = v[0].getMin() * 60 + v[0].getSec();
    int n = 0;  //номер элемента
    int tmp = 0;
    for (int i = 0; i < v.size(); ++i) {
        tmp = v[i].getMin() * 60 + v[i].getSec();   //вычисляем кол-во секунд в каждом элементе вектора
        if (tmp > m) {
            m = tmp;
            n = i;
        }
    }
    Time t;
    t.setMin(m / 60);
    t.setSec(m % 60);
    return n;
}

void division(Vec& v) {
    int m = min(v);
    int tmp = v[0].getMin() * 60 + v[0].getSec();
    for (int i = 0; i < v.size(); ++i) {

    }
}