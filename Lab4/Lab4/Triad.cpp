#include "Triad.h"
#include <algorithm>    //all_of()
#include <iostream>

//---------------- Constructors -----------------
Triad::Triad(const Triad& T) {
    first   = T.first;
    second  = T.second;
    third   = T.third;
}

//---------------- Overloadings -----------------
Triad& Triad::operator=(const Triad& other) {
    if (&other == this) {
        return *this;
    }
    this->first  = other.first;
    this->second = other.second;
    this->third  = other.third;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Triad& T) {
    return (out << "first = " << T.first << ", second = " << T.second << ", third = " << T.third << std::endl);
}

std::istream& operator>>(std::istream& in, Triad& T) {
    std::string tmp;
    std::cout << "������� first \n>";
    in >> tmp;
    while (!Triad::InputValidation(tmp)) {
        std::cout << "�� ���������� ��������. ��������� ���� first: \n>";
        in >> tmp;
    }
    T.first = stoi(tmp);

    std::cout << "������� second \n>";
    in >> tmp;
    while (!Triad::InputValidation(tmp)) {
        std::cout << "�� ���������� ��������. ��������� ���� second: \n>";
        in >> tmp;
    }
    T.second = stoi(tmp);

    std::cout << "������� third \n>";
    in >> tmp;
    while (!Triad::InputValidation(tmp)) {
        std::cout << "�� ���������� ��������. ��������� ���� third: \n>";
        in >> tmp;
    }
    T.third = stoi(tmp);

    return in;
}

//--------------- Other functions ---------------
void Triad::Show() const {
    std::cout << "first = " << first << ", second = " << second << ", third = " << third << std::endl;
}

bool Triad::InputValidation(const std::string& s) {
    if (s[0] == '-' || !(std::all_of(s.begin(), s.end(), isdigit))) {
        return false;
    }
    try {
        int tmp = stoi(s);
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n������������ ��������.";
        return false;
    }
    catch (const std::out_of_range& e) {
        std::cout << e.what() << "\n������� ����� ��������.";
        return false;
    }
    return true;
}