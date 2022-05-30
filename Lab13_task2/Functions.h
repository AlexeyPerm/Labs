#pragma once

#include <stack>
#include <vector>
#include <random>

typedef std::stack<Money> St;
typedef std::vector<Money> Vec;

const Money g_m;

auto printStack(St s) -> void;
auto genRandomMoney() -> Money;
auto makeStack(const int& n) -> St;
auto copyVectorToStack(Vec& v) -> St;
auto copyStackToVector(St& s) -> Vec;

// --------------------- Predicates --------------------- //

template<class T>
struct equalMoney : std::binary_function<T, T, bool> {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs == rhs;
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

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер


Money genRandomMoney() {
    long r = generateRandom(0, 1000);
    int k = generateRandom(0, 99);
    Money genMoney(r, k);
    return genMoney;
}

St makeStack(const int& n) {
    St s;
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k =  generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        s.push(m);
    }
    return s;
}

void printStack(St s) {
    //Передаём копию стека, так как при выводе элементы стека удаляются.
    while (!s.empty()) {
        std::cout << s.top() << "  ";
        s.pop();
    }
    std::cout << std::endl;
}

Vec copyStackToVector(St& s) {
    Vec v;
    while (!s.empty()) {
        //добавить элемент из вершины стека
        v.push_back(s.top());
        s.pop();
    }
    //s = copyVectorToStack(v);
    return v;
}

St copyVectorToStack(Vec& v) {
    St s;
    for (int i = (v.size() - 1); i >= 0; --i) {
        s.push(v[i]);
    }
    v.clear();  //очищаем вектор
    return s;
}


void addElementToBeginStack(St& s, const Money& elem) {
    Vec v = copyStackToVector(s);
    v.insert(v.begin() + v.size(), elem);   //помещаем элемент в начало стека.
    while (!s.empty()) {
        s.pop();
    }
    s = copyVectorToStack(v);
}

void delByElemNumber(St& s, const int& number) {
    Vec v = copyStackToVector(s);
    while (!s.empty()) {
        s.pop();
    }
    int i = v.size() - 1;
    do {
        if (i != (v.size() - 1 - number)) {
            s.push(v[i]);
        }
        --i;
    } while (i >= 0);

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