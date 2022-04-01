#include "Student.h"
#include <iostream>

// ------------------------- Constructors -------------------------- //
Student::Student() : Person() {
    rate = .0;
}

Student::Student(const std::string& name, const int age, const double rate) : Person(name, age) {
    this->rate = rate;
}

Student::Student(const Student& st) : Person(st) {
    rate = st.rate;
}

// --------------------- Overridden Functions ---------------------- //

void Student::Show() {
    Person::Show();
    std::cout << "Rate: " << rate << std::endl;
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

Student::~Student() = default;

// --------------------------- Getters ----------------------------- //
double Student::GetRate() const {
    return rate;
}

// --------------------------- Setters ----------------------------- //
void Student::SetRate(double r) {
    rate = r;
}

// --------------------- Overloaded Functions ---------------------- //
Student& Student::operator=(const Student& st) {
    if (this == &st) {
        return *this;
    }
    name = st.name;
    age = st.age;
    rate = st.rate;
    return *this;
}
