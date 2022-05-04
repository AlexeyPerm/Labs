#include <set>
#include <random>
#include <vector>
#include <iostream>
//#include "Money.h"
#include "../Lab12_task2/Money.h"
#include "List.h"

/* Программа должна корректно (но это не точно) работать при типах данных int, long, long long, double, long double
 * Для проверки работы при числовых типах данных раскомментировать строку #define NUMERIC_TYPES и в строке
 * typedef int numType; вместо int указать необходимый тип
 * Если необходимо работать с объектами класса Money, то строку #define NUMERIC_TYPES необходимо закомментировать.
 */
#define NUMERIC_TYPES

typedef double numType; //можно указать int, long, long long, double, long double,

void generateElementsInMultiset(std::vector<Money>&, const int& n);
void generateElementsInMultiset(std::vector<numType>&, const int& n);

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер


int main() {
#ifndef NUMERIC_TYPES

//Генерируем 9 элементов множества плюс одно дублируем. На выходе получаем множество с 10 элементами.
    constexpr int n = 5;
    //List<Money> list(n);  //если хочется вводить данные руками %-)
    std::vector<Money> myVector;    //закомментировать при ручном вводе.
    generateElementsInMultiset(myVector, n);    //закомментировать при ручном вводе.
    List<Money> list{myVector[5], myVector[4], myVector[3],
                     myVector[2], myVector[1], myVector[0]};    //закомментировать при ручном вводе.
    std::cout << "\nCreated multiset:\n";
    list.print();
#else
    constexpr int n = 5;
    //List<numType> list(n);    //если хочется вводить данные руками %-)
    std::vector<numType> myVector;  //закомментировать при ручном вводе.
    generateElementsInMultiset(myVector, n);    //закомментировать при ручном вводе.
    List<numType> list{myVector[5], myVector[4], myVector[3],
                       myVector[2], myVector[1], myVector[0]};   //закомментировать при ручном вводе.
    std::cout << "\nCreated multiset:\n";
    list.print();

#endif //NUMERIC_TYPES
    std::cout << "Average: ";
    const auto msetAverage = list.average();
    std::cout << msetAverage << std::endl;

    std::cout << "Add average item to the multiset:\n";
    list.addItemToMultiSet(msetAverage);
    list.print();

    std::cout << "Remove element from the multiset:\n";
    list.remove(msetAverage);
    list.print();

    std::cout << "Minimum element: ";
    const auto minElement = list.minElement();    //begin() возвращает итератор. Получаем значение с помощью *
    std::cout << minElement << std::endl;

    std::cout << "Every element minus minimumElement:\n";
    list.subtractMinElement();
    list.print();

    return 0;
}


void generateElementsInMultiset(std::vector<Money>& vec, const int& n) {
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        vec.push_back(m);
    }
    vec.push_back(*vec.end());
}

void generateElementsInMultiset(std::vector<numType>& vec, const int& n) {
    for (int i = 0; i < n; ++i) {
        constexpr numType left = 0;
        constexpr numType right = 100;
        auto k = generateRandom(left, right);
        vec.push_back(k);
    }
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
