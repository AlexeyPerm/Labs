#include <iostream>
#include "List.h"

class Test {
public:
    Test() { a = 0; b = 0;}
    Test(int a, int b) : a(a), b(b) {};

private:
    int a;
    int b;
};

int main() {
    Test t(123, 345);

    List<Test> a(3, t);
    std::cout << a << std::endl;
    return 0;
}
