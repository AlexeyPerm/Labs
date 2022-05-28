
#include "Menu.h"
#include "draw.h"

int main(int argc, char** argv) {
    //while(selection);
    Tree*  myTree = Tree::buildBalancedTree(11);

    myTree->printVTree(3);
    std::cout << std::endl << std::endl;
    myTree->printTree(1);


    //draw_main(test, argc, argv);


    return 0;
}

