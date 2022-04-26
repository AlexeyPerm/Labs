#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include "../Lab12_task2/Money.cpp"

typedef std::stack<Money> st;
typedef std::vector<Money> vec;

auto average(st s) -> Money;
auto minElement(st& s) -> Money;
auto printStack(st s) -> void;
auto makeStack(const int& n) -> st;
auto copyVectorToStack(vec& v) -> st;
auto copyStackToVector(st& s) -> vec;
auto subtractMinElement(st& s) -> void;
auto delByElemNumber(st& s, const int& number) -> void;
auto addElementToBeginStack(st& s, const Money& elem) -> void;

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

st makeStack(const int& n) {
    st s;
    constexpr long lRubles = 0;
    constexpr int  iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int  k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        s.push(m);
    }
    return s;
}

void printStack(st s) {
//Передаём копию стека, так как при выводе элементы стека удаляются.
    while (!s.empty()) {
        std::cout << s.top() << "  ";
        s.pop();
    }
    std::cout << std::endl;
}

Money average(st s) {
    Money m;
    m = 0;
    int n = static_cast<int> (s.size());   //количество элементов в стеке
    while (!s.empty()) {
        m += s.top();
        s.pop();
    }
    Money result;  //хранение среднего значения.
    result = m / n;
    return result;
}

vec copyStackToVector(st& s) {
    vec v;
    while (!s.empty()) {
        //добавить элемент из вершины стека
        v.push_back(s.top());
        s.pop();
    }
    s = copyVectorToStack(v);
    return v;
}

st copyVectorToStack(vec& v) {
    st s;
    for (auto iter = v.end() - 1; iter >= v.begin(); --iter) {
        s.push(*iter);
    }
    return s;
}

void addElementToBeginStack(st& s, const Money& elem) {
    vec v = copyStackToVector(s);
    v.insert(v.begin() + static_cast<int> (v.size()), elem);   //помещаем элемент в начало вектора.
    while (!s.empty()) {
        s.pop();
    }
    s = copyVectorToStack(v);
}

void delByElemNumber(st& s, const int& number) {
    vec v = copyStackToVector(s);           //переводим стек в вектор
    while (!s.empty()) {
        s.pop();
    }
    int i = static_cast<int> (v.size()) - 1;                       //размер вектора.
    do {
        if (i != (v.size() - 1 - number)) {     //не добавляем удаляемый элемент.
            s.push(v[i]);
        }
        --i;
    } while (i >= 0);

}

Money minElement(st& s) {
    vec v = copyStackToVector(s);
    Money minMoney = v[0];
    for (const auto& item: v) {
        if (item < minMoney) {
            minMoney = item;
        }
    }
    return minMoney;
}

void subtractMinElement(st& s) {
    vec v = copyStackToVector(s);
    Money minElem = minElement(s);
    for (auto& item: v) {
        item -= minElem;
    }
    while (!s.empty()) {
        s.pop();
    }
    s = copyVectorToStack(v);
}

template<class T>
T generateRandom(const T& left, const T& right) {
    /* -------------------------------------------------------------------------------------------------
     * std::random_device rd генератор для недетерминированных случайных чисел,
     * зависящий от непредсказуемого источника.
     * https://en.cppreference.com/w/cpp/numeric/random/random_device
     * -------------------------------------------------------------------------------------------------
     * std::mt19937 Генератор псевдослучайных чисел, использующий алгоритм Вихрь Мерсенна.
     * https://www.cplusplus.com/reference/random/mt19937/
     * -------------------------------------------------------------------------------------------------
     * std::uniform_real_distribution<> dis(left, right)  left, right - диапазон, в котором будут
     * сгенерированы числа.
     * https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
     * -------------------------------------------------------------------------------------------------
     */

    const char* i  = typeid(int).name();
    const char* l  = typeid(long).name();
    const char* d  = typeid(double).name();
    const char* ll = typeid(double).name();
    const char* e  = typeid(long double).name();

    std::random_device rd;
    std::mt19937 gen(rd());

    if (typeid(T).name() == i || typeid(T).name() == l || typeid(T).name() == ll) {
        std::uniform_int_distribution<> dis(left, right);
        return dis(gen);
    }
    else if ((typeid(T).name() == d) || (typeid(T).name() == e)) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}
