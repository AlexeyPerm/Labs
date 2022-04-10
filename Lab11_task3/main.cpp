#include <iostream>
#include <vector>
#include <random>
#include "List.h"
#include "Money.h"
//#define DEBUG

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер
void generateElementsInVector(std::vector<Money>& v, const int& n);

int main() {
#ifndef DEBUG
//генерирую объекты класса Money для того, чтобы не вводит это всё постоянно руками.
    constexpr int n = 5;
    std::vector<Money> v;
    generateElementsInVector(v, n);

//через std::initializer_list инициализируем вектор случайно сгенерированными объектами класса Money;
    List<Money> list{v[0], v[1], v[2], v[3], v[4]};
    std::cout << "Created vector: ";
    list.print();

    std::cout << "Average: ";
    Money averageMoney = list.average();
    std::cout << averageMoney << std::endl;

    std::cout << "Add average item to the beginning of the vector:\n";
    list.addItemToBeginVector(averageMoney);
    list.print();

    std::cout << "Remove element from the vector. ";
    int eraseItem = generateRandom(0, static_cast<int> (list.getSize()));
    std::cout << "Index of removed element: " << eraseItem << std::endl;
    list.removeElementByIndex(eraseItem);
    list.print();

    std::cout << "Minimum element: ";
    auto minimumElement = list.minElement();
    std::cout << minimumElement << std::endl;

#else
    Money m(10, 20);
    Money z(60, 99);
    List<Money> qq{m, z};
    qq.print();
#endif  //DEBUG

    return 0;
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
    } else if ((typeid(T).name() == d) || (typeid(T).name() == e)) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}

void generateElementsInVector(std::vector<Money>& v, const int& n){
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        v.push_back(m);
    }
}