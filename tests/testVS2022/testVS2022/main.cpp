#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include "Money.h"
using namespace std;
typedef vector<Money>VecM;//������
typedef priority_queue<Money, vector<Money>> PQue;//������� � ������������

PQue makeQueue(int n) //������������ �������
{
    PQue q;
    Money m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        q.push(m); //���������� ���������� � �������
    }
    return q;
}
VecM queueToVec(PQue q) //����������� ������� � ������
{
    VecM v;
    while (!q.empty()) //���� ������� �� ������
    {
        v.push_back(q.top()); //�������� � ����� ������� �� �������
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
    cout << "\n������� � ������������:\n";
    while (!q.empty()) //���� ������� �� ������
    {
        cout << q.top() << endl; //������� ������� �� �������
        q.pop(); //������� �������
    }
    cout << endl;
}
//���������� ������������� ��������
Money maxElem(PQue q)
{
    Money max = q.top();
    return max;
}
//���������� ������������ ��������
Money minElem(PQue q)
{
    Money min;
    while (!q.empty()) //���� ������� �� ������
    {
        min = q.top(); //������� ������� �� �������
        q.pop(); //������� �������
    }
    return min;
}
//���������� �������� ���������������
Money avgInQueue(PQue q)
{
    Money avg;
    while (!q.empty()) //���� ������� �� ������
    {
        avg = avg + q.top(); //������� ������� �� �������
        q.pop(); //������� �������
    }
    avg = avg / int(q.size());
    return avg;
}
//��������� ������������ ��������
void addMinInQueue(PQue& q)
{
    q.push(minElem(q));
}
//�������� ��������� ������ �������� ���������������
void delMoreAvg(PQue& q)
{
   
    
}
//��������� ��������� �� ������������
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
        cout << "������� 1,2:" << endl;
        cout << "������� ���������� ���������: "; cin >> n;
        PQue q1 = makeQueue(n);
        printQueue(q1);
        cout << "\n������� 3:" << endl;
        cout << "\n���������� ������������ ��������:\n";
        addMinInQueue(q1);
        printQueue(q1);
        cout << "\n������� 4:" << endl;
        cout << "\n�������� ��������� ����� �������� ���������������:\n";
        delMoreAvg(q1);
        printQueue(q1);
        cout << "\n������� 5:" << endl;
        cout << "\n��������� ��������� �� ������������ �������:\n";
        multElem(q1);
        printQueue(q1);
    }
    catch (int)
    {
        cout << "������!";
    }
}
