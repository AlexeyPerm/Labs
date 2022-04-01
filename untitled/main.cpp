#include "Car.h"
#include "Object.h"
#include "Lorry.h"
#include "Vector.h"
#include "Dialog.h"
#include <iostream>

int main() {
Car* a = new Car("test", 150, 1555);
Vector v(2);
 Object* p = a;
  v.Add();
    std::cout << "======== p = b (lorry)========" << std::endl;
    v.Show();


    return 0;
}


