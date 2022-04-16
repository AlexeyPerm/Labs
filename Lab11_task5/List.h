#pragma once

#include <vector>
#include <stack>
#include <istream>
#include <ostream>
#include <iostream>
#include <initializer_list>

template<class T>
class List;

template<class T>
std::ostream& operator<<(std::ostream& out, const List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        out << v.data[i] << std::endl;
    }
    return out;
}

template<class T>
std::istream& operator>>(std::istream& in, List<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        in >> v.data[i];
    }
    return in;
}


template<class T>
class List {
public:
// ------------------------- Constructors -------------------------- //
    List() { size = 0; }
    explicit List(const int&);
//Использую список инициализации, потому что лень вручную постоянно заполнять значениями каждый объект класса
    List(const std::initializer_list<T>&);
    ~List() = default;
// ---------------------------- Methods ---------------------------- //
    void print();
    T minElement ();
    T average() const;
    void subtractMinElement();
    void addItemToBeginStack(T& elem) ;
    int  getSize() const { return size; }
    void delByElemNumber (const int& number);
// --------------------------- Overloads --------------------------- //
    friend std::istream& operator>><T>(std::istream&, List<T>&);
    friend std::ostream& operator
    <<<T>(std::ostream&, const List<T>&);

private:
    int size;   //размер списка
    std::stack<T> st;    //указатель на массив элементов списка
    std::vector<T> copyStackToVector();
    std::stack<T>  copyVectorToStack(std::vector<T>& v);
};

// ------------------------- Constructors -------------------------- //
template<class T>
List<T>::List(const int& s) {
    T a;
    for (int i = 0; i < s; ++i) {
        std::cin >> a;    //заменил генерацией случайных чисел
        st.push(a);
    }
    size = st.size();
}

//Принимает список объектов <T> и заполняем ими вектор.
template<class T>
List<T>::List(const std::initializer_list<T>& list) {
    for (auto& item: list) {
        st.push(item);
    }
    size = list.size();
}

// ---------------------------- Methods ---------------------------- //
template<class T>
void List<T>::print() {
    std::stack<T> tmp = st; //создаём копию стека и выводим его содержимое на экран.
    while (!tmp.empty()) {
        std::cout << tmp.top() << "  ";
        tmp.pop();
    }
    std::cout << std::endl;
}

template<class T>
T List<T>::average() const {
    T m;
    m = 0;
    std::stack<T> tmp = st;
    auto n = tmp.size();   //количество элементов в стеке
    while (!tmp.empty()) {
        m += tmp.top();
        tmp.pop();
    }
    T result;  //хранение среднего значения.
    result = m / n;
    return result;
}

template<class T>
void List<T>::addItemToBeginStack(T& elem) {
    std::vector<T> v = copyStackToVector();
    v.insert(v.begin() + v.size(), elem);   //помещаем элемент в начало стека.
    while (!st.empty()) {
        st.pop();
    }
    st = copyVectorToStack(v);
}

template<class T>
std::vector<T> List<T>::copyStackToVector() {
    std::vector<T> v;
    std::stack<T> tmp = st;
    while (!tmp.empty()) {
        //добавить элемент из вершины стека
        v.push_back(tmp.top());
        tmp.pop();
    }
    return v;
}

template<class T>
std::stack<T> List<T>::copyVectorToStack(std::vector<T>& v) {
    std::stack<T> s;
    for (int i = (v.size() - 1); i >= 0; --i) {
        s.push(v[i]);
    }
    return s;
}

template<class T>
void List<T>::delByElemNumber(const int& number) {
    std::vector<T> v = copyStackToVector();
    while (!st.empty()) {
        st.pop();
    }
    int i = v.size() - 1;
    do {
        if (i != (v.size() - 1 - number)) {
            st.push(v[i]);
        }
        --i;
    } while (i >= 0);
}

template<class T>
T List<T>::minElement() {
    std::vector<T> v = copyStackToVector();
    T minElem = v[0];
    for (const auto& item: v) {
        if (item < minElem) {
            minElem = item;
        }
    }
    return minElem;
}

template<class T>
void List<T>::subtractMinElement() {
    std::vector<T> v = copyStackToVector();
    while (!st.size()){
        st.pop();
    }
    T a = minElement();
    for (auto& item: v) {
        item -= a;
    }
    st = copyVectorToStack(v);
}