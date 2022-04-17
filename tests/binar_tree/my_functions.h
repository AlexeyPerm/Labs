#pragma  once

#include <iostream>

struct Node {   //бинарное дерево по своей сути рекурсивная структура
    int d;
    Node* left;
    Node* right;
};

Node* first(const int& d);                  //первый элемент в дереве.
Node* searchInsert(Node* root, int& l);      //поиск, куда вставить элемента
void printTree(const Node* root, const int& l);

Node* first(const int& d) {
    Node* pv = new Node;    //указатель на массив из объектов Node; Он же корень дерева
    pv->d = d;
    pv->right = nullptr;
    pv->right = nullptr;
    return pv;
}

//Поиск с включением
Node* searchInsert(Node* root, int& d) {
    Node* pv = root, * prev;    // корень дерева
    bool found = false;
    while (pv && !found) {
        prev = pv;
        if (d == pv->d) {
            found = true;
        }
        else if (d < pv->d) {
            pv = pv->left;
        }
        else {
            pv = pv->right;
        }
    }
    if (found) {
        return pv;
    }
    //создание нового узла//
    Node* pNew = new Node;
    pNew->d = d;
    pNew->left = nullptr;
    pNew->right = nullptr;
    if (d < prev->d) {
        prev->left = pNew;
    }
    else {
        prev->right = pNew;
    }
    return pNew;
}

void printTree(const Node* p, const int& level) {
    if (p) {
        printTree(p->left, level + 1);    //вывод левого поддерева.
    }
    for (int i = 0; i < level; ++i) {
        std::cout << "   ";
    }
    std::cout << p->d << std::endl;
    printTree(p->right, level + 1);
}