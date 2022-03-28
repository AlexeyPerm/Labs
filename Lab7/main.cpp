#include <iostream>
#include "List.h"
#include "Money.h"

int main() {
    Money z (0, 99);
    Money x(10, 20);
    Money t;
    t = x + z;
    std::cout << t;

    return 0;
}
