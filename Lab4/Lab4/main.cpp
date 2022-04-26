#include "Triad.h"
#include "Time.h"
#include <iostream>

void F1(Triad&);
Triad F2();

int main() {
    setlocale(LC_CTYPE, "rus");

    // ----------- Операция ввода ------------
    Time t1;
    std::cin >> t1;
    std::cout << t1;

    // ------ Конструктор с параметрами ------
    std::cout << std::endl << "============= Конструктор с параметрами =============" << std::endl << std::endl;
    Time t2(32665, 43, 2);
    t2.Show();


    // -------- Операция присваивания --------
    std::cout << std::endl << "== Операция присваивания с последующим выводом на экран. ===" << std::endl << std::endl;
    std::cout << "Создаётся объект класса Time и ему присваиваются значения\nсозданного ранее класса:" << std::endl;
    Time t3;
    t3 = t2;
    std::cout << t3;

    // -------- Операция подстановки ---------
    std::cout << std::endl << "==================== Подстановка ====================" << std::endl << std::endl;
    F1(t2);
    Triad triad;
    triad = F2();
    std::cout << triad;

    return 0;
}

void F1(Triad& t) {
    t.set_first(999);
    std::cout << t;
}

Triad F2() {
    Time t(213, 5, 32);
    return t;
}
