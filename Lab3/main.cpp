#include <iostream>
#include "Money.h"

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "=========== ����������� �� ���������. ��������� �������� ============" << std::endl;
    Money zero;
    std::cout << "������ ������: \"zero\"." << std::endl;
    zero.print();

    std::cout << std::endl << "���������� ������� ��� ��������� ��������: " << std::endl;
    std::cout << "zero.set_ruble(15)" << std::endl << "zero.set_kopeks(99);" << std::endl;
    zero.setRubles(15);
    zero.setKopeks(99);
    std::cout << "���������� ������� ��� ��������� ��������: " << std::endl;
    std::cout << zero.getRubles() << std::endl;
    std::cout << zero.getKopeks();

    std::cout << std::endl << "===================== ����������� � ����������� =====================" << std::endl;
    Money first(66, 99);
    std::cout << "Money first(66, 99);" << std::endl;
    std::cout << "��������� ������: \"first\"." << std::endl;
    first.print();

    std::cout << std::endl << "============== ������������� ��������� ����� � ������ ==============="
              << std::endl;

    Money second;
    std::cout << "��������� ������: \"second\"." << std::endl;
    std::cin >> second;
    std::cout << "second = " << second;

    std::cout << std::endl << "=============== ������������� ��������� ������������ ================"
              << std::endl;
    Money third;
    std::cout << R"("third" = "second".)" << std::endl;
    std::cout << "��������� ������: \"third\" ����������� �������� ���������� \"second\"." << std::endl;
    third = second;
    third.print();

    std::cout << std::endl << "=========== ������������� �������� ����������� ���������� ==========="
              << std::endl;
    std::cout << "�� ���������� ����������� ����������:" << std::endl;
    zero.setRubles(1);
    zero.setKopeks(99);
    std::cout << "zero = ";
    zero.print();
    std::cout << "\n����� ���������� ����������� ����������:" << std::endl;
    ++zero;
    zero.print();
    std::cout << "\n����� ���������� ������������ ����������:" << std::endl;
    zero++;
    zero.print();

    std::cout << std::endl << "============== ������������� ��������� ��������� > � < =============="
              << std::endl;

    std::cout << "������ ������: " << zero << std::endl;
    std::cout << "������ ������: " << second << std::endl;;
    if (zero > second) {
        std::cout << "������ ������ ������ �������: true ";
    }
    else {
        std::cout << "������ ������ ������ �������: false ";
    }

    return 0;
}
