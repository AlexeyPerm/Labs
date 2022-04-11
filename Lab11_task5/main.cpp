#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include "../Lab11_task3/Money.cpp"
#include "List.h"

std::vector<Money> copyStackToVector(std::stack<Money> st);
void generateElementsInStack(std::stack<Money>& st, const int& n);
template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

int main() {
//генерирую объекты класса Money для того, чтобы не вводит это всё постоянно руками, ибо лень
    constexpr int n = 5;
    std::stack<Money> st;
    generateElementsInStack(st, n);
    std::vector<Money> myVector = copyStackToVector(st);

//через std::initializer_list инициализируем вектор случайно сгенерированными объектами класса Money;
    List<Money> list{myVector[4], myVector[3], myVector[2], myVector[1], myVector[0]};
    std::cout << "Created stack:\n";
    list.print();

    std::cout << "Average: ";
    Money averageMoney = list.average();
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

    std::cout << "Every element minus minimumElement: ";
    list.subtractMinElement();
    list.print();



    return 0;
}

void generateElementsInStack(std::stack<Money>& st, const int& n) {
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        st.push(m);
    }
}

template<class T>
T generateRandom(const T& left, const T& right) {
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

std::vector<Money> copyStackToVector(std::stack<Money> st) {
    std::vector<Money> v;
    while (!st.empty()) {
        //добавить элемент из вершины стека
        v.push_back(st.top());
        st.pop();
    }
    return v;
}