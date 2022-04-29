#include <iostream>
#include <cmath>
//10-8
using namespace std;
class Myclass {
public:
    double a;
    double x;
    Myclass(double _a, double _x) :a(_a), x(_x) {}
    double f() {
        const int n = 11;
        double sum = 0.0;
        for (int k = 1; k != n + 1; k++)
        {
            sum += a * k / pow(x,k);
            a++;
        }
        return sum;
    }
};

int main()
{
    double a, x;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter a:";
    cin >> a;
    Myclass obj(a, x);
    cout << obj.f() << endl;
    return 0;
}