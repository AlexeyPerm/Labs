#pragma once

class Iterator {
    friend class List;    //Делаем все элементы доступными для класса List.

public:
// ------------------------- Constructors -------------------------- //
    Iterator() { current = nullptr; }    //Создаём нулевой указатель
    explicit Iterator(int* const c) : current(c) {};
    Iterator(const Iterator& it) { current = it.current; }

// --------------------------- Overloads --------------------------- //
    Iterator& operator++();         //Перемещает итератор к следующему элементу контейнера
    Iterator  operator++(int);      //Перемещает итератор к следующему элементу контейнера
    Iterator& operator--();         //Перемещает итератор к предыдущему элементу контейнера
    Iterator  operator--(int);      //Перемещает итератор к предыдущему элементу контейнера
    Iterator& operator-=(int n);    //Перемещает итератор влево к элементу с номером n;
    Iterator  operator-(int n);     //Перемещает итератор влево к элементу с номером n;
    int& operator*() { return *current; }    //Возвращает элемент, на который в данный момент указывает итератор.
    bool operator==(const Iterator& it) const { return current == it.current; }
    bool operator!=(const Iterator& it) const { return current != it.current; }

private:
    int* current;       //Указатель на текущий элемент.
};