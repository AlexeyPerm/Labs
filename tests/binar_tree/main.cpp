#include <iostream>

//#include "Tree.h"
struct Node {
    int data;
    //Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* a = new Node;
    a->data = data;
    a->right = nullptr;
    //a->left = nullptr;
    return a;
}

void addRight(Node* root, Node* data) {
    if (root->right == nullptr) {
        root->right = data;
    }
    else {
        addRight(root->right, data);
    }
}


int main() {

    Node* a = createNode(999);
    for (int i = 0; i < 10; ++i) {
        Node* el = createNode(i);
        addRight(a, el);
    }

    return 0;
}