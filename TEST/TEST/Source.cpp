#include <iostream>
#include <string>
using namespace std;

class Point {
public:
	explicit Point() {
		x = y = z = 0;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;

	}

private:
	int x;
	int y;
	int z;
};