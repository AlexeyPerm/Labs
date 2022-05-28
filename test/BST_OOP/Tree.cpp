#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"
#pragma ide diagnostic ignored "misc-no-recursion"

#include "Tree.h"
#include <random>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

Tree::Tree(const double& dt) {
    data = dt;
    left = nullptr;
    right = nullptr;
}

Tree::~Tree() {
    delete this->left;
    delete this->right;
}

Tree* Tree::buildBalancedTree(const int& n) {
//Построить левое поддерево с n_left = n/2 (деление по модулю).
//Построить правое поддерево с n_right = n – 1 – n_left
    if (!n) {
        return nullptr;
    }
    Tree* tree = new Tree(generateRandom(0.0, 10.0));
    int nLeft = n / 2;
    int nRight = n - n / 2 - 1;
    tree->left = buildBalancedTree(nLeft);
    tree->right = buildBalancedTree(nRight);
    return tree;
}

template<class T>
T Tree::generateRandom(const T& low, const T& high) {
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
    } else if ((typeid(T).name() == d) || (typeid(T).name() == e) || (typeid(T).name() == ll)) {
        std::uniform_real_distribution<> dis(low, high);
        return dis(gen);
    }
    return 0;
}
void Tree::printTree(const int& level) {
    if (this != nullptr) {
        this->left->printTree(level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << "\t";
        }
        std::cout << std::fixed << std::setprecision(2) << this->data << std::endl;
        this->right->printTree(level + 1);
    }
}
int Tree::getHeight() {
    if (this != nullptr) {
        int hLeft = this->left->getHeight();
        int hRight = this->right->getHeight();
        if (hLeft >= hRight) {
            return hLeft + 1;
        } else {
            return hRight + 1;
        }
    }
    return 0;
}

void Tree::insertLeftBranch(const double& dt) {
    if (this->left == nullptr) {
        Tree* newNode = new Tree(dt);
        this->left = newNode;
    } else {
        this->left->insertLeftBranch(dt);
    }
}

void Tree::insertRightBranch(const double& dt) {
    if (this->right == nullptr) {
        Tree* newNode = new Tree(dt);
        this->right = newNode;
    } else {
        this->right->insertRightBranch(dt);
    }
}
double Tree::min() {
    //Не придумал ничего умнее, как сделать переменную static. Означает, что переменная инициализируется один
    //раз и будет жить до завершения функции.
    static double minElem = this->data;
    if (this != nullptr) {
        if (this->data < minElem) {
            minElem = this->data;
        }
        this->left->min();
        this->right->min();
    }
    return minElem;
}
std::vector<double> Tree::balancedTreeToVector() {
    static std::vector<double> v;
    if (this != nullptr) {
        v.push_back(this->data);
        this->left->balancedTreeToVector();
        this->right->balancedTreeToVector();
    }
    std::sort(v.begin(), v.end());
    return v;
}

Tree* Tree::createBalancedSearchTree() {
    std::vector<double> v = this->balancedTreeToVector();
    constexpr int VECTOR_BEGIN = 0;
    const int VECTOR_END = static_cast<int> (v.size() - 1);
    Tree* bstTree = sortedArrayToBST(v, VECTOR_BEGIN, VECTOR_END);
    return bstTree;
}

Tree* Tree::sortedArrayToBST(std::vector<double> v, int start, int end) {
    /* Подглядел алгоритм создания сбалансированного дерева поиска из ОТСОРТИРОВАННОГО массива.
 * https://bit.ly/3xEi628
 * https://bit.ly/3uVjhZf
 *
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
    Tree* tree = new Tree(v[middle]);
    tree->left = sortedArrayToBST(v, start, middle - 1);
    tree->right = sortedArrayToBST(v, middle + 1, end);
    return tree;
}
void Tree::insertToTree(const double& dt) {
    Tree* tree = this;
    while (tree != nullptr) {
        if (dt >= tree->data) {
            if (tree->right != nullptr) {
                tree = tree->right;
            } else {
                Tree* newNode = new Tree(dt);
                tree->right = newNode;
                break;
            }
        } else if (dt < tree->data) {
            if (tree->left != nullptr) {
                tree = tree->left;
            } else {
                Tree* newNode = new Tree(dt);
                tree->left = newNode;
                break;
            }
        }
    }
}
int Tree::getAmountOfNodes() {
    if (this == nullptr) {
        return 0;
    }
    if ((this->left == nullptr) && (this->right == nullptr)) {
        return 1;
    }
    int l{};
    int r{};
    if (this->left != nullptr) {
        l = this->left->getAmountOfNodes();
    }
    if (this->right != nullptr) {
        r = this->right->getAmountOfNodes();
    }
    return (l + r + 1);
}
void Tree::levelScan() {
    std::vector<Tree*> v;
    Tree* p = this;
    v.push_back(p);
    for (int i = 0; i < this->getAmountOfNodes(); i++) {
        if (v.at(i)->left != nullptr)
            v.push_back(v.at(i)->left);
        if (v.at(i)->right != nullptr)
            v.push_back(v.at(i)->right);
    }
    for (const auto& i: v) {
        std::cout << i->getData() << " ";
    }
    std::cout << std::endl;
}
double Tree::getData() {
    if (this != nullptr) {
        return data;
    } else {
        return 0.0;
    }
}

Tree* Tree::replaceNULLforEmpty() {
    Tree* tree = this->copyTree();
    int h = tree->getHeight();
    tree = replace_help(tree, h);
    return tree;
}
Tree* Tree::replace_help(Tree* tree, const int& h) {
    //int curLevel = getLevel(tree);
    int curLevel = 1;
    if ((tree->getLeft() == nullptr) && (curLevel != h - 1)) {
        tree->insertLeftBranch(0.0);
    }
    if ((tree->getRight() == nullptr) && (curLevel != h - 1)) {
        tree->insertRightBranch(0.0);
    }
    if (tree->getLeft() != nullptr) {
        tree->addLeftTree(replace_help(tree->getLeft(), h));
    }
    if (tree->getRight() != nullptr) {
        tree->addRightTree(replace_help(tree->getRight(), h));
    }
    return tree;
}

int Tree::getLevel(Tree* tree) {
    static const int n = this->getHeight();
    static const int m = tree->getHeight();
    return (n - m);
}

Tree* Tree::copyTree() {
    Tree* tree = new Tree(this->data);
    if (this->left != nullptr)
        tree->left = this->left->copyTree();
    if (this->right != nullptr)
        tree->right = this->right->copyTree();
    return tree;
}

void Tree::postorder(int indent) {
    if (this != nullptr) {
        if (this->right) {
            this->right->postorder(indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (this->right) {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << this->data << "\n ";
        if (this->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            this->left->postorder(indent + 4);
        }
    }
}

#pragma clang diagnostic pop