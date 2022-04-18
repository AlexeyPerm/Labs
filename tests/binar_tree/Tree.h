#pragma once

#include <iostream>

using namespace std;

template<class T>
class Tree {
private:
    T data; // Данные типа Т
    Tree* left; // Указатель на узел слева
    Tree* right; // Указатель на узел справа
    Tree* parent; // Указатель на предка
public:
    explicit Tree(T); // Конструктор
    ~Tree(); // Деструктор
    void insertLeft(T); // Вставить узел слева
    void insertRight(T); // Вставить узел справа
// Добавить поддерево слева
    void addLeftTree(Tree<T>* tree) { left = tree; }
// Добавить поддерево справа
    void addRightTree(Tree<T>* tree) { right = tree; }
    Tree<T>* ejectLeft(); // Извлечь поддерево слева
    Tree<T>* ejectRight(); // Извлечь поддерево справа13
    void deleteLeft(); // Удалить поддерево слева
    void deleteRight(); // Удалить поддерево справа
    void setData(T dt) { data = dt; } // Установить данные для узла
/* Пройти дерево с печатью элементов в прямом порядке (сверху вниз) */
    static void preOrder(Tree<T>*);
/* Пройти дерево с печатью элементов в симметричном порядке (слева направо) */
    static void inOrder(Tree<T>*);
/* Пройти дерево с печатью элементов в обратном порядке (снизу вверх) */
    static void postOrder(Tree<T>*);
    Tree<T>* copyTree(); // Скопировать дерево
    T getData() {
        if (this != NULL) {
            return data;
        }
        else {
            return NULL;
        }
    }
// Получить данные с узла
    void printTree(int); // Печать дерева горизонтально
    void printVTree(int); // Печать дерева вертикально
/* Прохождение по дереву и запись в файл */
    void obh(Tree<T>* node);
    void printVTree2(); // Печать дерева вертикально (2)
    int getAmountOfNodes(); // Получить количество элементов дерева
/* Получить высоту дерева (считает с текущего узла по направлению к листьям) */
    int getHeight();
/* Проходить по каждому уровню дерева
начиная с корня и вывести элементы */
    void levelScan();
    void deleteTree() { delete this; } // Удалить дерево
/* Если дерево неполное, сделать его полным (недостающие узлы приобретут данные NULL) */
    Tree<T>* replaceNULLforEmpty();
    Tree<T>* getLeft() { return left; }
// Получить левый узел
    Tree<T>* getRight() { return right; }
// Получить правый узел
    Tree<T>* getParent() { return parent; }
// Получить родителя
/* Найти элемент и добавить к нему слева узел */
    void findElement_insertLeft(Tree<T>*, T, T);

/* Найти элемент и добавить к нему справа узел */
    void findElement_insertRight(Tree<T>*, T, T);
/* Построить идеально сбалансированное дерево по данному количеству элементов */
    static Tree<T>* balancedTree(int n);
};

template<class T>
int getLevel(Tree<T>* tree);

template<class T>
Tree<T>::Tree(T dt) {
    data = dt;
    right = left = parent = nullptr;
}

template<class T>
Tree<T>::~Tree() {
    delete this->right;
    delete this->left;
}

template<class T>
void Tree<T>::insertLeft(T dt) {
    Tree<T> node = new Tree(dt);
    if (this->left != NULL) {
        this->left->parent = node;
    }
    node->left = this->left;
    this->left = node;
    node->parent = this;
}

template<class T>
void Tree<T>::insertRight(T dt) {
    Tree<T> node = new Tree(dt);
    if (this->right != NULL)
        this->right->parent = node;
    node->right = this->right;
    this->right = node;
    node->parent = this;
}
template<class T>
void Tree<T>::preOrder(Tree<T>* node) {     //прямой обход
    if (node != NULL) {
        std::cout << node->getData() << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
template<class T>
void Tree<T>::inOrder(Tree<T>* node) {      //Симметричный. Слева направо
    if (node != NULL) {
        inOrder(node->left);
        std::cout << node->getData() << " ";
        inOrder(node->right);
    }
}
template<class T>
void Tree<T>::postOrder(Tree<T>* node) {         //снизу вверх. Обратный.
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->getData() << " ";
    }
}

