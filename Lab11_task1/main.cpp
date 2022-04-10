#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

typedef std::vector<double> Vec;

auto makeVector(const int& k) -> Vec;
auto average(const Vec& v) -> double;
auto printVector(const Vec& v) -> void;
auto minElement(const Vec& v) -> double;
auto subtractMinElement(Vec& v) -> void;   //вычитание минимального числа элементов массива
auto removeElementByIndex(Vec& v, const int& index) -> void;
auto addItemToBeginVector(Vec& v, const double& item) -> void;
auto generateRandom(const double& l, const double& r) -> double;  //рандомайзер

int main() {
//constexpr: "Programming. Principles and Practice Using C++". Second Edition. Bjarne Stroustrup. Стр. 95
    constexpr int elementsCount = 5;   //Количество элементов в массиве. Смысла делать больше пяти нет.
    Vec v = makeVector(elementsCount);
    std::cout << "Generated vector: ";
    printVector(v);
    std::cout << "Average: ";
    auto averageNum = average(v);
    std::cout << averageNum << std::endl;

    std::cout << "Add average item to the beginning of the vector: ";
    addItemToBeginVector(v, averageNum);
    printVector(v);
    try {
        std::cout << "Remove element from the vector. ";
        std::cout << "Index must be [0;" << v.size() << ")" << std::endl;
        int n;
        std::cout << "Index>";
        std::cin >> n;
        if (n > (v.size() - 1)) {
            throw 1;
        }
        removeElementByIndex(v, n);
        printVector(v);
    } catch (int) {
        std::cout << "Error!" << std::endl;
    }

    std::cout << "Min element: " << minElement(v) << std::endl;
    std::cout << "Every element minus minElement: ";
    subtractMinElement(v);
    printVector(v);
    return 0;
}

Vec makeVector(const int& k) {
//constexpr: "Programming. Principles and Practice Using C++". Second Edition. Bjarne Stroustrup. Стр. 95
    constexpr double left = -10.0; //левая граница случайных чисел
    constexpr double right = 20.0; //правая граница случайных чисел
    Vec v;      //создаём вектор
    for (int i = 0; i < k; ++i) {
        v.push_back(generateRandom(left, right));
    }
    return v;
}

double generateRandom(const double& l, const double& r) {
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(l, r);
    return dis(gen);
}

void printVector(const Vec& v) {
    for (const auto& item: v) {
        std::cout.width(6);     //форматируем вывод, ограничив его в ширину 6 символов
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

double average(const Vec& v) {
    long double sum = 0;
    for (const auto& item: v) {
        sum += item;
    }
    return static_cast<double> (sum / v.size());
}

void addItemToBeginVector(Vec& v, const double& item) {
    v.insert(v.begin(), item);
}

void removeElementByIndex(Vec& v, const int& index) {
    v.erase(v.begin() + index);
}

double minElement(const Vec& v) {
    double min = v[0];
    for (const auto& item: v) {
        if (item < min) {
            min = item;
        }
    }
    return min;
}

void subtractMinElement(Vec& v) {
    double min = minElement(v);
    for (auto& item: v) {
        item -= min;
    }
}