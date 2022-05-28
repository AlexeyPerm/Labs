#pragma once
#include "GL/glut.h"
#include <iostream>
#include "Tree.h"


bool selection() {
    std::cout << "Enter option number.\n";
    std::cout << "1. Create Binary Balanced Tree.\n";
    std::cout << "2. Find minimum element.\n";
    std::cout << "3. Convert to Binary Search Tree.\n";
    std::cout << "4. Print Binary Balanced Tree.\n";
    std::cout << "5. Print Binary Search Tree.\n";
    std::cout << "6. Insert into Balanced Tree.\n";
    std::cout << "7. Insert into Binary Search Tree.\n";
    std::cout << "0. Exit.\n";
    std::cout << ">";
    int choice;
    Tree* myTree;       //сбалансированное дерево
    Tree* myBST;        //Дерево поиска
    (std::cin >> choice).get();
    switch (choice) {
        case 1 : {        //Create Binary Balanced Tree.
            std::cout << "Enter nodes count :\n>";
            int nodesCount{};
            std::cin >> nodesCount;
            myTree = Tree::buildBalancedTree(nodesCount);
            return true;
        }
        case 2 : {        //Find minimum element.
            double minEl = myTree->min();
            std::cout << "Minimum element = " << minEl << std::endl;
            return true;
        }
        case 3 : {        //Convert perfect to Binary Search Tree
            myBST = myTree->createBalancedSearchTree();
            return true;
        }
        case 4 : {        //Print Binary Balanced Tree
            if (myTree != nullptr) {
                std::cout << "===============================================================" << std::endl;
                std::cout << "==================== Binary Balanced Tree =====================" << std::endl;
                std::cout << "===============================================================" << std::endl;
                myTree->printTree(0);
            } else {
                std::cout << "\nNothing to print..." << std::endl << std::endl;
            }
            return true;
        }
        case 5 : {        //Print Binary Search Tree
            if (myBST != nullptr) {
                std::cout << "===============================================================" << std::endl;
                std::cout << "===================== Binary Search Tree ======================" << std::endl;
                std::cout << "===============================================================" << std::endl;
                myBST->printTree(0);
            } else {
                std::cout << "\nNothing to print..." << std::endl << std::endl;
            }
            return true;
        }
        case 6 : {
            std::cout << "Add item>";
            double a{};
            std::cin >> a;
            myTree->insertToTree(a);
            break;
        }
        case 7 : {
            std::cout << "Add item>";
            double a{};
            std::cin >> a;
            myBST->insertToTree(a);
            break;
        }
        case 0 : {        //Exit
            if (myTree) {
                myTree->deleteTree();
            }
            if (myBST) {
                myBST->deleteTree();
            }
            std::cout << "Exit...";
            return false;
        }
        default:
            std::cout << "Error. Enter option number.";
            return true;
    }
    return true;
}

