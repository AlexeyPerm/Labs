template<class S>
class SearchTree {
public:
    S data; // Данные типа Т
    SearchTree* left; // Указатель на узел слева
    SearchTree* right; // Указатель на узел справа
    SearchTree* parent; // Указатель на предка
    SearchTree(S); // Конструктор
    ~SearchTree(); // Деструктор
    void deleteSearchTree() { delete this; }
// Удалить дерево
    void printSearchTree(int);
// Горизонтальная печать дерева
    void inOrder(SearchTree<S>*);
// Симметричный обход дерева
    void setData(S dt) { data = dt; }
// Установить данные для узла
    SearchTree<S>* next(); // Найти следующий элемент
    SearchTree<S>* prev(); // Найти предыдущий элемент
    void insertNode(S); // Вставить узел
    void deleteNode(S); // Удалить узел
    SearchTree<S>* findElement(S); // Найти элемент
    SearchTree<S>* findMax(); // Найти максимум
    SearchTree<S>* findMin(); // Найти минимум
};

template<class S>
SearchTree<S>* SearchTree<S>::findElement(S dt) {
    if ((this == NULL) || (dt == this->data))
        return this;
    if (dt < this->data)
        return this->left->findElement(dt);
    else return this->right->findElement(dt);
}

template<class S>
SearchTree<S>* SearchTree<S>::findMin() {
    if (this->left == NULL)
        return this;
    return this->left->findMin();
}
template<class S>
SearchTree<S>* SearchTree<S>::findMax() {
    if (this->right == NULL)
        return this;
    return this->right->findMax();
}

template<class S>
SearchTree<S>* SearchTree<S>::next() {
    SearchTree* tree = this;
    if (tree->right != NULL)
        return tree->right->findMin();
    SearchTree<S>* t = tree->parent;
    while ((t != NULL) && (tree == t->right)) {
        tree = t;
        t = t->parent;
    }
    return t;
}
template<class S>
SearchTree<S>* SearchTree<S>::prev() {
    SearchTree* tree = this;
    if (tree->left != NULL)
        return tree->left->findMax();
    SearchTree<S>* t = tree->parent;
    while ((t != NULL) && (tree == t->left)) {
        tree = t;
        t = t->parent;
    }
    return t;
}