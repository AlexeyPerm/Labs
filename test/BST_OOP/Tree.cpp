#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"
#pragma ide diagnostic ignored "misc-no-recursion"

#include "Tree.h"
#include "TreeTools.h"
#include <cmath>
#include <random>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

//extern SGlutContextStruct;

Tree::Tree(const double& dt) {
    data    = dt;
    left    = nullptr;
    right   = nullptr;
    parent  = nullptr;
    node_x  = node_y = 0;
    text_x  = text_y = 0;
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
    int h1{};
    int h2{};
    //int hadd = 0;
    if (this == nullptr) {
        return 0;
    }
    if (this->left != nullptr) {
        h1 = this->left->getHeight();
    }
    if (this->right != nullptr) {
        h2 = this->right->getHeight();
    }
    return ((h1 >= h2 ? h1 : h2) + 1);      //Если h1 >= h2, то вернём h1 + 1, иначе h2 + 2;
}

void Tree::insertLeftBranch(const double& dt) {
    Tree* node = new Tree(dt);
    if (this->left) {
        this->left->parent = node;
    }
    node->left   = this->left;
    this->left   = node;
    node->parent = this;
}

void Tree::insertRightBranch(const double& dt) {
    Tree* node = new Tree(dt);
    if (this->right) {
        this->right->parent = node;
    }
    node->right  = this->right;
    this->right  = node;
    node->parent = this;
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
    int middle  = (start + end) / 2;
    Tree* tree  = new Tree(v[middle]);
    tree->left  = sortedArrayToBST(v, start, middle - 1);
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
        if (v[i]->left != nullptr)
            v.emplace_back(v[i]->left);
        if (v[i]->right != nullptr)
            v.emplace_back(v[i]->right);
    }
    for (const auto& i: v) {
        std::cout << i->getData() << " ";
    }
    std::cout << std::endl;
}

double Tree::getData() {
    return this != nullptr ? data : NULL;
}

int Tree::getLevel(Tree* tree) {
    return tree->getParent() == nullptr ? 0 : getLevel(tree->getParent()) + 1;
}

Tree* Tree::replaceNullForEmpty() {
    Tree* node = this->copyTree();
    int h = node->getHeight();
    node = replace_help(node, h);
    return node;
}

Tree* Tree::replace_help(Tree* node, int h) {
    int curLevel = getLevel(node);
    if ((node->getLeft() == nullptr) && (curLevel != h - 1)) {
        node->insertLeftBranch(NULL);
    }
    if ((node->getRight() == nullptr) && (curLevel != h - 1)) {
        node->insertRightBranch(NULL);
    }
    if (node->getLeft() != nullptr) {
        node->addLeftTree(replace_help(node->getLeft(), h));
    }
    if (node->getRight() != nullptr) {
        node->addRightTree(replace_help(node->getRight(), h));
    }
    return node;
}

Tree* Tree::copyTree() {
    Tree* tree = new Tree(this->data);
    if (this->parent != nullptr) {
        tree->parent =  this->parent;
    }
    if (this->left != nullptr) {
        tree->left =  this->left->copyTree();
    }
    if (this->right != nullptr) {
        tree->right =  this->right->copyTree();
    }
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


void Tree::setCoordsForNode(int window_width, int window_height, int shift,
                            int tree_width, int tree_height, int x, int y, int R) {
    if (tree_width != tree_height) {
        int k_x = (window_width - 2 * (shift + R)) / (tree_width - 1); // Коэффициент пропорциональности по оси Ох
    }

}
Tree* Tree::getNodeByCoords(int x, int y, int R) {
    return nullptr;
}
void Tree::setCoordsForText(int k, int shift) {

}
void Tree::drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k) {

}
void Tree::printVTree(const int& k) {
    std::cout << std::fixed << std::setprecision(2);
    const int height = this->getHeight();
    // Максимальное число листов на нижнем уровне (нумерация с нуля)
    const int maxLeafs = static_cast<int> (std::pow(2, height - 1));
    int curLevel = 0;                   //номер строки на выводе
    int index    = 0;
    int width    = 2 * maxLeafs - 1;    // Минимальная ширина дерева для печати (не конечная, но необходимая)
    // Номер элемента в строке (нумерация с нуля) Позиция корня (число пробелов перед ним)
    int factSpaces = getPos(index, width, curLevel, height - 1);
    pos node{};
    std::vector<Tree*> vNodes;
    std::vector<pos>   vPos;

    Tree* t = this->copyTree();
    t = t->replaceNullForEmpty();
    Tree* p = t;
    vNodes.emplace_back(p);
    node.col = factSpaces;
    node.str = curLevel;
    vPos.emplace_back(node);

    for (int i = 0; i < t->getAmountOfNodes(); ++i) {
        if (std::pow(2, curLevel) <= index + 1) {
            index = 0;
            ++curLevel;
        }
        if (vNodes[i]->left != nullptr) {
            vNodes.emplace_back(vNodes[i]->left);
            factSpaces = getPos(index, width, curLevel, height - 1);
            node.str   = curLevel;
            node.col   = factSpaces;
            vPos.emplace_back(node);
            ++index;
        }
        if (vNodes[i]->right != nullptr) {
            vNodes.emplace_back(vNodes[i]->right);
            factSpaces = getPos(index, width, curLevel, height - 1);
            node.str   = curLevel;
            node.col   = factSpaces;
            vPos.emplace_back(node);
            ++index;
        }
    }

    /* Редактируем позиции в строчках (теперь они обозначают количество пробелов
     * перед данным символом начиная с предыдущего символа): до этого эти значения
     * представляли собой координаты (как х)
     */
    for (int i = vNodes.size() - 1; i >= 0; i--) {
        if (i != 0) {
            if (vPos[i - 1].str == vPos[i].str) {
                vPos[i].col = vPos[i].col - vPos[i - 1].col - 1;
            }
        }
    }
    int flag = 0;   // Следит за тем, что y меняется
    for (int i = 0; i < vNodes.size(); i++) {
        node = vPos[i];
        curLevel = node.str;
// Переход на новую строчку будет, когда y1 станет меньше y (слежка за изменением y)
        if (flag < curLevel) {
            flag = curLevel;
            std::cout << std::endl;
        }
        factSpaces = node.col;
        int realSpaces = k * factSpaces;
        for (int j = 0; j < realSpaces; j++) {
            std::cout << " ";
        }
        if (vNodes[i]->getData() != 0.0) {
            std::cout << vNodes[i]->getData();
        } else {
            for (int j = 0; j < k; j++) {
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;
}

#pragma clang diagnostic pop