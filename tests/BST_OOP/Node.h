#pragma once

#include "GL/glut.h"

#include <vector>

class Node {
private:
    double data;
    Node* left;         //указатель на объект структуры Node слева
    Node* right;        //указатель на объект структуры Node справа
    int node_x;         //координата x
    int node_y;         //координата y (высота узла в дереве)
    int text_x;
    int text_y;
private:
    template<class T>
    static T generateRandom(const T& low, const T& high);       //Генератор случайных чисел для заполнения деревьев.
    std::vector<double> balancedTreeToVector();                 //Сохраняет все данные дерева в векторе.
    Node* sortedArrayToBST(std::vector<double> v, int start, int end);  //Конвертируем массив (вектор) в дерево поиска.
public:
    explicit Node(const double& dt);
    ~Node();

    void levelScan();
    void printVTree(const int& k);
    void printTree(const int& level);
    void deleteTree() { delete this; }
    void insertToTree(const double& dt);
    void insertLeftBranch(const double& dt);
    void insertRightBranch(const double& dt);
    void addLeftTree(Node* tree) { left = tree; }
    void addRightTree(Node* tree) { right = tree; }

    double min();
    double getData();
    int getHeight();
    int getAmountOfNodes();
    int getLevel(Node* node);

    Node* copyTree();
    Node* replaceNULLforEmpty();
    Node* createBalancedSearchTree();
    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    Node* replace_help(Node* node, const int& h);
    static Node* buildBalancedTree(const int& n);
    void postorder(int indent);

    void drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k);


};

