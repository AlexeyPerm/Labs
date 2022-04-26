#include "money.h"
//#define DEBUG


int main() {
    setlocale(LC_ALL, "rus");
#ifndef DEBUG
    std::cout << std::endl << "=================== Конструктор по умолчанию. Параметры обнулены ==================="
              << std::endl << std::endl;
    Money zero;
    std::cout << "Экземпляр класса: \"zero\"." << std::endl;
    zero.show();
    std::cout << std::endl << "Используем сеттеры для изменения значений: " << std::endl;
    std::cout << "zero.set_ruble(19)" << std::endl << "zero.set_kopeks(44);" << std::endl << std::endl;
    zero.set_ruble(19);
    zero.set_kopeks(44);
    zero.show();
    std::cout << std::endl << "Используем геттеры для получения значений: " << std::endl;
    std::cout << "zero.get_ruble();" << std::endl << "zero.get_kopeks();" << std::endl;
    std::cout << zero.get_ruble() << std::endl;
    std::cout << zero.get_kopeks();

    std::cout << std::endl << "===================== Конструктор с параметрами =====================" << std::endl
              << std::endl;
    Money first(66, 99);
    std::cout << "Money first(66, 99);" << std::endl;
    std::cout << "Экземпляр класса: \"first\"." << std::endl;
    first.show();

    std::cout << std::endl << "===================== Перегруженные операторы ввода и вывода ====================="
              << std::endl << std::endl;
    Money second;
    std::cout << "Экземпляр класса: \"second\"." << std::endl;
    std::cin >> second;
    std::cout << "second = " << second;

    std::cout << std::endl << "===================== Перегруженные операторы присваивания ====================="
              << std::endl << std::endl;
    Money third;
    std::cout << R"("third" = "second".)" << std::endl;
    std::cout << "Экземпляр класса: \"third\" присваивает значения экземпляра \"second\"." << std::endl;
    third = second;
    third.show();

    std::cout << std::endl << "===================== Перегруженные оператор префиксного инкремента ====================="
              << std::endl << std::endl;
    std::cout << "До применения префиксного инкремента:" << std::endl;
    zero.set_ruble(-1);
    zero.set_kopeks(0);
    std::cout << "zero = ";
    zero.show();
    std::cout << "\nПосле применения префиксного инкремента:" << std::endl;
    ++zero;
    zero.show();
    std::cout << std::endl;
    std::cout << "До применения постфиксного инкремента:" << std::endl;
    zero.set_ruble(1);
    zero.set_kopeks(99);
    zero.show();
    std::cout << "\nПосле применения постфиксного инкремента:" << std::endl;
    zero++;
    zero.show();

    std::cout << std::endl << "===================== Перегруженные операторы сравнения > и < ====================="
              << std::endl << std::endl;
    std::cout << "Первый объект: " << zero << std::endl;
    std::cout << "Второй объект: " << second << std::endl;;
    if (zero > second) {
        std::cout << "Первый объект больше второго: true ";
    }
    else {
        std::cout << "Первый объект больше второго: false ";
    }

    std::cout << std::endl << "===================== Перегруженные операторы сравнения > и < ====================="
              << std::endl << std::endl;
    std::cout << "Первый объект: " << zero;
    std::cout << "Второй объект: " << second;
    if (zero < second) {
        std::cout << "Первый объект меньше второго: true ";
    }
    else {
        std::cout << "Первый объект меньше второго: false ";
    }

#endif // DEBUG

#ifdef DEBUG
    Money x(1,2);
    x.show();

#endif // DEBUG


    return 0;
}