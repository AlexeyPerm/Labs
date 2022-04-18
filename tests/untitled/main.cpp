#include <iostream>


typedef struct Node {
    int value;
    Node* left;
    Node* right;
} Node;

//создание нового элемента
Node* createNode(int i);

//вставляет элемент в дерево с корнем root
void insertIntoTree(Node* root, Node* elem);

//Печать дерево от элемента вниз.
void printTree(Node* curElem);

int main() {

    int a[7]{-3, 1, -5, 40, 2, -6, 8};
    Node* root = createNode(0);
    for (int i = 0; i < 7; ++i) {
        Node* el = createNode(a[i]);
        insertIntoTree(root, el);
    }


    std::cout << "My tree: " << std::endl;
    printTree(root);

    return 0;
}

Node* createNode(int i) {
    Node* elem = new Node;
    elem->value = i;
    elem->left = nullptr;
    elem->right = nullptr;
    return elem;
}

void insertIntoTree(Node* root, Node* elem) {
    if (elem->value < root->value) {
        //Идёт в левое поддерево
        if (root->left == nullptr) {
            //Левое поддерево пустое. Сюда вставим elem.
            root->left = elem;
        }
        else {
            //Слева что-то есть. Рекурсивное вставляем влево
            insertIntoTree(root->left, elem);
        }
    }
    else {
        //Идёт в левое поддерево
        if (root->right == nullptr) {
            root->right = elem;
        }
        else {
            insertIntoTree(root->right, elem);
        }
    }
}

void printTree(Node* curElem) {
    if (curElem->right != nullptr) {
        printTree(curElem->right);
    }
    std::cout << " Value = " << curElem->value << std::endl;
    if (curElem->left != nullptr) {
        printTree(curElem->left);
    }
}