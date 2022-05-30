#include <iostream>
#include "Money.h"

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "=========== Конструктор по умолчанию. Параметры обнулены ============" << std::endl;
    Money zero;
    std::cout << "Объект класса: \"zero\"." << std::endl;
    zero.print();

    std::cout << std::endl << "Используем сеттеры для изменения значений: " << std::endl;
    std::cout << "zero.set_ruble(15)" << std::endl << "zero.set_kopeks(99);" << std::endl;
    zero.setRubles(15);
    zero.setKopeks(99);
    std::cout << "Используем геттеры для получения значений: " << std::endl;
    std::cout << zero.getRubles() << std::endl;
    std::cout << zero.getKopeks();

    std::cout << std::endl << "===================== Конструктор с параметрами =====================" << std::endl;
    Money first(66, 99);
    std::cout << "Money first(66, 99);" << std::endl;
    std::cout << "Экземпляр класса: \"first\"." << std::endl;
    first.print();

    std::cout << std::endl << "============== Перегруженные операторы ввода и вывода ==============="
              << std::endl;

    Money second;
    std::cout << "Экземпляр класса: \"second\"." << std::endl;
    std::cin >> second;
    std::cout << "second = " << second;

    std::cout << std::endl << "=============== Перегруженные операторы присваивания ================"
              << std::endl;
    Money third;
    std::cout << R"("third" = "second".)" << std::endl;
    std::cout << "Экземпляр класса: \"third\" присваивает значения экземпляра \"second\"." << std::endl;
    third = second;
    third.print();

    std::cout << std::endl << "=========== Перегруженные оператор префиксного инкремента ==========="
              << std::endl;
    std::cout << "До применения префиксного инкремента:" << std::endl;
    zero.setRubles(1);
    zero.setKopeks(99);
    std::cout << "zero = ";
    zero.print();
    std::cout << "\nПосле применения префиксного инкремента:" << std::endl;
    ++zero;
    zero.print();
    std::cout << "\nПосле применения постфиксного инкремента:" << std::endl;
    zero++;
    zero.print();

    std::cout << std::endl << "============== Перегруженные операторы сравнения > и < =============="
              << std::endl;

    std::cout << "Первый объект: " << zero << std::endl;
    std::cout << "Второй объект: " << second << std::endl;;
    if (zero > second) {
        std::cout << "Первый объект больше второго: true ";
    }
    else {
        std::cout << "Первый объект больше второго: false ";
    }

    return 0;
}
