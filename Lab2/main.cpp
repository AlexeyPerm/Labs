#include <iostream>
#include <algorithm>    //������������ ������� all_of()
#include <windows.h>    //SetConsoleCP(1251);
#include "vehicle.h"

Vehicle make_Vehicle();
static bool CorrectInputCost(const std::string&, int&);

int main()
{
    setlocale(LC_ALL, "rus");
    //SetConsoleCP(866);
    std::cout << "\n=================== Without parameters ===================\n\n";
    Vehicle first;
    first.show();

    std::cout << "\n===================== With parameters =====================\n\n";
    Vehicle second("���", "2101", 1330);
    second.show();

    std::cout << "\n================== Copy (initialization) =================\n\n";
    Vehicle third = second;
    third.set_brand("Kia");
    third.set_model("Seltos");
    third.set_cost(9965);
    third.show();
    std::cout << "����� ��������: " << &third << std::endl;

    std::cout << "\n============= Copy (class as class parameter) ============\n\n";
    Vehicle fourth(third);
    fourth.show();
    std::cout << "����� ��������: " << &fourth << std::endl;

    std::cout << "\n===================== Copy (function) ====================\n\n";
    first = make_Vehicle();
    first.show();
    std::cout << std::endl;
    first.show();

    return 0;
}

Vehicle make_Vehicle()
{
    std::string n{};
    std::string s{};
    std::string costString{};
    int costInt{};
    std::cout << "������� �����: \n>";
    getline(std::cin, n);
    std::cout << "������� ������: \n>";
    getline(std::cin, s);
    std::cout << "������� ���������: \n>";
    getline(std::cin, costString);
    while (!CorrectInputCost(costString, costInt))
    {
        getline(std::cin, costString);
    }

    Vehicle temp(n, s, costInt);
    return temp;
}

bool CorrectInputCost(const std::string& str, int& costInt)
{
    if (!(std::all_of(str.begin(), str.end(), isdigit)))
    {    //��������� ��� �������� ������ �� �����
        std::cout << "��������� ������ ���� ����� ������. ��������� ����: \n>";
        return false;
    }
    try
    {    //������ �� ���� ��������� ����������.
        costInt = stoi(str);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << "\n������� ����� ��������: \n>";
        return false;
    }
    return true;
}