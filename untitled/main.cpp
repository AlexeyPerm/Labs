#include "Car.h"
#include "Object.h"
#include "Lorry.h"
#include "iostream"
#include "Vector.h"

int main() {
    Car* a = new Car("Toyota", 8, 240);
    Lorry* b = new Lorry("kia", 149, 4, 800);

    Vector v(10);
    Object *p = a;
    v.Add(p);
    v.Show();

    std::cout << "======== p = b (lorry)========" << std::endl;
    p = b;
    v.Add();
    v.Show();

    return 0;
}