#include <iostream>
#include <vector>
#include <cstdlib>

typedef std::vector<int> Vec;

//в данном случае auto только для выравнивания
auto makeVector(int) -> Vec;
auto max(const Vec&) -> int;
auto min(const Vec&) -> int;
auto del(Vec&, int) -> void;
auto division(Vec&) -> void;
auto average(const Vec&) -> int;
auto printVector(const Vec&) -> void;
auto addVector(Vec&, int, int) -> void;

int main() {

    try {
        srand(time(nullptr));
        std::vector<int> v;
        std::vector<int>::iterator vi = v.begin();
        constexpr int n = 10;
        v = makeVector(n);
        printVector(v);
        std::cout << "\nAverage : " << std::endl;
        int el = average(v);
        std::cout << el;
        std::cout << "\nEnter position number: ";
        int pos;
        std::cin >> pos;
        if (pos > v.size()) {
            throw 1;
        }
        addVector(v, pos, el);
        printVector(v);

        std::cout << "\nMaximum element: ";
        int nMax = max(v);
        std::cout << nMax;
        std::cout << "\nRemove max element: " << std::endl;
        del(v, nMax);
        printVector(v);
        //делим каждый элемент на минимальное значение вектора.
        division(v);
        std::cout << "\nDivision: " << std::endl;
        printVector(v);


    } catch (int) {
        std::cout << "Error!!!";
    }


    return 0;
}


Vec makeVector(const int n) {
    Vec v;
    for (int i = 0; i < n; ++i) {
        int a = rand() % 100 - 50;
        v.push_back(a);
    }
    return v;
};

void printVector(const Vec& v) {
    for (const auto& x: v) {
        std::cout << x << " ";
    }
}

int average(const Vec& v) {
    long long s = 0;  //сумма элементов в векторе
    for (const auto& item: v) {
        s += item;
    }
    //так как size() возвращает long long, то и переменная n будет этого же типа
    int n = v.size();
    return s / n;
}

void addVector(Vec& v, const int position, const int element) {
    v.insert(v.begin() + position, element);
};

int max(const Vec& v) {
    int n = 0;      //индекс минимального элемента.
    int m = v[0];   //начальное значение максимального элемента
    for (int i = 0; i < v.size(); ++i) {
        if (m < v[i]) {
            m = v[i];
            n = i;
        }
    }
    return n;
}

int min(const Vec& v) {
    int n = 0;      //индекс минимального элемента.
    int m = v[0];   //начальное значение максимального элемента
    for (int i = 0; i < v.size(); ++i) {
        if (m > v[i]) {
            m = v[i];
            n = i;
        }
    }
    return n;
}

void del(Vec& v, const int index) {
    v.erase(v.begin() + index);
}

void division(Vec& v) {
    int m = min(v);
    for (int i = 0; i < v.size(); ++i) {
        v[i] /= v[m];
    }
}