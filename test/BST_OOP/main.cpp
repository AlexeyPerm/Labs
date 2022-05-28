
#include "Menu.h"
#include "draw.h"

int main(int argc, char** argv) {
    //while(selection);
    Tree* test = new Tree(2.5);
    test->insertRightBranch(3.1);
    test->getRight()->insertRightBranch(4.5);
    test->insertLeftBranch(8.4);
    test->getLeft()->insertLeftBranch(5.4);
    test->printTree(1);

    //draw_main(test, argc, argv);


    return 0;
}

