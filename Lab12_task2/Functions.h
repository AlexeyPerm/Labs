#pragma once

#include <set>
#include <random>
#include <vector>
#include "Money.h"

typedef std::multiset<Money> ms;
typedef std::multiset<Money>::iterator it;

auto makeMultiset(const int& n) -> ms;
auto average(const ms& mset) -> Money;
auto printMultiset(const ms& mset) -> void;
auto subtractMinElement(ms& mset, const Money& elem) -> void;
template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

ms makeMultiset(const int& n) {
    ms mset;
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        mset.insert(m);
    }
    return mset;
}

void printMultiset(const ms& mset) {
    for (const auto& item: mset) {
        std::cout << item << "  ";
    }
    std::cout << std::endl;
}

Money average(const ms& mset) {
    Money m;
    m = 0;
    for (const auto& item: mset) {
        m += item;
    }
    Money result = m / mset.size();  //хранение среднего значения.
    return result;
}

void subtractMinElement(ms& mset, const Money& elem) {
    std::vector<Money> vec;
    for (const auto & i : mset) {
        vec.push_back(i - elem);
    }
    mset.clear();
    for (const auto& item: vec) {
        mset.insert(item);
    }
}

template<class T>
T generateRandom(const T& left, const T& right) {
    const char* i  = typeid(int).name();
    const char* l  = typeid(long).name();
    const char* d  = typeid(double).name();
    const char* ll = typeid(long long).name();
    const char* e  = typeid(long double).name();

    std::random_device rd;
    std::mt19937 gen(rd());

    if (typeid(T).name() == i || typeid(T).name() == l) {
        std::uniform_int_distribution<> dis(left, right);
        return dis(gen);
    } else if ((typeid(T).name() == d) || (typeid(T).name() == e) || (typeid(T).name() == ll)) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}