#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <iomanip>

typedef std::vector<double> Vec;    //не
auto makeVector(const int& k) -> Vec;
auto randomDouble(const double& l, const double& r) -> double;  //рандомайзер
auto printVector(const Vec &v) -> void;

int main() {
    Vec v = makeVector(10);
    printVector(v);

    return 0;
}

Vec makeVector(const int& k) {
    Vec v;      //создаём вектор
    constexpr double left = -10.0; //левая граница случайных чисел
    constexpr double right = 20.0; //правая граница случайных чисел

    for (int i = 0; i < k; ++i) {
        v.push_back(randomDouble(left, right));
    }
    return v;
}

double randomDouble(const double& l, const double& r) {
    /* -------------------------------------------------------------------------------------------------
     * std::random_device rd генератор для недетерминированных, зависящий от непредсказуемого источинка,
     * случайных чисел.
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(l, r);
    return dis(gen);
}

void printVector(const Vec &v){
    for (const auto& item: v) {
        std::cout.width(5);     //форматируем вывод, ограничив его в ширину 5 символов
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << item << std::endl;
    }
}