#include "List.h"
#include <initializer_list>
#include <string>

// ------------------------- Constructors -------------------------- //
List::List() {
    size = 0;
    data = nullptr;
    begin.current = nullptr;
    end.current   = nullptr;
}

List::List(const int size, const int k) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = k;
    }
    begin.current = &data[0];
    end.current   = &data[size - 1];
}

List::List(const int size) {
    if (size > 0) {
        this->size = size;
        data = new int[size]{};
        begin.current = &data[0];
        end.current   = &data[size - 1];
    }
    else {
        std::cout << "Error!!! Size <= 0\n";
        data = nullptr;
    }
}

//initializer_list имеет функцию size(), которая возвращает количество
//элементов списка. Используем преобразование типа size_t -> int.
//Делегируем конструктор List::List(int);
List::List(const std::initializer_list<int>& l) : List(static_cast<int> (l.size())) {
    //Использую "Range-based for loop":
    //https://en.cppreference.com/w/cpp/language/range-for
    int count = 0;
    for (const auto& i: l) {
        data[count] = i;
        count++;
    }
}

List::~List() {
    delete[] data;
    data = nullptr;
}

List::List(const List& l) {    //Конструктор копирования
    this->size = l.size;
    data = new int[size]{};
    for (int i = 0; i < size; ++i) {
        this->data[i] = l.data[i];
    }
    begin = l.begin;
    end   = l.end;
}

// --------------------------- Overloads --------------------------- //

List& List::operator=(const List& l) {    //конструктор присваивания
    if (this == &l) {    //Проверка на самоприсваивание
        return *this;
    }
    if (data) {
        delete[] data;    //Если дата не Null, то освобождаем память.
    }

    size = l.size;
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = l.data[i];
    }

    begin = l.begin;
    end   = l.end;
    return *this;
}

int& List::operator[](const int index) const {
    if (size > index) {
        return data[index];
    }
    else {
        std::cout << "\nError! Index > size\nExit..." << std::endl;
        exit(0);
    }
}

std::ostream& operator<<(std::ostream& out, const List& l) {
    for (int i = 0; i < l.size; ++i) {
        out << l.data[i] << "  ";
    }
    std::cout << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, List& l) {
    for (int i = 0; i < l.size; ++i) {
        std::cout << "> ";
        in >> l.data[i];
    }
    return in;
}

List::operator int() const {
    return size;
}

//В файле с лабораторной работой по какой-то причине инкремент и декремент перегружаются
//не совсем корректно. По-правильному должна возвращаться ссылка на объект.
//https://en.cppreference.com/w/cpp/language/operator_incdec

// ---------------------------- Methods ---------------------------- //
void List::erase() {
    delete[] data;
    size = 0;
    data = nullptr;
    begin.current = nullptr;
    end.current   = nullptr;
}
void List::pushElem(const int elem) {
    if (size == 0) {
        this->size = size;
        data = new int[size]{};
        begin.current = &data[0];
        end.current   = &data[size - 1];
    }
    ++size;
    data[size - 1] = elem;
    end.current    = &data[size - 1];
}
