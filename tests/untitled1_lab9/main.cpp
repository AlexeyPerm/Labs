#include <iostream>
#include "Vector.h"

int main() {
    try {
        Vector x(1);
        Vector y;
        std::cout << x;
        std::cout << "Number? ";
        int i;
        std::cin >> i;
//Если  i > 2 || i < 0, то сгенерируется исключение
        std::cout << x[i] << std::endl;

        std::cout << "========= y = x + 3 =========" << std::endl;
        y = x + 10;
        std::cout << y;
        std::cout << "========= --x  =========" << std::endl;
        --x;
        std::cout << x;
        --x;
        std::cout << "========= --x  =========" << std::endl;


    }
    catch (int)
    {
        std::cout << "ERROR!!!!" << std::endl;
    }
    return 0;
}