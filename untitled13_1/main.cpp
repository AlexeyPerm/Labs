#include <vector>
#include <iostream>
#include <algorithm>
#include "../Lab12_task3/Money.cpp"

typedef std::vector<Money> Vec;
Vec makeVector(int n);
void printVector(Vec& v);
Money average(Vec& v);


Money g_m;

struct Greater_s {
    bool operator()(Money m) {
        return m > g_m;
    }
};

struct compLess {
    bool operator()(Money m1, Money m2) {
        return m1 > m2;
    }
};


int main() {
    int n = 3;
    //std::cin >> n;
    Vec v;
    v = makeVector(n);
    printVector(v);
    Vec::iterator it;

    it = std::max_element(v.begin(), v.end());
    std::cout << "Max = " << *it << std::endl;
    Money x = *it;
    Money averMoney = average(v);
    std::cout << "Aver = " << averMoney << std::endl;

    //replace_if(v.begin(), v.end(), Greater_s(), x);
    //std::cout << "Change" << std::endl;
    //printVector(v);


    std::cout << "sorted <" << std::endl;
    sort(v.begin(), v.end(), compLess());
    printVector(v);

    return 0;
}

Vec makeVector(const int n) {
    Money a;
    Vec v;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        v.push_back(a);
    }
    return v;
}

void printVector(Vec& v) {
    for (const auto& item: v) {
        std::cout << item << "  ";
    }
    std::cout << std::endl;
}

Money average(Vec& v) {
    long long sum = 0;
    for (const auto& item: v) {
        sum += item.getRubles() * 100 + item.getKopeks();
    }
    Money m;
    const long long tmp = (sum / v.size());
    m.setRubles(static_cast<int> (tmp / 100));
    m.setKopeks(static_cast<int> (tmp % 100));
    return m;
}