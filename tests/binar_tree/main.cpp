#include <iostream>
#include "fstream"
using namespace std;

struct Node
{
    double label;
    Node* left;
    Node* right;

    ~Node() {
        delete left;
        delete right;
    }
};

void insertSearchNode(Node** tree, double x)
{
    if (*tree) {
        if (x < (*tree)->label)
            insertSearchNode(&(*tree)->left, x);
        else
            insertSearchNode(&(*tree)->right, x);
    }
    else {
        *tree = new Node;
        (*tree)->label = x;
        (*tree)->right = NULL;
        (*tree)->left = NULL;
    }
}
void insertArrayTree(double arr[], int n, Node** tree)
{
    for (int i = 0; i < n; i++)
        insertSearchNode(tree, arr[i]);
}

void insertIntoArray(double arr[], Node** tree, int* i)
{
    if (*tree) {
        if ((*tree)->left) insertIntoArray(arr, &(*tree)->left, i);
        arr[(*i)++] = (*tree)->label;
        if ((*tree)->right) insertIntoArray(arr, &(*tree)->right, i);
    }
}
void print_tree_level(Node *top, int level) {
    if (top) {
        print_tree_level(top->left, level + 1);
        for (int i = 0; i < level; i++)
            cout << "_____";
        cout << top->label << endl;
        print_tree_level(top->right, level + 1);
    }
}

int main()
{
    Node* maintree = NULL;
    int num = 10;
    double *arr = new double[num];
    ifstream inData;
    inData.open("p.txt");
    for (int i = 0; i < num; i++) {
        inData >> arr[i];
        cout << arr[i] <<"  ";
    }inData.close();
    cout << endl;
    insertArrayTree(arr, num, &maintree);
    int index = 0;
    insertIntoArray(arr, &maintree, &index);
    print_tree_level(maintree, 0);

    delete maintree;

    for (int y = 0; y < num; y++)
        cout << arr[y] << ' ';
    cout << '\n';
}