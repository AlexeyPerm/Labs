#pragma once

#include <map>
#include <vector>
#include <random>

typedef std::map<int, Money> Map;
const Money g_m;

auto printMap(const Map& m) -> void;
auto genRandomMoney() -> Money;
auto minElement(Map& s) -> Money;
auto makeMap(const int& n) -> Map;

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

// --------------------- Predicates --------------------- //



struct equalMoney {
    bool operator()(std::pair<int, Money>& lhs, Money& rhs) const {
        return lhs.second == rhs;
    }
};

//Подсмотрел этот вариант https://stackoverflow.com/questions/31354947/adding-all-values-of-map-using-stdaccumulate
//Шаблон не обязателен, но он более универсален.
//struct accumulateMapValues {
//    template<class T1, class MAP>
//    T1 operator()(T1 value, const MAP& item) const {
//        return value + item.second;
//    }
//};

//Считаем сумму текущего элемента item контейнера с временной переменной value, в которой накапливается результат
struct accumulateMapValues {
    Money operator()(const Money& value, const auto& item) const {
        return value + item.second;
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

Money genRandomMoney() {
    long r = generateRandom(0, 1000);
    int k = generateRandom(0, 99);
    Money genMoney(r, k);
    return genMoney;
}

Map makeMap(const int& n) {
    Map s;
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        s.insert(std::make_pair(i + 1, m));
    }
    return s;
}

void printMap(const Map& m) {
    for (const auto& item: m) {
        std::cout << item.first << " : " << item.second << std::endl;
    }

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
    } else if ((typeid(T).name() == d) || (typeid(T).name() == e)) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}