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
    int node_x;     // х-координата элемента;
    int node_y;     // y-координата элемента;
    int text_x;     // х-координата текста;
    int text_y;     // y-координата текста;
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
    // Установить координаты для данного узла при рисовании
    void setCoordsForNode(int window_width, int window_height, int shift,
                          int tree_width, int tree_height, int x, int y, int R);
    Tree* getNodeByCoords(int x, int y, int R);
    //Установить координаты для текста текущего узла при рисовании
    void setCoordsForText(int k, int shift);
    void drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k); //рисовать дерево

};

struct SGlutContextStruct {
    /* window_width  – ширина окна;
     * window_height – высота окна;
     * shift – отступ от краев (решено сделать его одинаковым с двух сторон);
     * k - коэффициент ширины данных;
     * R – радиус круга;
     * x, y - координаты чего-либо;
     * state - переменная состояния при работе с мышью
    */
    void* tree;     //копия дерева
    int window_width, window_height, shift, k, R, x, y, state;
};

