#include <set>
#include <random>
#include <vector>
#include <iomanip>
#include <iostream>

//std::less<> - сортировка от меньшего к большему
typedef std::multiset<double> ms;

auto makeMultiset(const int& n) -> ms;
auto average(const ms& mset) -> double;
auto printMultiset(const ms& mset) -> void;
auto subtractMinElement(ms& mset, double elem) -> void;
template<class T>
T generateRandom(const T& left, const T& right);  //рандомайзер

int main() {
    constexpr int n = 9;
//Генерируем 9 элементов множества плюс одно дублируем. На выходе получаем множество с 10 элементами.
    ms mset = makeMultiset(n);
    std::cout << "\nCreated stack:\n";
    printMultiset(mset);

    std::cout << "Average: ";
    const auto msetAverage = average(mset);
    std::cout << msetAverage << std::endl;

//В задании говорится, что нужно поместить в начало контейнера среднее арифметическое.
//Но так как все элементы множества хранятся отсортированными, то без лишних заморочек
//добавляем элемент через метод insert().
    std::cout << "Add average item into the multiset:\n";
    mset.insert(msetAverage);
    printMultiset(mset);

//Так как функция find() возвращает итератор, то создадим его.
    auto i = mset.find(msetAverage);
    std::cout << "Remove element <" << *i << "> from the multiset.\n";
    mset.erase(i);  //удаляется элемент с позицией, на которую указывает итератор.
    printMultiset(mset);

    std::cout << "Minimum element: ";
    const double minElement = (*mset.begin());    //begin() возвращает итератор. Получаем значение с помощью *
    std::cout << minElement << std::endl;

    std::cout << "Every element minus minimumElement:\n";
    subtractMinElement(mset, minElement);
    printMultiset(mset);

    return 0;
}

ms makeMultiset(const int& n) {
/*Заполняем множество рандомными значениями. Одно из значений обязательно дублируем, так как
 *это нужно для того, чтобы убедиться, что multiset отрабатывает так, как ожидается.
 * В конце цикла дублируем x.
*/
    ms mset;
    constexpr double right = 10.0;
    double x{};
    for (int i = 0; i < n; ++i) {
        x = generateRandom(0.0, right);
        mset.insert(x);
        if (i == (n - 1)) {
            mset.insert(x);
        }
    }
    return mset;
}

void printMultiset(const ms& ms) {
    for (const auto& item: ms) {
        std::cout << std::fixed << std::setprecision(2) << item << "  ";
    }
    std::cout << std::endl;
}

double average(const ms& ms) {
    double sum = 0;
    for (const auto& item: ms) {
        sum += item;
    }
    return (sum / static_cast<double> (ms.size()));
}

void subtractMinElement(ms& mset, const double elem) {
    std::vector<double> vec;
    int k = 0;
    for (auto i = mset.begin(); i != mset.end(); ++i, ++k) {
        vec.push_back(*i - elem);
    }
    mset.clear();
    for (auto item: vec) {
        mset.insert(item);
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

