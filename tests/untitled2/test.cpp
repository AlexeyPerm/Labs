#include "test.h"


void Node::buildBalancedTree(int n) {
//Построить левое поддерево с n_left = n/2 (деление по модулю).
//Построить правое поддерево с n_right = n – 1 – n_left
    int nLeft = n / 2;
    int nRight = n - n / 2 - 1;
    Node tree(generateRandom(0.0, 10.0)); //генерирую случайное число для поля data
    if (n == 0) {
        return;
    }
    else {
        tree.left = buildBalancedTree(nLeft);
        tree.right = buildBalancedTree(nRight);
    }
}

