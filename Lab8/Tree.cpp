#include "Tree.h"
#include "Person.h"
#include "Student.h"
#include <iostream>

// ------------------------- Constructors -------------------------- //
Tree::Tree() {
    size = 0;
    current = 0;
    begin = nullptr;
}

Tree::~Tree() {
    if (begin) {
        delete[] begin;
        begin = nullptr;
    }
}

Tree::Tree(const int size) {
    current = 0;
    this->size = size;
    begin = new Object* [size];
}

// ---------------------------- Methods ---------------------------- //

void Tree::Show() const {
    if (current == 0) {
        std::cout << "Empty!" << std::endl;
    }
    Object** p = begin;
    for (int i = 0; i < current; ++i) {
        (*p)->Show();
        p++;    //����������� ��������� �� ��������� ������.
    }
}

void Tree::Del() {
    if (!current) {
        return;
    }
    current--;
}

void Tree::Add(Object* z) {
    if (z) {    //���� �������� � �������� ��������� ������, �� ��������� ��� � ������ � ������� �� �������.
        if (current < size) {
            begin[current] = z;
            current++;
        }
        return;
    }
    Object* o;
    std::cout << "1. Person " << std::endl;
    std::cout << "2. Student " << std::endl;
    int y;
    std::cin >> y;
    switch (y) {
        case 1: {
            Person* person = new(Person);   //������ ���������. �������������� ��� ������������� �� ���������.
            person->Input();
            o = person;
            if (current < size) {
                begin[current] = o;
                current++;
            }
            break;
        }
        case 2: {
            Student* st = new(Student);
            st->Input();
            o = st;
            if (current < size) {
                begin[current] = o;
                current++;
            }
        }
        default:
            return;
    }
}

// --------------------- Overridden Functions ---------------------- //
void Tree::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        Object** p = begin;
        for (int i = 0; i < current; ++i) {
            (*p)->HandleEvent(e);
            p++;
        }
    }
}
