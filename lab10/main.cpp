#include <iostream>
#include "Money.h"
#include "FileWork.h"

int main() {
    char fileName[30]{};
    int k = 0;  //Хранение значения возврата функции makeFile()
    int c = 0;  //переменная выбора пункта меню в switch()
    do {
        std::cout << std::endl;
        std::cout << "1. Make file" << std::endl;
        std::cout << "2. Open file" << std::endl;
        std::cout << "3. Delete record from file" << std::endl;
        std::cout << "4. Add record to file" << std::endl;
        std::cout << "5. Change record in file" << std::endl;
        std::cout << "6. Remove all records greater than" << std::endl;
        std::cout << "7. Add multiple records" << std::endl;
        std::cout << "8. Halve all objects with exact value" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << ">";
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
                removeObjectFromFile(fileName, recordNumber);
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
                std::cin >> recordNumber;
                std::cout << "Enter person:" << std::endl;
                Money newMoney;
                std::cin >> newMoney;
                k = addObjectToFile(fileName, recordNumber, newMoney);
                if (k < 0) {
                    std::cout << "Can't read the file. Exit...";
                    break;
                }
                if (k == 0) {
                    k = addObjectToEndFile(fileName, newMoney);
                }
                break;
            }
            case 5: {
                std::cout << "Enter filename for output>";
                std::cin >> fileName;
                std::cout << "Enter record number>";
                int recordNumber = 0;
                std::cin >> recordNumber;
                std::cout << "Enter person:" << std::endl;
                Money newMoney2;
                std::cin >> newMoney2;
                k = changeFileInStream(fileName, recordNumber, newMoney2);
                if (k < 0) {
                    std::cout << "Can't read the file. Exit...";
                    break;
                }
                if (k == 0) {
                    std::cout << "No such record";
                }
                break;
            }
            case 6: {
                std::cout << "Enter filename for output>";
                std::cin >> fileName;
                std::cout << "Enter value>";
                long value = 0;
                std::cin >> value;
                k = removeObjectsGreaterThanValue(fileName, value);
                if (k < 0) {
                    std::cout << "Can't read the file. Exit...";
                    break;
                }
                if (k == 0) {
                    std::cout << "No such record";
                }
                break;
            }
            case 7: {
                std::cout << "Enter filename for output>";
                std::cin >> fileName;
                std::cout << "Enter elements count>";
                int elementsCount = 0;
                std::cin >> elementsCount;
                std::cout << "Enter record number>";
                int elemIndex = 0;
                std::cin >> elemIndex;
                k = addMultipleObjectsInFiles(fileName, elementsCount, elemIndex);
                if (k < 0) {
                    std::cout << "Can't read the file. Exit...";
                    break;
                }
                if (k == 0) {
                    std::cout << "No such records";
                }
                break;
            }
            case 8: {
                std::cout << "Enter filename for output>";
                std::cin >> fileName;
                std::cout << "Enter elements value>";
                long elemValue;
                std::cin >> elemValue;
                k = halveObjectInFileByValue(fileName, elemValue);
                if (k < 0) {
                    std::cout << "Can't read the file. Exit...";
                    break;
                }
                if (k == 0) {
                    std::cout << "No such records";
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
