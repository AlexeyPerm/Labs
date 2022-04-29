#include <set>
#include <iostream>
#include "Money.h"
#include "Functions.h"

typedef std::multiset<Money> ms;

int main() {
//Генерируем 9 элементов множества плюс одно дублируем. На выходе получаем множество с 10 элементами.
    constexpr int n = 9;
    ms mset = makeMultiset(n);
    std::cout << "\nCreated multiset:\n";
    printMultiset(mset);

    std::cout << "Average: ";
    const auto msetAverage = average(mset);
    std::cout << msetAverage << std::endl;


    std::cout << "Add average item to the multiset:\n";
    mset.insert(msetAverage);
    printMultiset(mset);

    auto i = mset.find(msetAverage);
    std::cout << "Remove element < " << *i << " > from the multiset.\n";
    mset.erase(i);  //удаляется элемент с позицией, на которую указывает итератор.
    printMultiset(mset);

    std::cout << "Minimum element: ";

    const Money minElement = (*mset.begin());    //begin() возвращает итератор. Получаем значение с помощью *
    std::cout << minElement << std::endl;

    std::cout << "Every element minus minimumElement:\n";
    subtractMinElement(mset, minElement);
    printMultiset(mset);

    return 0;
}

