#include "Vector.h"
#include "Car.h"
#include "Lorry.h"
#include <iostream>


// ------------------------- Constructors -------------------------- //
Vector::~Vector() {
    if (begin) {
        delete[] begin;
        begin = nullptr;
    }
}

Vector::Vector() {
    size = 0;
    begin = nullptr;
    current = 0;
}

Vector::Vector(const int size) {
    this->size = size;
    current = 0;
    begin = new Object* [size];
}

// ---------------------------- Methods ---------------------------- //
void Vector::Add(Object* z) {    //добавление объекта, на который указывает указатель p в вектор
    if(z){
        if (current < size) {
            begin[current] = z;
            current++;
        }
        return;
    }
    Object* p ;
    //Выбор из объектов двух возможных классов
    std::cout << "1. Car " << std::endl;
    std::cout << "2. Lorry " << std::endl;
    int y;  //хранит значение выбора
    std::cin >> y;
    switch (y) {
        case 1: {
            Car* c = new (Car);
            c->Input();
            p = c;
            if (current < size) {
                begin[current] = p;
                current++;
            }
            break;
        }
        case 2: {
            Lorry* l = new (Lorry);
            l->Input();
            p = l;
            if (current < size) {
                begin[current] = p;
                current++;
            }
            break;
        }
        default: {
            return;
        }
    }
}

void Vector::Show() const {
    if (current == 0) {
        std::cout << "Empty!" << std::endl;
    }
    Object** p = begin;
    for (int i = 0; i < current; ++i) {
        (*p)->Show();
        p++;    //передвигаем указатель на следующий объект.
    }
}

void Vector::Del() {
    if (current == 0) {
        return;
    }
    current--;
}

// --------------------- Overloaded Functions ---------------------- //
int Vector::operator()() const {
    return current;
}

// --------------------- Overridden Functions ---------------------- //

void Vector::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        Object** p = begin;
        for (int i = 0; i < current; ++i) {
            (*p)->HandleEvent(e);
            p++;
        }
    }
}

