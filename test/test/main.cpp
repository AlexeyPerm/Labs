#include <iostream>
#include <set>
#include <map>

std::set<int>& fillSet(const int count, std::set<int>& mSet) {
    int elem{};
    for (int i = 0; i < count; ++i) {
        std::cout << "Elem>";
        std::cin >> elem;
        mSet.insert(elem);
    }
    return mSet;
}

void printSet(std::set<int>& mSet) {
    for (const auto& item: mSet) {
        std::cout << item << "  ";
    }
}

int main() {

    std::set<int> mySet;

    fillSet(4, mySet);

    printSet(mySet);


    return 0;
}