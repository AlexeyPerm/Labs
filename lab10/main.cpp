#include <iostream>
#include "Money.h"

int main()
{
    Money m(100, 23);
    Money n(100, 24);

    std::cout << (n > m);
    return 0;
}
