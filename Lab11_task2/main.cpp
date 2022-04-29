#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include "Money.h"

typedef std::vector<Money> Vec;

auto average(const Vec& v) -> Money;
auto makeVector(const int& n) -> Vec;
auto printVector(const Vec& v) -> void;
auto minElement(const Vec& v) -> Money;
auto subtractMinElement(Vec& v) -> void;
auto removeElementByIndex(Vec& v, const int& index) -> void;
auto addItemToBeginVector(Vec& v, const Money& item) -> void;
template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер


int main() {
//Генерируем размер вектора от 1 до 10. При необходимости диапазон можно изменить.
    const int n = generateRandom(1, 10);
    std::cout << "Generated vector with size = " << n << ":\n";
    Vec v = makeVector(n);
    printVector(v);

    std::cout << "Average: ";
    auto averageMoney = average(v);
    std::cout << averageMoney << std::endl;

    std::cout << "Add average item to the beginning of the vector:\n";
    addItemToBeginVector(v, averageMoney);
    printVector(v);

    std::cout << "Remove element from the vector. ";
    //немного схалявим и срандомизируем номер удаляемого элемента
    int eraseItem = generateRandom(0, static_cast<int> (v.size() - 1));
    std::cout << "Index of removed element: " << eraseItem << std::endl;
    removeElementByIndex(v, eraseItem);
    printVector(v);

    std::cout << "Minimum element: ";
    auto minimumElement = minElement(v);;
    std::cout << minimumElement << std::endl;

    std::cout << "Every element minus minimumElement: ";
    subtractMinElement(v);
    printVector(v);

    return 0;
}

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

void addItemToBeginVector(Vec& v, const Money& item) {
    v.insert(v.begin(), item);
}

void removeElementByIndex(Vec& v, const int& index) {
    v.erase(v.begin() + index);
}

Money minElement(const Vec& v) {
//Присваиваем переменной minElem значение, возвращаемое функцией min_element. Делается автоопределения типа,
//так как тип возвращаемых данных сложный и длинный и писать такое руками не просто.
    auto minElem = std::min_element(v.begin(), v.end());
    return *minElem;
}

void subtractMinElement(Vec& v) {
    Money minElem = minElement(v);
    for (auto& item: v) {
        item -= minElem;
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
    const char* e = typeid(long double).name();

    std::random_device rd;
    std::mt19937 gen(rd());

    if (typeid(T).name() == i || typeid(T).name() == l) {
        std::uniform_int_distribution<> dis(left, right);
        return dis(gen);
    }
    else if ((typeid(T).name() == d) || (typeid(T).name() == e)) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}