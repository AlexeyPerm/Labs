#include <map>
//#include <vector>
#include <iostream.>
//#include <numeric>
#include "Money.h"
#include "Functions.h"

typedef std::map<int, Money> Map;

int main() {

    const int n = generateRandom(4, 10);
    std::cout << "Generated stack with size = " << n << ":\n";
    auto myMap = makeMap(n);
    printMap(myMap);
    int elementCount = static_cast<int>(myMap.size());

//Генерируем случайны элемент. И вставляем его в начало контейнера.
//Нужно для выполнения задания с заменой элементов.
    Money randomMoney = genRandomMoney();
    myMap.insert(std::make_pair(elementCount + 1, randomMoney));

/*std::accumulate() суммирует элементы в контейнере.
* Третий параметр функции - с какого значения будут производиться вычисления. В нём же хранится промежуточный итог
* суммирования и он же является возвращаемым типом.
* https://en.cppreference.com/w/cpp/algorithm/accumulate
 *https://youtu.be/kxYJkyQuYQU
 * constexpr inline Money accumulate(_InputIterator __first, _InputIterator __last,
 *                                   _Tp __init, _BinaryOperation __binary_op)
*/
    std::cout << "Average: ";
    auto averageMoney = std::accumulate(myMap.begin(), myMap.end(),
                                        g_m, accumulateMapValues()) / static_cast<int> (myMap.size());
    std::cout << averageMoney << std::endl;
    std::cout << "Add average item to the beginning of the vector:\n";




    return 0;
}
