#include <iostream>
#include "Time.h"
#include "Vector.h"
using namespace std;


int main() {
	setlocale(LC_CTYPE, "rus");

	Time t1(999,59,59);
	cout << t1 << endl;
	
	Time *pt = &t1;
	pt->Show();
	cout << endl;

	Triad tr(1,2,3);
	Triad *ptr = &tr;
	ptr->Show();

	cout << "=====================================" << endl << endl;
	Vector v(1);
	Object *p = &t1;
	v.Add(&t1);
	p = &tr;
	v.Add(&tr);


	cout << v;

	return 0;
}