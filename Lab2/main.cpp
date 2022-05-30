#include <iostream>
#include <algorithm>    //используется функция all_of()
#include "vehicle.h"

Vehicle make_Vehicle();
void print_Vehicle(Vehicle &v);
static bool CorrectInputCost(const std::string&, int&);

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "\n=================== Without parameters ===================\n\n";
    Vehicle first;
    first.show();

    std::cout << "\n===================== With parameters =====================\n\n";
    Vehicle second("Vaz", "2101", 1330);
    second.show();

    std::cout << "\n================== Copy (initialization) =================\n\n";
    Vehicle third = second;
    third.set_brand("Kia");
    third.set_model("Seltos");
    third.set_cost(9965);
    third.show();
    std::cout << "Address: " << &third << std::endl;

    std::cout << "\n============= Copy (class as class parameter) ============\n\n";
    Vehicle fourth(third);
    fourth.show();
    std::cout << "Address: " << &fourth << std::endl;

    std::cout << "\n===================== make_Vehicle  ====================\n\n";
    first = make_Vehicle();
    print_Vehicle(first);

    return 0;
}

Vehicle make_Vehicle()
{
    std::string n{};
    std::string s{};
    std::string costString{};
    int costInt{};
    std::cout << "ведите марку: \n>";
    getline(std::cin, n);
    std::cout << "ведите модель: \n>";
    getline(std::cin, s);
    std::cout << "ведите стоимость: \n>";
    getline(std::cin, costString);
    while (!CorrectInputCost(costString, costInt))
    {
        getline(std::cin, costString);
    }

    Vehicle temp(n, s, costInt);
    return temp;
}
void print_Vehicle(Vehicle &v){
    v.show();
}

bool CorrectInputCost(const std::string& str, int& costInt)
{
    if (!(std::all_of(str.begin(), str.end(), isdigit)))
    {    //проверяем все элементы строки на число
        std::cout << "Стоимость должна быть целым числом. Повторите ввод: \n>";
        return false;
    }
    try
    {    //Пробую на вкус обработку исключений
        costInt = stoi(str);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << "\nВведите число поменьше: \n>";
        return false;
    }
    return true;
}