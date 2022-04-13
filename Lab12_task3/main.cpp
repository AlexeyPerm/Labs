#include <set>
#include <random>
#include <vector>
#include <iostream>
#include "Money.h"
#include "List.h"

typedef double numType; //можно указать int, long, long long, double, long double,
void generateElementsInMultiset(std::stack<Money>&   st, const int& n);
void generateElementsInMultiset(std::stack<numType>& st, const int& n);

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер


int main() {
//Генерируем 9 элементов множества плюс одно дублируем. На выходе получаем множество с 10 элементами.
    constexpr int n = 9;
    List<Money> lst(n);
    lst.print();



    return 0;
}





void generateElementsInMultiset(std::stack<Money>& st, const int& n) {
    constexpr long lRubles = 0;
    constexpr int  iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int  k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        st.push(m);
    }
}

void generateElementsInMultiset(std::stack<numType>& st, const int& n) {
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
