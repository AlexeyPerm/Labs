#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Tree {
private:
    T data;                                            // Данные типа Т
    Tree* left;                                        // Указатель на узел слева
    Tree* right;                                    // Указатель на узел справа
    Tree* parent;                                    // Указатель на предка
public:
    Tree(T);                                        // Конструктор
    ~Tree();                                        // Деструктор

    void insertLeft(T);                            // Вставить узел слева
    void insertRight(T);                            // Вставить узел справа

    void addLeftTree(Tree<T>* tree) { left = tree; }    // Добавить поддерево слева
    void addRightTree(Tree<T>* tree) { right = tree; }    // Добавить поддерево справа

    Tree<T>* ejectLeft();                            // Извлечь поддерево слева
    Tree<T>* ejectRight();                            // Извлечь поддерево справа

    void deleteLeft();                                // Удалить поддерево слева
    void deleteRight();                                // Удалить поддерево справа

    void setData(T dt) { data = dt; } // Установить данные для узла

    /* Пройти дерево с печатью элементов
    в прямом порядке (сверху вниз) */
    static void preOrder(Tree<T>*);

    /* Пройти дерево с печатью элементов в
    симметричном порядке (слева направо) */
    static void inOrder(Tree<T>*);

    /* Пройти дерево с печатью элементов
    в обратном порядке (снизу вверх) */
    static void postOrder(Tree<T>*);

    Tree<T>* copyTree();                            // Скопировать дерево

    T getData() {
        if (this != nullptr) {
            return data;
        }
    }

    void printTree(int);                            // Печать дерева горизонтально
    void printVTree(int);                            // Печать дерева вертикально

    /* Прохождение по дереву и запись в файл */
    void obhod(Tree<T>* node);

    void printVTree2();                                // Печать дерева вертикально (2)

    int getAmountOfNodes();                            // Получить количество элементов дерева
    /* Получить высоту дерева
    (считает с текущего узла по направлению к листьям) */
    int getHeight();

    /* Проходить по каждому уровню дерева
    начиная с корня и вывести элементы */
    void levelScan();
    void deleteTree() { delete this; }                // Удалить дерево
    /* Если дерево неполное, сделать его полным
    (недостающие узлы приобретут данные NULL) */


    Tree<T>* getLeft() { return left; }                // Получить левый узел
    Tree<T>* getRight() { return right; }            // Получить правый узел
    Tree<T>* getParent() { return parent; }            // Получить родителя


    void findElement_insertLeft(Tree<T>*, T, T);    //Найти элемент и добавить к нему слева узел
    void findElement_insertRight(Tree<T>*, T, T);    //Найти элемент и добавить к нему справа узел

    /* Построить идеально сбалансированное
    дерево по данному количеству элементов */
    static Tree<T>* balancedTree(int n);
};

template <class T>
Tree<T>* replace_help(Tree<T>* node, int h);
template <class T>
Tree<T>* Tree<T>::replaceNULLforEmpty() {
    Tree<T>* node = this->copyTree();
    int h = node->getHeight();
    node=replace_help(node,h);
    return node;
}
template <class T>
Tree<T>* replace_help(Tree<T>* node, int h) {
    int curLevel = getLevel(node);
    if ((node->getLeft() == NULL) && (curLevel != h - 1)) {
        node->insertLeft(NULL);
    }
    if ((node->getRight() == NULL) && (curLevel != h - 1)) {
        node->insertRight(NULL);
    }
    if (node->getLeft()!=NULL) node->addLeftTree(replace_help(node->getLeft(),h));
    if (node->getRight()!=NULL) node->addRightTree(replace_help(node->getRight(),h));
    return node;
}

template<class T>
void Tree<T>::findElement_insertLeft(Tree<T>* node, T dt1, T dt2) {
    if (dt1 == node->getData()) {
        node->insertLeft(dt2);
    }
    if (node != NULL) {
        findElement_insertLeft(node->getLeft(), dt1, dt2);
    }

    findElement_insertLeft(node->getRight(), dt1, dt2);

}

template<class T>
void Tree<T>::findElement_insertRight(Tree<T>* node, T dt1, T dt2) {
    if (dt1 == node->getData()) {
        node->insertRight(dt2);
    }
    if (node != NULL) {
        findElement_insertRight(node->getRight(), dt1, dt2);
    }

    //findElement_insertRight(node->getRight(), dt1, dt2);
}

