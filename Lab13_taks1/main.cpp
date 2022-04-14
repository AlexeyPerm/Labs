#include <vector>
#include <iostream>
#include <algorithm>
#include "Money.h"
#include "Functions.h"

typedef std::vector<Money> Vec;
int main() {
//Генерируем размер вектора от 4 до 10. При необходимости диапазон можно изменить.
    const int n = generateRandom(4, 10);
    std::cout << "Generated vector with size = " << n << ":\n";
    Vec v = makeVector(n);
    printVector(v);
    std::cout << "Average: ";

/*std::accumulate() суммирует элементы в контейнере.
* Последний параметр функции - с какого значения будут производиться
* вычисления. И он же является возвращаемым типом данных.
* https://en.cppreference.com/w/cpp/algorithm/accumulate
 *https://youtu.be/kxYJkyQuYQU
*/
    auto averageMoney = std::accumulate(v.begin(), v.end(), g_m) / static_cast<int> (v.size());
    std::cout << averageMoney << std::endl;

    std::cout << "Add average item to the beginning of the vector:\n";
    v.insert(v.begin(), averageMoney);
    printVector(v);

    std::cout << "Duplicate random item:\n";
    //добавляем дубликат какого-либо элемента в контейнере в случайное место.
    int randomIndex = generateRandom(0, static_cast<int> (v.size()) - 1);
    int randomPos = generateRandom(0, static_cast<int> (v.size()) - 1); //случайной номер позиции в контейнере
    v.insert(v.begin() + randomIndex, v[randomPos]);
    printVector(v);

    std::cout << "Remove element with value = " << v[randomIndex] << " from the vector. " << std::endl;
    auto removeElement = v[randomIndex];
//Можно сразу передать в erase() возвращаемый итератор функции remove(), как стартовую позицию. Сложно читается.
//v.erase(remove(v.begin(), v.end(), removeElement), v.end());
//а создать переменную, которая будет хранить возвращаемый итератор.
    auto it = remove(v.begin(), v.end(), removeElement);
    v.erase(it, v.end());
    printVector(v);

    std::cout << "Sorted vector:\n";
    sort(v.begin(), v.end(), compLess());
    printVector(v);

    return 0;
}


