#include <iostream>
#include "Vector.h"
#include <ctime>
#include "..\untitled_lab11_2\Time.h"
#include "..\untitled_lab11_2\Time.cpp"

int main() {
    std::srand(std::time(nullptr));
    constexpr int n = 17;   //кол-во элементов в векторе.
    std::cout << "Vector: \n";
    Vector<Time> v(n);
    v.print();

    std::cout << "Average: \n";
    Time s = v.average();
    std::cout << s << std::endl;
    int pos{};
    std::cout << "Enter position number: \n";
    std::cin >> pos;
    v.add(pos, s);
    std::cout << "Add average element: \n";
    v.print();

    return 0;
}
