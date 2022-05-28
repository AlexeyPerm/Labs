#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include "Money.h"
using namespace std;
typedef vector<Money>VecM;//вектор
typedef priority_queue<Money, vector<Money>> PQue;//очередь с приоритетами

PQue makeQueue(int n) //формирование очереди
{
    PQue q;
    Money m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        q.push(m); //добавление переменной в очередь
    }
    return q;
}
VecM queueToVec(PQue q) //копирование очереди в список
{
    VecM v;
    while (!q.empty()) //пока очередь не пустая
    {
        v.push_back(q.top()); //добавить в списк элемент из очереди
        q.pop();
    }
    return v;
}
PQue vecToQueue(VecM v)
{
    PQue q;
    auto it = v.begin();
    for (int i = 0; i < v.size(); i++)
    {
        q.push(*it);
        it++;
    }
    return q;
}
void printQueue(PQue q)
{
    cout << "\nОчередь с приоритетами:\n";
    while (!q.empty()) //пока очередь не пустая
    {
        cout << q.top() << endl; //вывести элемент из очереди
        q.pop(); //удалить элемент
    }
    cout << endl;
}
//нахождение максимального элемента
Money maxElem(PQue q)
{
    Money max = q.top();
    return max;
}
//нахождение минимального элемента
Money minElem(PQue q)
{
    Money min;
    while (!q.empty()) //пока очередь не пустая
    {
        min = q.top(); //вывести элемент из очереди
        q.pop(); //удалить элемент
    }
    return min;
}
//нахождение среднего арифметического
Money avgInQueue(PQue q)
{
    Money avg;
    while (!q.empty()) //пока очередь не пустая
    {
        avg = avg + q.top(); //вывести элемент из очереди
        q.pop(); //удалить элемент
    }
    avg = avg / int(q.size());
    return avg;
}
//добаление минимального элемента
void addMinInQueue(PQue& q)
{
    q.push(minElem(q));
}
//удаление элементов больше среднего арифметического
void delMoreAvg(PQue& q)
{
   
    
}
//умножение элементов на максимальный
void multElem(PQue& q)
{

}
int main()
{
    system("color F0");
    setlocale(LC_ALL, "ru");
    try
    {
        int n;
        cout << "Задание 1,2:" << endl;
        cout << "Введите количество элементов: "; cin >> n;
        PQue q1 = makeQueue(n);
        printQueue(q1);
        cout << "\nЗадание 3:" << endl;
        cout << "\nдобавление минимального элемента:\n";
        addMinInQueue(q1);
        printQueue(q1);
        cout << "\nЗадание 4:" << endl;
        cout << "\nудаление элементов более среднего арифметического:\n";
        delMoreAvg(q1);
        printQueue(q1);
        cout << "\nЗадание 5:" << endl;
        cout << "\nумножение элементов на максимальный элемент:\n";
        multElem(q1);
        printQueue(q1);
    }
    catch (int)
    {
        cout << "Ошибка!";
    }
}
