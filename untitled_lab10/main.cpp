#include "Person.h"
#include "FileWork.h"
#include <iostream>

int main() {
    Person p;
    char fileName[30]{};
    int k = 0;  //Хранение значения возврата функции makeFile()
    int c = 0;  //переменная выбора пункта меню в switch()
    do {
        std::cout << std::endl;
        std::cout << "1. Make file" << std::endl;
        std::cout << "2. Open file" << std::endl;
        std::cout << "3. Delete record from file" << std::endl;
        std::cout << "4. Add record to file" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> c;
        switch (c) {
            case 1: {
                std::cout << "File name>";
                std::cin >> fileName;
                k = makeFile(fileName);
                if (k < 0) {
                    std::cout << "Can't make the file. Exit...";
                }
                break;
            }
            case 2: {
                std::cout << "Enter filename for output>";
                std::cin >> fileName;
                k = printFile(fileName);
                if (k == 0) {
                    std::cout << "Empty file";
                    break;
                }
                if (k < 0) {
                    std::cout << "Can't read the file";
                }
                break;
            }
            case 3: {
                std::cout << "Enter filename for output>";
                std::cin >> fileName;
                std::cout << "Enter record number>";
                int recordNumber = 0;
                std::cin >> recordNumber;
                delObjectFromFile(fileName, recordNumber);
                if (k < 0) {
                    std::cout << "Can't read the file";
                }
                break;
            }
            case 4: {
                std::cout << "Enter filename for output>";
                std::cin >> fileName;
                std::cout << "Enter record number>";
                int recordNumber = 0;
                std::cout << "Enter person>";
                Person newPerson;
                std::cin >> newPerson;
                k = addObjectToFile(fileName, recordNumber, newPerson);
                if (k < 0) {
                    std::cout << "Can't make the file. Exit...";
                    break;
                }
                if (k == 0) {
                    k = addObjectToEndFile(fileName, newPerson);
                }
                break;
            }
            case 0: {
                std::cout << "Exit program...";
                break;
            }
            default:
                break;
        }
    } while (c != 0);
    return 0;
}