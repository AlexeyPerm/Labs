#include <iostream>
#include <cmath>
#include <stdexcept>

class Error {
public:
    void what() {
        std::cout << "Error! Negative number";
    }
};

double areaTriangle(const double& a, const double& b, const double& c) {
    double halfPerimeter = (a + b + c) / 2;
    if (halfPerimeter <= 0) {
        throw Error();
    }
    double x = halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c);
    if (x <= 0) {
        throw Error();
    }
    return std::sqrt(x);

}

int main() {
    double a = -15.;
    double b = 5.;
    double c = 5.;
    try {
        std::cout << areaTriangle(a, b, c);
    }
    catch (Error& e) {
        e.what();
    }


    return 0;
}

