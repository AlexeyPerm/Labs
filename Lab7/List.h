#pragma once

#include "istream"
#include "iostream"

using namespace std;

template<class T>
class List;

template<class T>
ostream& operator<<(ostream& out, const List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        out << v.data[i] << endl;
    }
    return out;
}

template<class T>
istream& operator>>(istream& in, List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        in >> v.data[i];
    }
    return in;
}


template<class T>
class List {
public:
// ------------------------- Constructors -------------------------- //
    List(int, T);

    [[maybe_unused]] List(const List<T>&);

    ~List();

// --------------------------- Overloads --------------------------- //
    List operator+(T list);

    T& operator[](int) const; //перегрузка индексирования

    explicit operator int() const;

    List& operator=(const List<T>&);

    //Так как мы объявляем специализацию другом, то мы можем вынести
    //определение (или только объявление) общего шаблона до класса List
    //https://ru.stackoverflow.com/a/495222
    friend ostream& operator<<<T>(ostream&, const List<T>&);

    friend istream& operator>><T>(istream&, List<T>&);

private:
    int size = 0;   //размер списка
    T* data = nullptr;  //указатель на массив элементов списка
};

/*
Размещение кода из List.cpp в List.h сделает List.h слишком
большим/беспорядочным. Альтернативой будет переименование
List.cpp в List.inl (.inl от англ. "inline" = "встроенный"),
а затем подключение List.inl из нижней части файла List.h.
Это даст тот же результат, что и размещение всего кода в
заголовочном файле, но код получится немного чище.
 */
#include "List.inl"