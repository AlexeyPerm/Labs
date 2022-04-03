#include "List.h"

// ------------------------- Constructors -------------------------- //
List::List() {
    size = 0;
    arr = nullptr;

}

List::List(const int size) {
    if (size > 0) {
        this->size = size;
        arr = new int[size];
    } else {
        std::cout << "Error!!! Size <= 0\n";
        arr = nullptr;
    }
}

List::List(const std::initializer_list<int>& l) : List(static_cast<int> (l.size())) {
    //Использую "Range-based for loop":
    //https://en.cppreference.com/w/cpp/language/range-for
    int count = 0;
    for (auto& i: l) {
        arr[count] = i;
        count++;
    }
}

List::~List() {
    delete[] arr;
    arr = nullptr;
}

List::List(const List& l) {    //Конструктор копирования
    this->size = l.size;
    arr = new int[size]{};
    for (int i = 0; i < size; ++i) {
        this->arr[i] = arr[i];
    }
}
// --------------------- Overloaded Functions ---------------------- //

List& List::operator=(const List& l) {    //конструктор присваивания
    if (this == &l) {    //Проверка на самоприсваивание
        return *this;
    }
    if (arr) {
        delete[] arr;    //Если дата не Null, то освобождаем память.
    }

    size = l.size;
    arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = l.arr[i];
    }
    return *this;
}

int& List::operator[](const int index) const {
    if (size > index) {
        return arr[index];
    } else {
        std::cout << "\nError! Index > size\nExit..." << std::endl;
        exit(1);
    }
}

std::ostream& operator<<(std::ostream& out, const List& l) {
    for (int i = 0; i < l.size; ++i) {
        out << l.arr[i] << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, List& l) {
    for (int i = 0; i < l.size; ++i) {
        std::cout << "> ";
        in >> l.arr[i];
    }
    return in;
}

List::operator int() const {
    return size;
}

List& List::operator-(int index) {
    current = &arr[index];

}
