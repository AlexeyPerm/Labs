#include <map>
#include <vector>
#include <iostream.>
//#include <numeric>
#include "Money.h"
#include "Functions.h"

typedef std::map<int, Money> Map;

int main() {

    const int n = generateRandom(4, 10);
    std::cout << "Generated stack with size = " << n << ":\n";
    Map myMap = makeMap(n);
    printMap(myMap);

/*std::accumulate() суммирует элементы в контейнере.
* Третий параметр функции - с какого значения будут производиться вычисления. В нём же хранится промежуточный итог
* суммирования и он же является возвращаемым типом.
* https://en.cppreference.com/w/cpp/algorithm/accumulate
 *https://youtu.be/kxYJkyQuYQU
 * constexpr inline Money accumulate(_InputIterator __first, _InputIterator __last,
 *                                   _Tp __init, _BinaryOperation __binary_op)
*/
    std::cout << "Average item: ";
    Money averageMoney = std::accumulate(myMap.begin(), myMap.end(),
                                        g_m, accumulateMapValues()) / static_cast<int> (myMap.size());
    std::cout << averageMoney << std::endl;
    std::cout << "Add average item to the map:\n";
    myMap.emplace(std::pair(myMap.size() + 1, averageMoney));
    printMap(myMap);

    int randomNum = generateRandom(1, static_cast<int> (myMap.size()) - 1);
    std::cout << "Remove elements with key = " << randomNum << " from the map. " << std::endl;
    myMap.erase((randomNum));
    printMap(myMap);

    std::cout << "Minimum element: ";
//Не знаю, не опасно ли так делать, но в переменную minElement сразу передаётся значение в разыменованном указателе на
//минимальный элемент
    auto it = std::min_element(myMap.begin(), myMap.end(),
                               [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; });
    std::cout << it->first << " : " << it->second << std::endl;
    Money minElement = it->second;

    std::cout << "Every element minus minimumElement:\n";
    std::for_each(myMap.begin(), myMap.end(),
                  [&minElement](auto& item) { item.second -= minElement; });
    printMap(myMap);
    return 0;
}