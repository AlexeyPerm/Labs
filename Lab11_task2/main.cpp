#include <iostream>
#include <vector>
#include <random>
#include "Money.h"

typedef std::vector<Money> Vec;

auto makeVector(const int& n) -> Vec;
auto average(const Vec& v) -> Money;
auto printVector(const Vec& v) -> void;
template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер


int main() {
    std::cout << "Generated vector: \n";
    constexpr int n = 10;
    auto v = makeVector(n);
    printVector(v);

    std::cout << "Average: ";
    auto averageMoney = average(v);
    std::cout << averageMoney << std::endl;

    return 0;
}

Vec makeVector(const int& n) {
    Vec v;
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        v.push_back(m);
    }
    return v;
}

void printVector(const Vec& v) {
    for (const auto& item: v) {
        std::cout << item << "  ";
    }
    std::cout << std::endl;
}

Money average(const Vec& v) {
    long long sum = 0;
    for (const auto& item: v) {
        sum += item.getRubles() * 100 + item.getKopeks();
    }
    Money m;
    const long long tmp = (sum / v.size());
    m.setRubles(static_cast<int> (tmp / 100));
    m.setKopeks(static_cast<int> (tmp % 100));
    return m;
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
    //
    const char* i = typeid(int).name();
    const char* l = typeid(long).name();
    const char* d = typeid(double).name();
    const char* e = typeid(long double).name();

    std::random_device rd;
    std::mt19937 gen(rd());

    if (typeid(T).name() == i || typeid(T).name() == l) {
        std::uniform_int_distribution<> dis(left, right);
        return dis(gen);
    } else if ((typeid(T).name() == d) || (typeid(T).name() == e)) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}