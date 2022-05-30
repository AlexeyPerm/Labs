#include <iostream>
#include <iomanip>    //setprecision
#include "calculation.h"

calculation make_calculation(double, int, int);

int main() {
    std::setlocale(LC_ALL, "rus");

    //--------------------- Method calculation::Init() --------------------

    calculation initCalc;
    calculation initCalc_2;
    std::cout << "\n------------ Method Init() ------------\n";
    initCalc.Init(4.54, 10, 30);
    initCalc_2.Init(4.54, 10, 28);
    std::cout << std::fixed << std::setprecision(2);
    initCalc.Show();
    std::cout << "Sum = " << initCalc.summa() << std::endl << std::endl;
    initCalc_2.Show();
    std::cout << "Sum = " << initCalc_2.summa() << std::endl;


    //------------------------- Pointer to Struct -------------------------
    //
    //������ ��������� � ����������� � ����� ���������
    std::cout << "\n---------  Pointer to Struct ---------\n";
    calculation* pCalcPointer = new calculation{};
    pCalcPointer->Init(12, 25, 31);
    pCalcPointer->Show();
    std::cout << "Sum = " << pCalcPointer->summa() << std::endl;
    delete pCalcPointer;


    //--------------------------- Static Array ----------------------------

    std::cout << "\n---------  Static Array ---------\n";
    int const count = 2;
    calculation staticArrayCalc[count];

    //�����, ��� ��� ����������� rfor() ����������������, ��� ����� for �� ������ �������. ��������� ���� ������������.
    //https://docs.microsoft.com/en-us/cpp/cpp/range-based-for-statement-cpp?view=msvc-170
    //https://en.cppreference.com/w/cpp/language/range-for
    for (auto& i: staticArrayCalc) {
        i.Read();
        i.Show();
        std::cout << "Sum = " << i.summa() << std::endl << std::endl;
    }

    //--------------------------- Dynamic Array ---------------------------

    std::cout << "---------  Dynamic Array ---------\n";
    calculation* dynamicArrayCalc = new calculation[count]{};
    for (int i = 0; i < count; i++) {
        dynamicArrayCalc[i].Read();
        dynamicArrayCalc[i].Show();
        std::cout << std::fixed << "Sum =  " << dynamicArrayCalc[i].summa() << std::endl << std::endl;
    }
    delete[] dynamicArrayCalc;

    //---------------------- func make_calculation() ----------------------
    std::cout << "\n-------  func make_calculation() -------\n";
    double x{};
    int y{}, z{};
    std::cout << "�����: \n> ";
    std::cin >> x;
    std::cout << "���������� ������������ ����: \n> ";
    std::cin >> y;
    std::cout << "���������� ���� � ������: \n> ";
    std::cin >> z;
    calculation C = make_calculation(x, y, z);
    C.Show();
    std::cout << "����� = " << C.summa();

    return 0;
}

calculation make_calculation(const double F, const int S, const int D) {
    calculation tmp{};
    tmp.Init(F, S, D);
    return tmp;
}
