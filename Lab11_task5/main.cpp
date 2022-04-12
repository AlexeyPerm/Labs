#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include "../Lab11_task3/Money.cpp"
#include "List.h"

/* Программа должна корректно (но это не точно) работать при типах данных int, long, long long, double, long double
 * Для проверки работы при числовых типах данных раскомментировать строку #define NUMERIC_TYPES и в строке
 * typedef int numType; вместо int указать необходимый тип
 * Если необходимо работать с объектами класса Money, то строку #define NUMERIC_TYPES необходимо закомментировать.
 */
//#define NUMERIC_TYPES
typedef double numType; //можно указать int, long, long long, double, long double,

void generateElementsInStack(std::stack<Money>&   st, const int& n);
void generateElementsInStack(std::stack<numType>& st, const int& n);

template<class T>
std::vector<T> copyStackToVector(std::stack<T> st);
template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

int main() {
#ifndef NUMERIC_TYPES
    //генерирую объекты класса Money для того, чтобы не вводит это всё постоянно руками, ибо лень
        constexpr int n = 5;
        std::stack<Money> st;
        generateElementsInStack(st, n);
        std::vector<Money> myVector = copyStackToVector(st);

    //через std::initializer_list инициализируем вектор случайно сгенерированными объектами класса Money;
        List<Money> list{myVector[4], myVector[3], myVector[2], myVector[1], myVector[0]};
        std::cout << "Created stack:\n";
        list.print();

#else
    constexpr int n = 5;
    std::stack<numType> st;
    generateElementsInStack(st, n);
    std::vector<numType> myVector = copyStackToVector(st);
    //добавляем 5 сгенерированных элементов
    List<numType> list{myVector[4], myVector[3], myVector[2], myVector[1], myVector[0]};
    std::cout << "Created stack:\n";
    list.print();

#endif //NUMERIC_TYPES

    std::cout << "Average: ";
    auto averageMoney = list.average();
    std::cout << averageMoney << std::endl;

    std::cout << "Add average item to the beginning of stack:\n";
    list.addItemToBeginStack(averageMoney);
    list.print();

    std::cout << "Remove element from the stack.";
    int eraseItem = generateRandom(0, static_cast<int> (list.getSize()));
    std::cout << "Index of removed element: " << eraseItem << std::endl;
    list.delByElemNumber(eraseItem);
    list.print();

    std::cout << "Minimum element: ";
    auto minimumElement = list.minElement();
    std::cout << minimumElement << std::endl;

    std::cout << "Every element minus minimumElement:\n";
    list.subtractMinElement();
    list.print();

    return 0;
}


void generateElementsInStack(std::stack<Money>& st, const int& n) {
    constexpr long lRubles = 0;
    constexpr int  iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int  k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        st.push(m);
    }
}

void generateElementsInStack(std::stack<numType>& st, const int& n) {
    for (int i = 0; i < n; ++i) {
        constexpr numType left  = 0;
        constexpr numType right = 100;
        auto k = generateRandom(left, right);
        st.push(k);
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
    }
    else if ((typeid(T).name() == d) || (typeid(T).name() == e) || (typeid(T).name() == ll)) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}

template<class T>
std::vector<T> copyStackToVector(std::stack<T> st) {
    std::vector<T> v;
    while (!st.empty()) {
        //добавить элемент из вершины стека
        v.push_back(st.top());
        st.pop();
    }
    return v;
}