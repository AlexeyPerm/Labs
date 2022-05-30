#include "Vector.h"

Vector::Vector() {
    begin = nullptr;
    size  = cur = 0;
}

Vector::Vector(const int s) {
    cur   = 0;
    size  = s;
    begin = new Object* [s];
}

Vector::Vector(const Vector& V) {
    size  = V.size;
    cur   = V.cur;
    begin = V.begin;
}

Vector::~Vector() {
    if (begin != nullptr) {
        delete[] begin;
    }
}

void Vector::Add(Object* O) {
    if (cur < size) {
        begin[cur] = O;
        cur++;
    }
}

std::ostream& operator<<(std::ostream& out, const Vector& V) {
    if (V.size == 0) {
        out << "Empty" << std::endl;
    }

    //������ ��������� ���� Object �� ������, ��� �������� ������� �������. ���������� ���
    //������������� ���������� ����������.
    Object** p = V.begin;
        for (int i = 0; i < V.cur; i++) {
        (*p)->Show();    //��� ��� ��������� �������� -> ����, ��� �������� �������������, �� ���������� ������.
        p++;
    }
    return out;
}
