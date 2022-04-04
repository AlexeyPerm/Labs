#include "Person.h"

// --------------------- Overloaded Functions ---------------------- //
Person& Person::operator=(const Person& p) {
    if (this == &p) {
        return *this;
    }
    age = p.age;
    name = p.name;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << "Name: " << p.name << std::endl;
    out << "Age: " << p.age << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Person& p) {
    std::cout << "Name > ";
    std::cin >> p.name;
    std::cout << "Age > ";
    std::cin >> p.age;
    return in;
}

std::fstream& operator<<(std::fstream& fout, const Person& p) {
    fout << "Name: " << p.name << std::endl;
    fout << "Age: " << p.age << std::endl;
    return fout;
}

std::fstream& operator>>(std::fstream& fin, Person& p) {
    std::cout << "Name > ";
    std::cin >> p.name;
    std::cout << "Age > ";
    std::cin >> p.age;
    return fin;
}