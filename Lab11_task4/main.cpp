#include <stack>
#include <vector>
#include <iostream>
#include "Functions.h"
typedef std::stack<Money> st;
typedef std::vector<Money> vec;

int main() {

//Генерируем размер вектора от 1 до 10. При необходимости диапазон можно изменить.
    const int n = generateRandom(1, 10);
    //constexpr int n = 5;
    std::cout << "Generated stack with size = " << n << ":\n";
    auto st = makeStack(n);
    printStack(st);

    std::cout << "Average: ";
    auto averageMoney = average(st);
    std::cout << averageMoney << std::endl;

    std::cout << "Add average item to the beginning of the stack:\n";
    addElementToBeginStack(st, averageMoney);
    printStack(st);

    std::cout << "Remove element from the vector by index\n";
    int number = generateRandom(0, static_cast<int> (st.size() - 1));
    std::cout << "Index of removed element: " << number << std::endl;
    delByElemNumber(st, number);
    printStack(st);

    std::cout << "Minimum element: ";
    auto minimumElement = minElement(st);
    std::cout << minimumElement << std::endl;

    std::cout << "Every element minus minimumElement:\n";
    subtractMinElement(st);
    printStack(st);
    return 0;
}
