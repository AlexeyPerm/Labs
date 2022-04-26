#include <iostream>
#include "Time.h"
#include "Vector.h"


int main() {
    setlocale(LC_CTYPE, "rus");

    Time time1(999, 59, 59);
    std::cout << time1 << std::endl;

    Time* pTime = &time1;
    pTime->Show();
    std::cout << std::endl;

    Triad triad1(1, 2, 3);
    Triad* pTriad = &triad1;
    pTriad->Show();

    Vector v(2);
    Object* p = &time1;
    v.Add(&time1);
    p = &triad1;
    v.Add(&triad1);
    std::cout << "\nRESULT:\n";
    std::cout << v;

    return 0;
}