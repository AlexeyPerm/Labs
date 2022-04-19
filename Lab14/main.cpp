#include <iostream>
#include "Functions.h"

int main() {
    Node* node;
    int nodesCount = 10;
    Node* x = buildBalancedTree(nodesCount);
    std::cout << std::endl;
    std::cout << "===============================================================" << std::endl;
    std::cout << "======================== Balanced Tree ========================" << std::endl;
    std::cout << "===============================================================" << std::endl;
    std::cout << std::endl << std::endl;
    printTree(x, 0);
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    //double minEl = minElementInBalancedTree(x);
    //std::cout << "Minimum element = " << minEl << std::endl;

    //vec v = balancedTreeToVector(x);

    Node* searchTree = createBalancedSearchTree(x);
    std::cout << "===============================================================" << std::endl;
    std::cout << "========================= Search Tree =========================" << std::endl;
    std::cout << "===============================================================" << std::endl;
    std::cout << std::endl << std::endl;
    printTree(searchTree, 0);

    return 0;
}
