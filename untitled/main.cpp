#include "Car.h"
#include "Object.h"
#include "Lorry.h"
#include "iostream"
#include "Vector.h"

int main() {
    Car* a = new Car;
    a->Input();
    Lorry* b = new Lorry;
    b->Input();

    Vector v(10);
    Object *p = a;
    v.Add(p);
    v.Show();




    delete a;
    delete b;
    return 0;
}