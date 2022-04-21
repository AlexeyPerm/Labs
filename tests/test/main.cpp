#include <iostream>
#include <set>
#include <map>

using namespace std;
int main() {

    map<int, int, greater<>> m;
    m.insert(make_pair(1, 2));
    m.insert(make_pair(22, 442));
    m[98] = 999;



    return 0;
}
