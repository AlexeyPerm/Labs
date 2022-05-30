#include <vector>
#include <iostream>
#include <algorithm>
#include "Money.h"
#include "Functions.h"

typedef std::vector<Money> Vec;

int main() {
//Генерируем размер вектора от 4 до 10. При необходимости диапазон можно изменить.
    const int n = generateRandom(4, 10);

    std::cout << "Generated vector with size = " << n << ":\n";
    Vec v = makeVector(n);
    printVector(v);

//Генерируем случайны элемент. И вставляем его в начало контейнера.
//Нужно для выполнения задания с заменой элементов.
    Money randomMoney = genRandomMoney();
    v.insert(v.begin(), randomMoney);

/*std::accumulate() суммирует элементы в контейнере.
* Последний параметр функции - с какого значения будут производиться
* вычисления. И он же является возвращаемым типом данных.
* https://en.cppreference.com/w/cpp/algorithm/accumulate
 *https://youtu.be/kxYJkyQuYQU
*/
    std::cout << "Average: ";
    auto averageMoney = std::accumulate(v.begin(), v.end(), g_m) / static_cast<int> (v.size());
    std::cout << averageMoney << std::endl;
    std::cout << "Add average item to the beginning of the vector:\n";

//В связывателе bind2nd(equalMoney<Money>(), randomMoney) через предикат сравниваем каждый элемент контейнера
//с randomMoney. Если они равны, тогда сравниваемый элемент заменяется на элемент averageMoney. Тем самым
//было выполнено п.3 задачи №1.
    std::replace_if(v.begin(), v.end(),
                    std::bind2nd(equalMoney<Money>(), randomMoney), averageMoney);
    printVector(v);


    std::cout << "Duplicate random item:\n";
    //добавляем дубликат какого-либо элемента в контейнере в случайное место.
    int randomNum = generateRandom(0, static_cast<int> (v.size()) - 1);
    int randomPos = generateRandom(0, static_cast<int> (v.size()) - 1); //случайной номер позиции в контейнере
    v.insert(v.begin() + randomNum, v[randomPos]);
    printVector(v);


    std::cout << "Remove elements with value = " << v[randomNum] << " from the vector. " << std::endl;
    auto removeElement = v[randomNum];
//Можно сразу передать в erase() возвращаемый итератор функции remove(), как стартовую позицию, но это сложно читается.
//v.erase(remove(v.begin(), v.end(), removeElement), v.end());
//А можно создать переменную, которая будет хранить возвращаемый итератор.
    auto it = remove(v.begin(), v.end(), removeElement);
    v.erase(it, v.end());
    printVector(v);

    std::cout << "Sorted vector:\n";
    sort(v.begin(), v.end(), compLess());
    printVector(v);


/*  std::greater<>()  - это предикат, означающий строгое неравенство >. Если сравниваются объекты класса, то
 * соответствующий оператор обязательно должен быть перегружен. В bind2nd(std::greater<Money>(), l) идёт сравнение
 * элемента, на который указывает итератор с константным элементом. Константный элемент при этом заранее был создан.
 * bind2nd() используется того, чтобы связать пользовательский предикат или предикат из std:: со сравниваемым
 * константным элементом. То есть говорим предикату, чтобы он работал с ним.
 * Функция count_if(), если смотреть её прототип, возвращает значение с типом long long.
 * constexpr inline long long int count_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
 *
*/
//Генерируем случайное число (куда ж без этого?), с которым будем сравнивать элементы контейнера.
    randomNum = generateRandom(500, 800);
    Money x(randomNum, 0);
    auto a = std::count_if(v.begin(), v.end(), std::bind2nd(std::greater<Money>(), x));
    std::cout << "Items more than value = " << x.getRubles() << ": " << a << std::endl;

//Выводим на экран первый попавшийся элемент, у которого кол-во рублей чётное.
    auto b = std::find_if(v.begin(), v.end(), evenRubles());
    std::cout << "First element with even rubles: " << *b << std::endl;

    std::cout << "Minimum element: ";
//Не знаю, не опасно ли так делать, но в переменную minElement сразу передаётся значение в разыменованном указателе на
//минимальный элемент
    Money minElement = *(std::min_element(v.begin(), v.end()));
    std::cout << minElement << std::endl;

/* for_each() применяется для каждого элемента в контейнере.
 *Используется лямбда-функция для вычитания из каждого элемента контейнера минимального элемента этого же контейнера.
 *Сигнатура лямбды: [](){}
 *[](принимаемый параметр функции){тело функции}. [] - сюда передаётся объект, находящийся вне области видимости
 *анонимной функции. В данном случае ссылка на Money minElement;
*/
    std::cout << "Every element minus minimumElement:\n";
    std::for_each(v.begin(), v.end(), [&minElement](auto& item) {
        item -= minElement;
    });
    printVector(v);

    return 0;
}


