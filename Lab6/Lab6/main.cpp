#include <iostream>
#include "List.h"
#include "Iterator.h"

int main() {
    List list1{21, 32, 234, 234098, 9999};  //Создаём объект через список инициализации
    std::cout << "list1 = ";
    for (int i = 0; i < list1.getSize(); ++i) {
        std::cout << list1[i] << "   ";
    }

    std::cout << std::endl;
    std::cout << "list2 = ";
    List list2(3, 999);             //Создаём объект размером 3 и заполняем его числом 999
    for (int i = 0; i < list2.getSize(); ++i) {
        std::cout << list2[i] << "   ";
    }
    std::cout << std::endl;

    List list1Copy = list1;         //Создаём объект list1Copy, инициализируем его копированием.
    std::cout << "&list1 = " << &list1 << std::endl << "&list1Copy = " << &list1Copy << std::endl;
    std::cout << "list1Copy = " << list1Copy;
    std::cout << "list1[2] = " << list1[2] << std::endl;

    List list3(3);
    std::cout << "list3.getSize() = " << list3.getSize() << std::endl;

    std::cout << "================== Iterators ==================" << std::endl;
    Iterator it1 = list1.last();        //Создаём объект класса Iterator и указываем его на начало контейнера
    Iterator it2 = list2.first();       //Создаём объект класса Iterator и указываем его на начало контейнера
    std::cout << "it1 = " << *it1 << std::endl << "it2 = " << *it2 << std::endl;
    std::cout << "it1 - 2 = " << *(it1 - 2) << std::endl;
    std::cout << "list1[1]  + list2[2] = " << (list1[1] + list2[2]);

    return 0;
}
