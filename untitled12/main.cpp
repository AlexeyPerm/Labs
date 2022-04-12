#include <iostream>
#include <map>

typedef std::map<int, int> TMap;
typedef TMap::iterator it;

TMap makeMap(const int& n) {
    TMap m;
    int a;
    for (int i = 0; i < n; ++i) {
        std::cout << " > ";
        std::cin >> a;
        m.insert(std::make_pair(i, a));
    }
    return m;
}

void printMap(TMap& m) {
    for (const auto&[key, value]: m) {
        std::cout << key << " : " << value << "  " << std::endl;
    }
}

int average(TMap& m) {
    int s{};
    for (const auto&[key, value]: m) {
        s += value;
    }
    int average = s / m.size();
    return average;
}

int maximum(TMap m) {
    it i = m.begin();
    int num = 0;    //номер максимального элемента
    int k = 0;      //счётчик элементов
    int max = (*i).second;      //*i - возвращаем элемент словаря, на который указывает итератор
    while (i != m.end()) {
        if (max < (*i).second) {
            max = (*i).second;
            num = k;
        }
        ++k;
        ++i;
    }
    return num;
}

int main() {

    int n = 0;
    std::cout << "N? ";
    std::cin >> n;
    TMap m = makeMap(n);
    printMap(m);

    int averageMap = average(m);
    std::cout << " average = " << averageMap << std::endl;
    std::cout << "add average:\n";
    m.insert(std::make_pair(m.size(), averageMap));
    printMap(m);

    int max = maximum(m);
    std::cout << " Number of max element = " << max << std::endl;
    std::cout << " remove max element \n" ;
    m.erase(max);
    printMap(m);


    return 0;
}
