#pragma once

#include <iomanip>
#include <random>
#include <vector>


template<class T>
T generateRandom(const T& low, const T& high);
struct Node;
auto getHeight(Node* tree) -> int;
auto createNode(double dt) -> Node*;
auto buildBalancedTree(int n) -> Node*;
auto printTree(Node* tree, int level) -> void;
auto createBalancedSearchTree(Node*) -> Node*;
auto addLeftBranch(Node* root, Node* data) -> void;
auto minElementInBalancedTree(Node* tree) -> double;
auto balancedTreeToVector(Node* tree) -> std::vector<double>;
auto sortedArrayToSearchTree(std::vector<double> v, int start, int end) -> Node*;

struct Node {           //Структура Node. Он же узел в дереве.
    double data;
    Node* left;        //указатель на объект структуры Node слева
    Node* right;       //указатель на объект структуры Node справа
};


Node* createBalancedSearchTree(Node* tree) {
    std::vector<double> v = balancedTreeToVector(tree);
    Node* root = sortedArrayToSearchTree(v, 0, static_cast<int> (v.size()) - 1);
    return root;
}

Node* sortedArrayToSearchTree(std::vector<double> v, int start, int end) {
/* Подглядел алгоритм создания сбалансированного дерева поиска из ОТСОРТИРОВАННОГО массива. https://bit.ly/3xEi628
 *                                      [ -20, -10, -3, 0, 5, 9, 27 ]
 *                                                      |
 *                                                Корень дерева
 *
 *                    Левый "подкорень"                          Правый "подкорень"
 *      [ -20,               -10,           -3 ]           [ 5,           9,                     27 ]
 *         |                  |              |               |            |                      |
 *         |          Корень поддерева       |               |      Корень поддерева             |
 *        Лист                             Лист             Лист                                Лист
 *
 *       1. Центральный элемент массива - корень дерева;
 *       2. Рекурсивно делим массив пополам. Центр каждой половины массива будет корнем поддерева.
 *
 */

    if (start > end) {
        return nullptr;
    }
    int middle = (start + end) / 2;
    Node* root = createNode(v[middle]);
    root->left = sortedArrayToSearchTree(v, start, middle - 1);
    root->right = sortedArrayToSearchTree(v, middle + 1, end);
    return root;
}

std::vector<double> balancedTreeToVector(Node* tree) {
    static std::vector<double> v;
    if (tree != nullptr) {
        v.push_back(tree->data);
        balancedTreeToVector(tree->left);
        balancedTreeToVector(tree->right);
    }
    std::sort(v.begin(), v.end());
    return v;
}


Node* createNode(const double dt) {
    Node* node = new Node;
    node->data = dt;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void addLeftBranch(Node* root, Node* data) {
    if (root->left == nullptr) {
        root->left = data;
    }
    else {
        addLeftBranch(root->left, data);
    }
}

void addRightBranch(Node* root, Node* data) {
    if (root->right == nullptr) {
        root->right = data;
    }
    else {
        addRightBranch(root->right, data);
    }
}

void printTree(Node* const tree, int const level) {
    if (tree) {
        printTree(tree->right, level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << "\t";
        }
        std::cout << std::fixed << std::setprecision(2) << tree->data << std::endl;
        printTree(tree->left, level + 1);
    }
}

Node* buildBalancedTree(const int n) {
//Построить левое поддерево с n_left = n/2 (деление по модулю).
//Построить правое поддерево с n_right = n – 1 – n_left
    int nLeft = n / 2;
    int nRight = n - n / 2 - 1;
    Node* tree = createNode(generateRandom(0.0, 10.0)); //генерирую случайное число для поля data
    if (n == 0) {
        return nullptr;
    }
    else {
        tree->left = buildBalancedTree(nLeft);
        tree->right = buildBalancedTree(nRight);
    }
    return tree;
}

int getHeight(Node* const tree) { //вычисляем высоту дерева.
    if (!tree) {
        return 0;
    }
//Обходим каждую ветку, начиная с самого дна, когда tree == nullptr. Возвращаем 0, это и будет старт отсчёта.
//На уровень выше добавляется стартовому счётчику единичку. И так пока не достигнем корня дерева.
    int hLeft = getHeight(tree->left);
    int hRight = getHeight(tree->right);
    if (hLeft >= hRight) {
        return hLeft + 1;
    }
    else {
        return hRight + 1;
    }
}

double minElementInBalancedTree(Node* const tree) {
//Не придумал ничего умнее, как сделать переменную static. Означает, что переменная инициализируется один
//раз и будет жить до завершения функции.
    static double minElem = tree->data;
    if (tree != nullptr) {
        if (tree->data < minElem) {
            minElem = tree->data;
        }
        minElementInBalancedTree(tree->left);
        minElementInBalancedTree(tree->right);
    }
    return minElem;
}


template<class T>
T generateRandom(const T& low, const T& high) {
    const char* i = typeid(int).name();
    const char* l = typeid(long).name();
    const char* d = typeid(double).name();
    const char* ll = typeid(long long).name();
    const char* e = typeid(long double).name();

    std::random_device rd;
    std::mt19937 gen(rd());

    if (typeid(T).name() == i || typeid(T).name() == l) {
        std::uniform_int_distribution<> dis(low, high);
        return dis(gen);
    }
    else if ((typeid(T).name() == d) || (typeid(T).name() == e) || (typeid(T).name() == ll)) {
        std::uniform_real_distribution<> dis(low, high);
        return dis(gen);
    }
    return 0;
}
