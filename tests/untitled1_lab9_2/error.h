#pragma once

#include <iostream>
#include <string>

class error {
    std::string str;
public:

    error(std::string s) { str = s; }

    void what() { std::cout << str << std::endl; }
};
