#pragma once

#include <vector>

class Node {
private:
    double data;
    Node* left;         //указатель на объект структуры Node слева
    Node* right;        //указатель на объект структуры Node справа

private:
    template<class T>
    static T generateRandom(const T& low, const T& high);       //Генератор случайных чисел для заполнения деревьев.
    std::vector<double> balancedTreeToVector();                 //Сохраняет все данные дерева в векторе.
    Node* sortedArrayToBST(std::vector<double> v, int start, int end);  //Конвертируем массив (вектор) в дерево поиска.
public:
    explicit Node(const double& dt);
    ~Node();

    void levelScan();
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


};

