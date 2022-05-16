#pragma once
#include "func.cpp"
#include <iomanip>
#include <random>
#include <vector>

class Node {
private:
    double data;
    Node* left;
    Node* right;
public:
    Node() {
        data = 0;
        left = nullptr, right = nullptr;
    }
    Node(double data) { data = this->data, left = nullptr, right = nullptr; }
    ~Node() { delete left, delete right; }

    void buildBalancedTree(int n);
};

