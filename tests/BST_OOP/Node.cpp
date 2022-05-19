
#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"
#pragma ide diagnostic ignored "misc-no-recursion"

#include "Node.h"
#include "func.h"
#include <random>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "GL/glut.h"

Node::Node(const double& dt) {
    data = dt;
    node_x = node_y = 0;
    text_x = text_y = 0;
    left = nullptr;
    right = nullptr;
}

Node::~Node() {
    delete this->left;
    delete this->right;
}

Node* Node::buildBalancedTree(const int& n) {
//Построить левое поддерево с n_left = n/2 (деление по модулю).
//Построить правое поддерево с n_right = n – 1 – n_left
    if (!n) {
        return nullptr;
    }
//    double dt{};
//    std::cout << "Data>";
//    std::cin >> dt;
    Node* tree = new Node(generateRandom(0.0, 10.0));
    int nLeft = n / 2;
    int nRight = n - n / 2 - 1;
    tree->left = buildBalancedTree(nLeft);
    tree->right = buildBalancedTree(nRight);
    return tree;
}

template<class T>
T Node::generateRandom(const T& low, const T& high) {
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
void Node::printTree(const int& level) {
    if (this != nullptr) {
        this->left->printTree(level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << "\t";
        }
        std::cout << std::fixed << std::setprecision(2) << this->data << std::endl;
        this->right->printTree(level + 1);
    }
}
int Node::getHeight() {
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

void Node::insertLeftBranch(const double& dt) {
    if (this->left == nullptr) {
        Node* newNode = new Node(dt);
        this->left = newNode;
    } else {
        this->left->insertLeftBranch(dt);
    }
}

void Node::insertRightBranch(const double& dt) {
    if (this->right == nullptr) {
        Node* newNode = new Node(dt);
        this->right = newNode;
    } else {
        this->right->insertRightBranch(dt);
    }
}
double Node::min() {
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
std::vector<double> Node::balancedTreeToVector() {
    static std::vector<double> v;
    if (this != nullptr) {
        v.push_back(this->data);
        this->left->balancedTreeToVector();
        this->right->balancedTreeToVector();
    }
    std::sort(v.begin(), v.end());
    return v;
}

Node* Node::createBalancedSearchTree() {
    std::vector<double> v = this->balancedTreeToVector();
    constexpr int VECTOR_BEGIN = 0;
    const int VECTOR_END = static_cast<int> (v.size() - 1);
    Node* bstTree = sortedArrayToBST(v, VECTOR_BEGIN, VECTOR_END);
    return bstTree;
}

Node* Node::sortedArrayToBST(std::vector<double> v, int start, int end) {
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
    Node* tree = new Node(v[middle]);
    tree->left = sortedArrayToBST(v, start, middle - 1);
    tree->right = sortedArrayToBST(v, middle + 1, end);
    return tree;
}
void Node::insertToTree(const double& dt) {
    Node* tree = this;
    while (tree != nullptr) {
        if (dt >= tree->data) {
            if (tree->right != nullptr) {
                tree = tree->right;
            } else {
                Node* newNode = new Node(dt);
                tree->right = newNode;
                break;
            }
        } else if (dt < tree->data) {
            if (tree->left != nullptr) {
                tree = tree->left;
            } else {
                Node* newNode = new Node(dt);
                tree->left = newNode;
                break;
            }
        }
    }
}
int Node::getAmountOfNodes() {
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
void Node::levelScan() {
    std::vector<Node*> v;
    Node* p = this;
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
double Node::getData() {
    if (this != nullptr) {
        return data;
    } else {
        return 0.0;
    }
}

Node* Node::replaceNULLforEmpty() {
    Node* node = this->copyTree();
    int h = node->getHeight();
    node = replace_help(node, h);
    return node;
}
Node* Node::replace_help(Node* node, const int& h) {
    //int curLevel = getLevel(node);
    int curLevel = 1;
    if ((node->getLeft() == nullptr) && (curLevel != h - 1)) {
        node->insertLeftBranch(0.0);
    }
    if ((node->getRight() == nullptr) && (curLevel != h - 1)) {
        node->insertRightBranch(0.0);
    }
    if (node->getLeft() != nullptr) {
        node->addLeftTree(replace_help(node->getLeft(), h));
    }
    if (node->getRight() != nullptr) {
        node->addRightTree(replace_help(node->getRight(), h));
    }
    return node;
}
int Node::getLevel(Node* node) {
    static const int n = this->getHeight();
    static const int m = node->getHeight();
    return (n - m);
}
Node* Node::copyTree() {
    Node* tree = new Node(this->data);
    if (this->left != nullptr)
        tree->left = this->left->copyTree();
    if (this->right != nullptr)
        tree->right = this->right->copyTree();
    return tree;
}
void Node::printVTree(const int& k) {
    int height = this->getHeight();
    int maxLeafs = std::pow(2, height - 1); //Максимальное число листов на нижнем уровне (нумерация с нуля)
    int width = 2 * maxLeafs - 1;                 // Минимальная ширина дерева для печати (не конечная, но необходимая)
    int curLevel = 0; // Номер строки (на выводе)
    int index = 0;  // Номер элемента в строке (нумерация с нуля)
    int factSpaces = getPos(index, width, curLevel, height - 1);    //Позиция корня (число пробелов перед ним)
    pos node;
    std::vector<Node*> v;
    std::vector<pos> vi;

    Node* t = this->copyTree();
    t = t->replaceNULLforEmpty();
    Node* p = t;
    v.push_back(p);
    node.col = factSpaces;
    node.str = curLevel;
    vi.push_back(node);

    for (int i = 0; i < t->getAmountOfNodes(); i++) {
        if (pow(2, curLevel) <= index + 1) {
            index = 0;
            curLevel++;
        }
        if (v.at(i)->left != nullptr) {
            v.push_back(v.at(i)->left);
            factSpaces = getPos(index, width, curLevel, height - 1);
            node.col = factSpaces;
            node.str = curLevel;
            vi.push_back(node);
            index++;
        }
        if (v.at(i)->right != nullptr) {
            v.push_back(v.at(i)->right);
            factSpaces = getPos(index, width, curLevel, height - 1);
            node.col = factSpaces;
            node.str = curLevel;
            vi.push_back(node);
            index++;
        }
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        if (i != 0) {
            if (vi.at(i - 1).str == vi.at(i).str) {
                vi.at(i).col = vi.at(i).col - vi.at(i - 1).col - 1;
            }
        }
    }
    int flag = 0; // Следит за тем, что y меняется
    for (int i = 0; i < v.size(); i++) {
        node = vi.at(i);
        curLevel = node.str;
        if (flag < curLevel) {  // Переход на новую строчку будет, когда y1 станет меньше y (слежка за изменением y) */
            flag = curLevel;
            std::cout << std::endl;
        }
        factSpaces = node.col;
        int realSpaces = k * factSpaces;
        for (int j = 0; j < realSpaces; j++) std::cout << " ";
        if (v.at(i)->getData() != 0.0) std::cout << v.at(i)->getData();
        else for (int j = 0; j < k; j++) std::cout << " ";
    }
    std::cout << std::endl;
}

void Node::postorder(int indent) {
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

void drawTree(int argc, char** argv, int window_width, int window_height){

}

#pragma clang diagnostic pop