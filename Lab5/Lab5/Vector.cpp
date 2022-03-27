#include "Vector.h"

Vector::Vector() {
	begin = 0;
	size = cur = 0;
}

Vector::Vector(const int s) {
	begin = new Object * [s];
	size = s;
	cur = 0;
}

Vector::Vector(const Vector &V) {
	begin = V.begin;
	size = V.size;
	cur = V.cur;
}

Vector::~Vector() {
	if (begin != 0) {
		delete[] begin;
		//begin = 0;
	}
}

void Vector::Add(Object *O) {
	if (cur < size) {
		begin[cur] = O;
		cur++;
	}
}

ostream &operator<<(ostream &out, const Vector &V) {
	if (V.size == 0) {
		out << "Empty" << endl;
	}

	//������ ��������� ���� Object �� ������, ��� �������� ������� �������. ���������� ���
	//������������� ���������� ����������.

	Object **p = V.begin;
	for (int i = 0; i < V.cur; i++) {
		(*p)->Show();	//��� ��� ��������� �������� -> ����, ��� �������� �������������, �� ���������� ������.
		p++;
	}
	return out;
}
