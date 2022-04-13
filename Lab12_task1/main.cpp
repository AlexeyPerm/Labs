#include <iostream>
#include <random>
#include <iomanip>
#include <set>

//std::less<> - сортировка от меньшего к большему
typedef std::multiset<double, std::less<>> mset;

auto average(mset& ms) -> double;
auto printMultiset(mset& ms) -> void;
auto makeMultiset(const int& n) -> mset;

template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

int main() {
    constexpr int n = 9;
//Генерируем 9 элементов множества плюс одно дублируем. На выходе получаем множество с 10 элементами.
    auto mset = makeMultiset(n);
    std::cout << "Created stack:\n";
    printMultiset(mset);

    std::cout << "Average: ";
    auto msetAverage = average(mset);
    std::cout << msetAverage << std::endl;

//В задании говорится, что нужно поместить в начало контейнера среднее арифметическое.
//Но так как все элементы множества хранятся отсортированными, то без лишних заморочек
//добавляем элемент через метод insert().
    std::cout << "Add average item to the multiset:\n";
    mset.insert(msetAverage);
    printMultiset(mset);

//Так как функция find() возвращает итератор, то создадим его.
    mset::iterator it;
   //it = mset.find(average);
    //std::cout << (*it);


    return 0;
}

mset makeMultiset(const int& n) {
/*Заполняем множество рандомными значениями. Одно из значений обязательно дублируем, так как
 *это нужно для того, чтобы убедиться, что multiset отрабатывает так, как ожидается.
 * В конце цикла дублируем x.
*/
    mset ms;
    for (int i = 0; i < n; ++i) {
        constexpr double right = 10.0;
        const double x = generateRandom(0.0, right);
        ms.insert(x);
        if (i == (n - 1)) {
            ms.insert(x);
        }
    }
    return ms;
}

void printMultiset(mset& ms) {
    for (const auto& item: ms) {
        std::cout << std::fixed << std::setprecision(2) << item << "  ";
    }
    std::cout << std::endl;
}

double average(mset& ms) {
    double sum = 0;
    for (auto& item: ms) {
        sum += item;
    }
    return (sum / ms.size());
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

