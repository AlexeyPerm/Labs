#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student(const std::string& name, const int& age, const double& rate) : Person(name, age) {
    this->rate = rate;
}

Student::Student(const Student& st) : Person(st) {  //делегируем конструктор для исключения дублирования кода.
    rate = st.rate;
}

// --------------------- Overridden Functions ---------------------- //
void Student::Show() {
    Person::Show();
    std::cout << std::fixed << std::setprecision(2) << "Rate: " << rate << std::endl;
}

void Student::Input() {
    Person::Input();
    std::string tmp;    //временная переменная для хранения введённых числовых значений
    std::cout << "Rate> ";

    std::cin >> tmp;
    while (!CheckCorrectInput(tmp, false)) {
        std::cout << "\nIncorrect input. Try again\n";
        std::cout << "Rate> ";
        std::cin >> tmp;
    }
    rate = std::stod(tmp);
}

// --------------------- Overloaded Functions ---------------------- //
Student& Student::operator=(const Student& st) {
    if (this == &st) {
        return *this;
    }
    name = st.name;
    age  = st.age;
    rate = st.rate;
    return *this;
}
