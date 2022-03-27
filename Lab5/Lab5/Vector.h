#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector {
public:
	Vector();
	Vector(const int);
	Vector(const Vector &);
	~Vector();
	void Add(Object *);
	friend ostream &operator << (ostream &, const Vector &);

private:
	Object **begin; //”казатель типа Object на адрес массива, где будут хранитьс€ объекты классов.
	int size;
	int cur;
};