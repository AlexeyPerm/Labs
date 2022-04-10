#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include "../Lab11_task3/Money.cpp"

typedef std::stack<Money> st;
typedef std::vector<Money> vec;

auto min(st s) -> int;
auto delElement(st& s) -> st;
auto average(st s) -> Money;
auto printStack(st s) -> void;
auto makeStack(const int& n) -> st;
auto copyVectorToStack(vec& v) -> st;
auto copyStackToVector(st& s) -> vec;
auto addElementToBeginStack(st& s, const Money& elem) -> void;

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер


int main() {
//Генерируем размер вектора от 1 до 10. При необходимости диапазон можно изменить.
    const int n = generateRandom(1, 10);
    std::cout << "Generated stack with size = " << n << ":\n";
    auto st = makeStack(n);
    printStack(st);

    std::cout << "Average: ";
    auto averageMoney = average(st);
    std::cout << averageMoney << std::endl;

    std::cout << "Add average item to the beginning of the vector:\n";
    addElementToBeginStack(st, averageMoney);
    printStack(st);


    return 0;
}

st makeStack(const int& n) {
    st s;
    constexpr long lRubles = 0;
    constexpr int iKopeks = 0;
    for (int i = 0; i < n; ++i) {
        long r = generateRandom(lRubles, lRubles + 1000);
        int k = generateRandom(iKopeks, iKopeks + 99);
        Money m(r, k);
        s.push(m);
    }
    return s;
}

void printStack(st s) {
//Передаём копию стека, так как при выводе элементы стека удаляются.
    while (!s.empty()) {
        std::cout << s.top() << "  ";
        s.pop();
    }
    std::cout << std::endl;
}

Money average(st s) {
    Money m;
    m = 0;
    int n = s.size();   //количество элементов в стеке
    while (!s.empty()) {
        m += s.top();
        s.pop();
    }
    Money result;  //хранение среднего значения.
    result = m / n;
    return result;
}

vec copyStackToVector(st& s) {
    vec v;
    while (!s.empty()) {
        //добавить элемент из вершины стека
        v.push_back(s.top());
        s.pop();
    }
    s = copyVectorToStack(v);
    return v;
}
st copyVectorToStack(vec& v) {
    st s;
    for (const auto& i: v) {
        s.push(i);
    }
    return s;
}


void addElementToBeginStack(st& s, const Money& elem) {
    vec v = copyStackToVector(s);
//    while (!s.empty()){
//        v.push_back(s.top());
//        s.pop();
//    }
    v.insert(v.begin(), elem);
    s = copyVectorToStack(v);
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
