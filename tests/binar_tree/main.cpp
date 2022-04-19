#include <iostream>
#include <iomanip>
#include <vector>

typedef std::vector<int> vec;
struct TNode {
    int data;
    TNode* left;
    TNode* right;
};

TNode* newNode(int data) {
    TNode* node = new TNode;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

TNode* sortedArrayToBST(vec v, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int middle = (start + end) / 2;
    TNode* root = newNode(v[middle]);
    root->left = sortedArrayToBST(v, start, middle - 1);
    root->right = sortedArrayToBST(v, middle + 1, end);
    return root;
}

void printTree(TNode* const tree, int const level) {
    if (tree) {
        printTree(tree->right, level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << "\t";
        }
        std::cout << std::fixed << std::setprecision(2) << tree->data << std::endl;
        printTree(tree->left, level + 1);
    }
}

void deleteTree(TNode* tree) {
    if (tree != nullptr) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        delete tree;
    }
    else {
        return;
    }
}

int main() {
    vec v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TNode* root = sortedArrayToBST(v, 0, v.size() - 1);
    deleteTree(root);
    return 0;
}