template<class T>
int Tree<T>::getAmountOfNodes() {
    if (this == NULL) {
        return 0;
    }
    if ((this->left == NULL) && (this->right == NULL)) {
        return 1;
    }
    int l = 0;
    int r = 0;
    if (this->left != NULL) {
        l = this->left->getAmountOfNodes();
    }
    if (this->right != NULL) {
        r = this->right->getAmountOfNodes();
    }
    return (l + r + 1);
}

template<class T>
int Tree<T>::getHeight() {
    int h1 = 0, h2 = 0, hadd = 0;
    if (this == NULL) {
        return 0;
    }
    if (this->left != NULL) {
        h1 = this->left->getHeight();
    }
    if (this->right != NULL) {
        h2 = this->right->getHeight();
    }
    if (h1 >= h2) {
        return h1 + 1;
    }
    else {
        return h2 + 1;
    }
}

template<class T>
void Tree<T>::levelScan() {
    vector<Tree<T>*> V;
    Tree<T>* p = this;
    V.push_back(p);
    for (int i = 0; i < this->getAmountOfNodes(); i++) {
        if (V[i]->left != NULL) {
            V.push_back(V[i]->left);
        }
        if (V[i]->right != NULL) {
            V.push_back(V[i]->right);
        }
    }
    for (int i = 0; i < V.size(); i++) {
        cout << V.at(i)->getData() << " ";
    }
    cout << endl;
}

template<class T>
int getLevel(Tree<T>* tree);

template<class T>
Tree<T>::Tree(T dt) {                    // Конструктор узла
    data = dt;                        // Присвоим данные по аргументу
    left = nullptr;                    // Обнулим все указатели
    right = nullptr;
    parent = nullptr;
}

template<class T>
Tree<T>::~Tree() {                    // Деструктор дерева
    delete this->left;
    delete this->right;
}

template<class T>
void Tree<T>::insertLeft(T dt) {
    Tree<T>* node = new Tree(dt);
    if (this->left != nullptr) {
        this->left->parent = node;    //Сделать так, чтобы его предком был новый узел */
    }
    node->left = this->left;        //Теперь у нового узла левый потомок – это левый потомок вызывающего узла */
    this->left = node;                //А вызывающий узел теперь имеет левого потомка – это новый узел */
    node->parent = this;            //Указываем, что у нового узла теперь предком является текущий узел */
}

template<class T>
void Tree<T>::insertRight(T dt) {
    Tree<T>* node = new Tree(dt);
    if (this->right != nullptr) {
        this->right->parent = node;
    }
    node->right = this->right;
    this->right = node;
    node->parent = this;
}

// ПРЯМОЙ ОБХОД (СВЕРХУ ВНИЗ)
template<class T>
void Tree<T>::preOrder(Tree<T>* node) {
    if (node != NULL) {
        cout << node->getData() << "";
        reorder(node->left);
        reorder(node->right);
    }
}

// СИММЕТРИЧНЫЙ ОБХОД (СЛЕВА НАПРАВО)
template<class T>
void Tree<T>::inOrder(Tree<T>* node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->getData() << "";
        inOrder(node->right);
    }
}

// ОБРАТНЫЙ ОБХОД (СНИЗУ ВВЕРХ)
template<class T>
void Tree<T>::postOrder(Tree<T>* node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->getData() << "";
    }
}

template<class T>
Tree<T>* Tree<T>::ejectLeft() {        // Извлечение
    if (this->left != NULL) {
        Tree<T>* temp = this->left;
        this->left = NULL;
        return temp;
    }
    return NULL;
}

template<class T>
void Tree<T>::deleteLeft() {        // Удаление
    Tree<T>* temp = this->ejectLeft();
    delete temp;
}

template<class T>
Tree<T>* Tree<T>::ejectRight() {
    if (this->right != NULL) {
        Tree<T>* temp = this->right;
        this->right = NULL;
        return temp;
    }
    return NULL;
}

template<class T>
void Tree<T>::deleteRight() {
    Tree<T>* temp = this->ejectRight();
    delete temp;
}

template<class T>
void Tree<T>::printTree(int level) {
    if (this != nullptr) {
        this->left->printTree(level + 1);
        for (int i = 1; i < level; i++) cout << " ";
        cout << this->getData() << endl;
        this->right->printTree(level + 1);
    }
    else return;
}

template<class T>
Tree<T>* Tree<T>::copyTree() {
    Tree<T>* tree = new Tree<T>(this->data);
    if (this->parent != NULL) {
        tree->parent = this->parent;
    }
    if (this->left != NULL) {
        tree->left = this->left->copyTree();
    }
    if (this->right != NULL) {
        tree->right = this->right->copyTree();
    }
    return tree;
}