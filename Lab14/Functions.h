#pragma once

#include <random>

template<class T>
T generateRandom(const T& left, const T& right);    //рандомайзер

struct Node {
    double data;       //информационное поле
    Node* left;     //указатель типа Node на левое поддерево
    Node* right;
};

Node* createNode(const double data) {
    Node* root = new Node;
    root->data = data;
    root->left = nullptr;
    root->right = nullptr;
    return root;    //возвращаем указатель на созданный элемент - корень дерева.
}

Node* addToRight(Node* root, const double data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }
    if(root->left != nullptr){
        root->left = createNode(data);
    }

    return root;
}


template<class T>
T generateRandom(const T& left, const T& right) {
    const char* i = typeid(int).name();
    const char* l = typeid(long).name();
    const char* d = typeid(double).name();
    const char* ll = typeid(long long).name();
    const char* e = typeid(long double).name();

    std::random_device rd;
    std::mt19937 gen(rd());

    if (typeid(T).name() == i || typeid(T).name() == l) {
        std::uniform_int_distribution<> dis(left, right);
        return dis(gen);
    }
    else if ((typeid(T).name() == d) || (typeid(T).name() == e) || (typeid(T).name() == ll)) {
        std::uniform_real_distribution<> dis(left, right);
        return dis(gen);
    }
    return 0;
}

