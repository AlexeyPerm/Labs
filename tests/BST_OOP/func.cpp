#include "func.h"

int getPos(int index, int width, int curLevel, int maxLevel) {
    int x1 = 0;
    int x2 = static_cast<int> (std::pow(2, curLevel) - 1);
    int y1 = static_cast<int> (width / std::pow(2, curLevel + 1));
    int y2 = static_cast<int> (width - std::pow(2, maxLevel - curLevel));
    if (x1 == x2) return y1;
// y=x(y2-y1)/(x2-x1)-x1(y2-y1)/(x2-x1)+y1
// y=kx+m: k=(y2-y1)/(x2-x1), m=-x1(y2-y1)/(x2-x1)+y1=-x1*k+y1
    double k = (y2 - y1) / (x2 - x1);
    double m = -x1 * k + y1;
    int y = static_cast<int> (k * index + m);
    return y;
}

