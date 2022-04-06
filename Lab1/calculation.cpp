#include "calculation.h"
#include <string>    //string
#include <iostream>
#include <algorithm>    //count

bool calculation::CheckCorrectInput(const std::string& input)
{
    if (input[0] == '-')
    {    //�������� �� ���� �����. �����.
        std::cout << "������� �������� ������ ���� ������ ����: \n> ";
        return false;
    }

    //std::count ���������� ���-�� �������� (�����) �� �������� ������.
    if (std::count(input.begin(), input.end(), '.') > 1)
    {
        std::cout << "������������ ��������. ��������� ����: \n> ";
        return false;
    }

    //static_cast<int> - �������������� ����. ����� � �����, ��� ��� ����� ���������, ��� int (value).
    //�������������� ������������, ������ ��� ���������� �������� �� �������������� �����, ��� ���
    //length() ���������� size_t (����������. ���. 237). ���������, ������ ��� ���������, ��� �����.
    for (char i : input)
    {
        if (!(isdigit(i) || i == '.'))
        {
            std::cout << "������������ ��������. ��������� ����: \n> ";
            return false;
        }
    }
    return true;
}

bool calculation::CheckCorrectInput(const double F, const int S, const int D)
{
    if (F < 0)
    {
        std::cout << "�� ���������� �������� ������.\n";
        return false;
    } else if (D < 0 || D > 31 || D < 28)
    {
        std::cout << "�� ���������� �������� ���������� ������� ���� \n";
        return false;
    } else if (D < 0 || S > D)
    {
        std::cout << "�� ���������� �������� ���� ������ ";
        return false;
    }
    return true;
}

void calculation::Show() const
{
    std::cout << "Salary = " << first << std::endl;
    std::cout << "Working Days = " << second << std::endl;
    std::cout << "Days in Month = " << daysInMonth << std::endl;
}

void calculation::Read()
{
    //���� ���������� ������� �����������, �� ������������ ������� � ����� ����� ������ ���� �������, � �� �����.
    //��-�� ����� stod() �������� ������� �����. ������� ��������� ��������� � ����. �������, ��� ������������ �������� �����.
    setlocale(LC_NUMERIC, "eng");
    std::cout << "�����: \n> ";
    std::string a{};
    std::cin >> a;
    while (!CheckCorrectInput(a))
    {
        std::cin >> a;
    }
    first = stod(a);
    //calculation::daysInMonth = 0;

    std::string b{};    //Second. ���������� ������������ ����
    std::string c{};    //daysInMonth
    bool correctInput = false;    //���� �������� ������������ �����.

    while (!correctInput)
    {

        std::cout << "���������� ������������ ����: \n> ";
        std::cin >> b;
        while (!CheckCorrectInput(b))
        {
            std::cin >> b;
        }
        second = stoi(b);

        std::cout << "���������� ���� � ������: \n> ";
        std::cin >> c;
        while (!CheckCorrectInput(c))
        {
            std::cin >> c;
        }
        daysInMonth = stoi(c);

        if (second > daysInMonth)
        {
            std::cout
                    << "���������� ������������ ���� �� ����� ���� ������ ���������� ���� � ������. ��������� ����.\n";
        } else if (daysInMonth > 31 || daysInMonth < 28)
        {
            std::cout << "�� ���������� �������� ���������� ���� � ������. ��������� ����\n";
        } else
        {
            correctInput = true;
        }
    }
}

void calculation::Init(const double F, const int S, int const daysInMonth)
{
    if (CheckCorrectInput(F, S, daysInMonth))
    {
        first = F;
        second = S;
        this->daysInMonth = daysInMonth;
    } else
    {
    //� ������� �������, ���� ������� make_calculation() ��������� ��������� ���������,
    //�� ��������� ������� ��������� � ��������� ������
        std::cout << "\nExit...\n";
        exit(0);
    }
}

double calculation::summa() const
{
    return first / daysInMonth * second;
}
