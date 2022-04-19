#include <iostream>
#include "Functions.h"

int main() {
    Node* node;
    int nodesCount = 9;
    Node* x = buildBalancedTree(nodesCount);

    printTree(x, 0);
    std::cout << std::endl << std::endl;
    double minEl = minElementInBalancedTree(x);
    std::cout << "Minimum element = " << minEl << std::endl;

    //vec v = balancedTreeToVector(x);


    return 0;
}
