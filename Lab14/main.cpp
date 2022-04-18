#include <iostream>
#include "Functions.h"


int main() {
    Node * root = createNode(10);
    addToRight(root, 5);
    addToRight(root, 5.5);

    return 0;
}
