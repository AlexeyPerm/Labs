#pragma once

#include <vector>

class Tree {
private:
    double data;
    Tree* left;         //указатель на объект структуры Tree слева
    Tree* right;        //указатель на объект структуры Tree справа

private:
    template<class T>
    static T generateRandom(const T& low, const T& high);       //Генератор случайных чисел для заполнения деревьев.
    std::vector<double> balancedTreeToVector();                 //Сохраняет все данные дерева в векторе.
    Tree* sortedArrayToBST(std::vector<double> v, int start, int end);  //Конвертируем массив (вектор) в дерево поиска.
public:
    explicit Tree(const double& dt);
    ~Tree();

    void levelScan();
    void printTree(const int& level);
    void deleteTree() { delete this; }
    void insertToTree(const double& dt);
    void insertLeftBranch(const double& dt);
    void insertRightBranch(const double& dt);
    void addLeftTree(Tree* tree) { left = tree; }
    void addRightTree(Tree* tree) { right = tree; }

    double min();
    double getData();
    int getHeight();
    int getAmountOfNodes();
    int getLevel(Tree* node);

    Tree* copyTree();
    Tree* replaceNULLforEmpty();
    Tree* createBalancedSearchTree();
    Tree* getLeft() { return left; }
    Tree* getRight() { return right; }
    Tree* replace_help(Tree* tree, const int& h);
    static Tree* buildBalancedTree(const int& n);
    void postorder(int indent);


};

