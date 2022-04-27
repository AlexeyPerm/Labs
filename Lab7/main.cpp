#include <random>
#include <iostream>
#include "List.h"
#include "Money.h"

/* Программа должна корректно (но это не точно) работать при типах данных int, long, long long, double, long double
 * Для проверки работы при числовых типах данных раскомментировать строку #define NUMERIC_TYPES и в строке
 * typedef int numType; вместо int указать необходимый тип
 * Если необходимо работать с объектами класса Money, то строку #define NUMERIC_TYPES необходимо закомментировать.
 */
//#define NUMERIC_TYPES

typedef double numType;
template<class T>
T generateRandom(const T& left, const T& right);

void generateElementsInList(List<numType>& lst, const int& n);
void generateElementsInList(List<Money>&   lst, const int& n);

int main() {
    constexpr int n = 5;        //Количество элементов в контейнере. Можно изменить при желании.
#ifdef NUMERIC_TYPES
    List<numType> list(n);
    generateElementsInList(list, n);
#else
    List<Money> list(n);
    generateElementsInList(list, n);
#endif //NUMERIC_TYPES
    //list.print();
    std::cout << list;
    std::cout << "list[2] = " << list[2] << std::endl;
    std::cout << "list[2] + list[3] = " << list[2] + list[3] << std::endl;


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
    const char* f = typeid(float).name();
    const char* d = typeid(double).name();
    const char* ll = typeid(long long).name();
    const char* e = typeid(long double).name();

    std::random_device rd;
    std::mt19937 gen(rd());

    if (typeid(T).name() == i || typeid(T).name() == l || (typeid(T).name() == ll)) {
        std::uniform_int_distribution<> dis(left, right);
        return dis(gen);
    }
    else if ((typeid(T).name() == d) || (typeid(T).name() == e || (typeid(T).name() == f))) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}

void generateElementsInList(List<numType>& lst, const int& n) {
    constexpr numType left = 0;
    constexpr numType right = 5000000;
    for (int i = 0; i < n; ++i) {
        numType k = generateRandom(left, right);
        lst[i] = k;
    }
}

void generateElementsInList(List<Money>& lst, const int& n) {
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        lst[i] = m;
    }
}
