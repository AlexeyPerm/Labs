#include <iostream>
#include <ctime>
#include "..\untitled_lab11_2\Time.h"
#include "..\untitled_lab11_2\Time.cpp"
#include <vector>
#include <stack>

typedef std::stack<Time> St;
typedef std::vector<Time> Vec;

auto max(St& s) -> int;
auto min(St& s) -> int;
auto average(St& s) -> Time;
auto delMinElement(St& s) -> St;
auto printStack(St& s) -> void;
auto makeStack(const int& n) -> St;
auto copyStackToVector(St& s) -> Vec;
auto copyVectorToStack(const Vec& v) -> St;
auto addToStack(St& s, const Time& elem, const int& pos) -> void;

int main() {
    std::srand(std::time(nullptr));
    constexpr int n = 10;   //кол-во элементов в векторе.
    auto myStack = makeStack(n);

    auto timeAverage = average(myStack);
    //printStack(myStack);

    std::cout << "\nAverage : " << std::endl;
    std::cout << timeAverage << std::endl;

    std::cout << "\nEnter position number: ";
    int pos;
    std::cin >> pos;
    addToStack(myStack, timeAverage, pos);

    std::cout << "\nMinimum element: ";
    int nMin = min(myStack);
    std::cout << nMin;
    std::cout << "\nRemove min element: " << std::endl;
    delMinElement(myStack);

    printStack(myStack);

    return 0;
}

St makeStack(const int& n) {
    St s;
    for (int i = 0; i < n; ++i) {
        int a = (std::rand() % 60);
        int b = (std::rand() % 60);
        Time t(a, b);
        s.push(t);
    }
    return s;
}

Vec copyStackToVector(St& s) {
    Vec v;
    while (!s.empty()) {
        //добавить элемент из вершины стека
        v.push_back(s.top());
        s.pop();
    }
    s = copyVectorToStack(v);
    return v;
}

St copyVectorToStack(const Vec& v) {
    St s;
    for (const auto& i: v) {
        s.push(i);
    }
    return s;
}

void printStack(St& s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
}

Time average(St& s) {
    Vec v = copyStackToVector(s);
    int n = 0;
    long long sum{};

    for (const auto& item: v) {
        sum += item.getMin() * 60 + item.getSec();
        ++n;
    }
    s = copyVectorToStack(v);
    long long tmp = sum / n;
    Time t;
    t.setMin(static_cast<int> (tmp / 60));
    t.setSec(static_cast<int> (tmp % 60));
    return t;
}

void addToStack(St& s, const Time& elem, const int& pos) {
    Time t;
    Vec v;
    int i = 1;  //номер элемента в стеке
    while (!s.empty()) {
        //t = s.top();
        if (i == pos) {
            v.push_back(elem);
        }
        v.push_back(s.top());   //добавляем текущий элемент стека в вектор
        s.pop();
        ++i;
    }
    s = copyVectorToStack(v);
}

int max(St& s) {
    Vec v = copyStackToVector(s);
    long long m = v[0].getMin() * 60 + v[0].getSec();
    long long tmp = 0;
    int n = 0;  //номер минимального элемента
    for (int i = 0; i < v.size(); ++i) {
        tmp = v[i].getMin() * 60 + v[i].getSec();   //вычисляем кол-во секунд в каждом элементе вектора
        if (tmp > m) {
            m = tmp;
            n = i;
        }
    }
//    Time t;
//    t.setMin(static_cast<int> (m / 60));
//    t.setSec(static_cast<int> (m % 60));
    return n;
}

int min(St& s) {
    Vec v = copyStackToVector(s);
    long long m = v[0].getMin() * 60 + v[0].getSec();
    long long tmp = 0;
    int n = 0;  //номер минимального элемента
    for (int i = 0; i < v.size(); ++i) {
        tmp = v[i].getMin() * 60 + v[i].getSec();   //вычисляем кол-во секунд в каждом элементе вектора
        if (tmp < m) {
            m = tmp;
            n = i;
        }
    }
//    Time t;
//    t.setMin(static_cast<int> (m / 60));
//    t.setSec(static_cast<int> (m % 60));
    return n;
}

St delMinElement(St& s) {
    auto minElem = min(s);
    Vec v;
    int n = 0;
    while (!s.empty()) {
        if (n != minElem) {
            v.push_back(s.top());
            s.pop();
        } else {
            std::cout << "Min element = " << s.top();
            s.pop();
        }
    }
    s = copyVectorToStack(v);
    return s;
}