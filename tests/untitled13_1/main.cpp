#include <map>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


int main() {
    using Map = std::map<int, int>;
    Map q;
    Map s;
    using ggg = pair<int, int>;
    q.insert(make_pair(3, 2));
    q.insert(make_pair(1, 3));
    q.insert(make_pair(2, 3));
    q.insert(make_pair(4, 1515));
    vector<pair<int, int>> z;

    auto k = pair(2, 1111);
    auto v = pair(999, 444);

    for (const auto& i: q) {
        z.push_back(i);
    }

    for (auto& item: z) {
        if (item.second == 1515) {
            item.second = 0;
        }
    }

    q.erase(q.begin(), q.end());
    for (const auto& item: z) {
        q.insert(item);
    }

    for (const auto& item: q) {
        std::cout << item.first << " : " << item.second << endl;
    }

    return 0;
}