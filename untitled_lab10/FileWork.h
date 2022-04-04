#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>

int makeFile(const char* fName){
    std::fstream stream(fName, std::ios::out|std::ios::trunc);
    if (!stream){
        return -1;
    }
    int n;  //количество записываемых объектов Person;
    std::cout << "Enter the number of person> ";
    std::cin >> n;
    Person p;
    for (int i = 0; i < n; ++i) {
        std::cin >> p;
        stream << p << "\n";
    }
    stream.close();
    return n;
}