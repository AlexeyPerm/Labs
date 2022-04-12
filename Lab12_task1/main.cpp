#include <iostream>
#include <random>
#include <set>


template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

typedef std::set<int, std::less<double>> tset;


int main() {
    constexpr int n = 10;
    tset s; //создание множества
    for (int i = 0; i < n; ++i) {
        constexpr double right = 10.0;
        s.insert(generateRandom(0.0, right));
    }

    for (const auto& item: s) {
        std::cout << item << "  ";
    }

    return 0;
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
