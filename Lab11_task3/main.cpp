#include <iostream>
#include <random>
#include "List.h"
#include "Money.h"
//#define DEBUG

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

int main() {
#ifndef DEBUG
//    const int n = generateRandom(1, 10);
//    std::cout << "Generated vector with size = " << n << ":\n";
    List<Money> list(5);
    std::cout << "Created vector: ";
    list.print();

    std::cout << "Average: ";
    Money averageMoney = list.average();
    std::cout << averageMoney << std::endl;

    std::cout << "Add average item to the beginning of the vector:\n";
    list.addItemToBeginVector(averageMoney);
    list.print();




#else
    List<int> list(7);
    std::cout << list.average();
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