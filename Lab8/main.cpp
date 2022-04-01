#include "Person.h"
#include "Tree.h"
#include "Student.h"
#include "Dialog.h"
#include <iostream>

int main() {
    Dialog d(4);
    d.Execute();
    std::cout << std::endl; //русский язык

    return 0;
}

