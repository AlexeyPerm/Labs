#include <stack>
#include <vector>
#include <iostream.>
#include <numeric>
#include "Money.h"
#include "Functions.h"


typedef std::stack<Money> St;
typedef std::vector<Money> Vec;

int main() {
    const int n = generateRandom(4, 10);
    std::cout << "Generated stack with size = " << n << ":\n";
    auto st = makeStack(n);
    printStack(st);
    Vec v = copyStackToVector(st);

//Генерируем случайны элемент. И вставляем его в начало контейнера.
//Нужно для выполнения задания с заменой элементов.
    Money randomMoney = genRandomMoney();
    v.push_back(randomMoney);

    std::cout << "Average: ";
    auto averageMoney = std::accumulate(v.begin(), v.end(), g_m) / static_cast<int> (v.size());
    std::cout << averageMoney << std::endl;
    std::cout << "Add average item to the beginning of the stack:\n";
    std::replace_if(v.begin(), v.end(),
                    std::bind2nd(equalMoney<Money>(), randomMoney), averageMoney);

//В связывателе bind2nd(equalMoney<Money>(), randomMoney) через предикат сравниваем каждый элемент контейнера
//с randomMoney. Если они равны, тогда сравниваемый элемент заменяется на элемент averageMoney. Тем самым
//было выполнено п.3 задачи №1.
    st = copyVectorToStack(v);
    printStack(st);

    v = copyStackToVector(st);
    std::cout << "Duplicate random item:\n";
    //добавляем дубликат какого-либо элемента в контейнере в случайное место.
    int randomNum = generateRandom(0, static_cast<int> (v.size()) - 1);
    int randomPos = generateRandom(0, static_cast<int> (v.size()) - 1); //случайной номер позиции в контейнере
    v.insert(v.begin() + randomNum, v[randomPos]);
    st = copyVectorToStack(v);
    printStack(st);

    v = copyStackToVector(st);
    std::cout << "Remove elements with value = " << v[randomNum] << " from the stack. " << std::endl;
    auto removeElement = v[randomNum];
//Можно сразу передать в erase() возвращаемый итератор функции remove(), как стартовую позицию, но это сложно читается.
//v.erase(remove(v.begin(), v.end(), removeElement), v.end());
//А можно создать переменную, которая будет хранить возвращаемый итератор.
    auto it = remove(v.begin(), v.end(), removeElement);
    v.erase(it, v.end());
    st = copyVectorToStack(v);
    printStack(st);

    v = copyStackToVector(st);
    std::cout << "Sorted stack:\n";
    sort(v.begin(), v.end(), compLess());
    st = copyVectorToStack(v);
    printStack(st);

    v = copyStackToVector(st);
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

    st = copyVectorToStack(v);
    printStack(st);

    return 0;
}

