#include "List.h"
#include "Error.h"

// ========================= Constructors ========================== //
List::List() {
    size = 0;
    arr = nullptr;
    current = nullptr;
}

List::List(const int size) {
    if (size > 0) {
        this->size = size;
        arr = new int[size];
        current = &arr[0];
    } else {
#if OPTION == 2
        throw Error("size <= 0\n");
#elif OPTION == 3
        throw NegativeSizeError();
#endif
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
    current = nullptr;
}

List::List(const List& l) {    //Конструктор копирования
    this->size = l.size;
    arr = new int[size]{};
    for (int i = 0; i < size; ++i) {
        this->arr[i] = arr[i];
    }
    current = l.arr;
}

// ===================== Overloaded Functions ====================== //
List& List::operator=(const List& l) {    //конструктор присваивания
    if (this == &l) {    //Проверка на самоприсваивание
        return *this;
    }
    if (arr) {
        delete[] arr;    //Если дата не Null, то освобождаем память.
    }

    size = l.size;
    current = l.current;
    arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = l.arr[i];
    }
    current = l.current;
    return *this;
}

int& List::operator[](const int index) const {

#if OPTION == 2
    if (index < 0) {
        throw Error("index < 0"); //если индекс i < 0, то бросаем исключение
    }
    if (index >= size) {
        throw Error("index > size");
    }
#elif OPTION == 3
    if (index < 0) {
        throw NegativeIndexError(); //если индекс i < 0, то бросаем исключение
    }
    if (index >= size) {
        throw OversizeIndexError();
    }
#endif

    return arr[index];
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

List& List::operator-(const int index) {
#if OPTION == 2
    if (!size) {
throw Error("List is empty");
    }
    if ((index + 1) > size) {
        throw Error("Index > array");
    }
#elif OPTION == 3
    if (!size) {
        throw EmptySizeError();
    }
    if ((index + 1) > size) {
        throw OversizeIndexError();
    }
#endif

    current = &arr[index];
    return *this;
}

