#pragma once

#include <random>

template<class T>
T generateRandom(const T& lhs, const T& rhs);

struct Node {       //Структура Node. Он же узел в дереве.
    double data;
    Node* left;         //указатель на объект структуры Node слева
    Node* right;        //указатель на объект структуры Node справа
};

Node* createNode(double dt) {
    Node* node = new Node;
    node->data = dt;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void addLeftBranch(Node* root, Node* data) {
    if (root->left == nullptr) {
        root->left = data;
    }
    else {
        addLeftBranch(root->left, data);
    }
}

void addRightBranch(Node* root, Node* data) {
    if (root->right == nullptr) {
        root->right = data;
    }
    else {
        addRightBranch(root->right, data);
    }
}

Node* buildPerfectBinaryTree(int n, Node* node) {
//Построить левое поддерево с n_left = n/2 (деление по модулю).
//Построить правое поддерево с n_right = n – 1 – n_left
    if (n == 0) {
        return nullptr;
    }
    const int nLeft = n / 2;
    const int nRight = n - nLeft - 1;
    //Создаём узел, для заполнения его данными и помещения в дерево.
    Node* tmpNode = createNode(generateRandom(0.0, 10.0));
    buildPerfectBinaryTree(nLeft, tmpNode->left);
    buildPerfectBinaryTree(nRight, tmpNode->right);
    return node;
}


template<class T>
T generateRandom(const T& lhs, const T& rhs) {
    const char* i = typeid(int).name();
    const char* l = typeid(long).name();
    const char* d = typeid(double).name();
    const char* ll = typeid(long long).name();
    const char* e = typeid(long double).name();

    std::random_device rd;
    std::mt19937 gen(rd());

    if (typeid(T).name() == i || typeid(T).name() == l) {
        std::uniform_int_distribution<> dis(lhs, rhs);
        return dis(gen);
    }
    else if ((typeid(T).name() == d) || (typeid(T).name() == e) || (typeid(T).name() == ll)) {
        std::uniform_real_distribution<> dis(lhs, rhs);
        return dis(gen);
    }
    return 0;
}
