#include <iostream>
#include "List.h"
#include "Money.h"

using namespace std;


int main() {
    Money money;
    cin >> money;
    cout << endl;
    Money money1(111, 3);
    cout << " ============== List <Money> x() ============== " << endl;
    List<Money> x(3, money1);
    cout << x;

    cout << " ============== List <Money> y() ============== " << endl;
    List<Money> y(2, money);
    cout << y << endl;

    cout << " ============== x = y ============== " << endl;
    y = x;
    cout << y << endl;

    cout << " ============== x[1] + y[2] ============== " << endl;
    cout << x[1] + y[2];

    return 0;
}
