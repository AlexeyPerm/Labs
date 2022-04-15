#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include "Money.h"

Money g_m;
typedef std::vector<Money> Vec;
auto makeVector(const int& n) -> Vec;
auto printVector(const Vec& v) -> void;
auto genRandomMoney() -> Money;

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

// --------------------- Predicates --------------------- //

template<class T>
struct equalMoney : std::binary_function<T, T, bool> {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs == rhs;
    }
};

struct evenRubles {
    bool operator()(Money& m) {
        return ((m.getRubles() % 2) == 0 && m.getRubles() != 0);
    }
};

struct compLess {
    bool operator()(Money& lsh, Money& rhs) {
        return lsh > rhs;
    }
};

// --------------------- Functions ---------------------- //
Vec makeVector(const int& n) {
    Vec v;
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
//Верхняя граница генерирования ограничена, чтобы вывод на экран был более читаем и влез в одну строку.
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        v.push_back(m);
    }
    return v;
}

void printVector(const Vec& v) {
    for (const auto& item: v) {
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << item << "  ";
    }
    std::cout << std::endl;
}

Money genRandomMoney() {
    long r = generateRandom(0, 1000);
    int k = generateRandom(0, 99);
    Money genMoney(r, k);
    return genMoney;
}


template<class T>
T generateRandom(const T& left, const T& right) {
    const char* i = typeid(int).name();
    const char* l = typeid(long).name();
    const char* d = typeid(double).name();
    const char* ll = typeid(long long).name();
    const char* e = typeid(long double).name();

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