#pragma once

#include <vector>

class Tree {
private:
    double data;
    Tree* left;     //указатель на объект структуры Tree слева
    Tree* right;    //указатель на объект структуры Tree справа
    Tree* parent;   // Указатель на родительский узел

private:
    template<class T>
    static T generateRandom(const T& low, const T& high);       //Генератор случайных чисел для заполнения деревьев.
    std::vector<double> balancedTreeToVector();                 //Сохраняет все данные дерева в векторе.
    Tree* sortedArrayToBST(std::vector<double> v, int start, int end);  //Конвертируем массив (вектор) в дерево поиска.
    //friend void display();
public:
    int node_x;     // х-координата элемента;
    int node_y;     // y-координата элемента;
    int text_x;     // х-координата текста;
    int text_y;     // y-координата текста;
    explicit Tree(const double& dt);
    ~Tree();

    void levelScan();       //Поперечное прохождение дерева
    void printVTree(const int& k);
    void printTree (const int& level);
    void deleteTree() { delete this; }
    void insertToTree(const double& dt);
    void insertLeftBranch (const double& dt);
    void insertRightBranch(const double& dt);
    void addLeftTree (Tree* tree) { left = tree; }
    void addRightTree(Tree* tree) { right = tree; }

    int getHeight();            //Высота дерева
    int getAmountOfNodes();     //Кол-во узлов в дереве
    int getLevel(Tree* tree);
    double min();
    double getData();           //Данные узла

    Tree* copyTree();
    void postorder(int indent);
    Tree* replaceNullForEmpty();
    Tree* createBalancedSearchTree();
    Tree* getLeft()   { return left; }
    Tree* getRight()  { return right; }
    Tree* getParent() { return parent; }
    Tree* replace_help(Tree* node, int h);
    static Tree* buildBalancedTree(const int& n);

    // ---------------------------------------------------------------------- //
    // -------------------------------- DRAW -------------------------------- //
    // ---------------------------------------------------------------------- //

    // Установить координаты для данного узла при рисовании
    void setCoordsForNode(int window_width, int window_height, int shift,
                          int tree_width, int tree_height, int x, int y, int R);
    Tree* getNodeByCoords(int x, int y, int R);
    Tree* get_help(Tree* node, int x, int y, int R);
    //Установить координаты для текста текущего узла при рисовании
    void setCoordsForText(int k, int R);
    static void initWindow(int argc, char** argv);
    void drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k); //рисовать дерево
};