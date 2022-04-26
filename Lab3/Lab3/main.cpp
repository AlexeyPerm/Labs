#include "money.h"
//#define DEBUG


int main() {
    setlocale(LC_ALL, "rus");
#ifndef DEBUG
    std::cout << std::endl << "=================== ����������� �� ���������. ��������� �������� ==================="
              << std::endl << std::endl;
    Money zero;
    std::cout << "��������� ������: \"zero\"." << std::endl;
    zero.show();
    std::cout << std::endl << "���������� ������� ��� ��������� ��������: " << std::endl;
    std::cout << "zero.set_ruble(19)" << std::endl << "zero.set_kopeks(44);" << std::endl << std::endl;
    zero.set_ruble(19);
    zero.set_kopeks(44);
    zero.show();
    std::cout << std::endl << "���������� ������� ��� ��������� ��������: " << std::endl;
    std::cout << "zero.get_ruble();" << std::endl << "zero.get_kopeks();" << std::endl;
    std::cout << zero.get_ruble() << std::endl;
    std::cout << zero.get_kopeks();

    std::cout << std::endl << "===================== ����������� � ����������� =====================" << std::endl
              << std::endl;
    Money first(66, 99);
    std::cout << "Money first(66, 99);" << std::endl;
    std::cout << "��������� ������: \"first\"." << std::endl;
    first.show();

    std::cout << std::endl << "===================== ������������� ��������� ����� � ������ ====================="
              << std::endl << std::endl;
    Money second;
    std::cout << "��������� ������: \"second\"." << std::endl;
    std::cin >> second;
    std::cout << "second = " << second;

    std::cout << std::endl << "===================== ������������� ��������� ������������ ====================="
              << std::endl << std::endl;
    Money third;
    std::cout << R"("third" = "second".)" << std::endl;
    std::cout << "��������� ������: \"third\" ����������� �������� ���������� \"second\"." << std::endl;
    third = second;
    third.show();

    std::cout << std::endl << "===================== ������������� �������� ����������� ���������� ====================="
              << std::endl << std::endl;
    std::cout << "�� ���������� ����������� ����������:" << std::endl;
    zero.set_ruble(-1);
    zero.set_kopeks(0);
    std::cout << "zero = ";
    zero.show();
    std::cout << "\n����� ���������� ����������� ����������:" << std::endl;
    ++zero;
    zero.show();
    std::cout << std::endl;
    std::cout << "�� ���������� ������������ ����������:" << std::endl;
    zero.set_ruble(1);
    zero.set_kopeks(99);
    zero.show();
    std::cout << "\n����� ���������� ������������ ����������:" << std::endl;
    zero++;
    zero.show();

    std::cout << std::endl << "===================== ������������� ��������� ��������� > � < ====================="
              << std::endl << std::endl;
    std::cout << "������ ������: " << zero << std::endl;
    std::cout << "������ ������: " << second << std::endl;;
    if (zero > second) {
        std::cout << "������ ������ ������ �������: true ";
    }
    else {
        std::cout << "������ ������ ������ �������: false ";
    }

    std::cout << std::endl << "===================== ������������� ��������� ��������� > � < ====================="
              << std::endl << std::endl;
    std::cout << "������ ������: " << zero;
    std::cout << "������ ������: " << second;
    if (zero < second) {
        std::cout << "������ ������ ������ �������: true ";
    }
    else {
        std::cout << "������ ������ ������ �������: false ";
    }

#endif // DEBUG

#ifdef DEBUG
    Money x(1,2);
    x.show();

#endif // DEBUG


    return 0;
}