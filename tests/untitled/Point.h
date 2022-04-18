#pragma once
#include<iostream>
using namespace std;

struct point
{
    double data;
    point* left;
    point* right;
};

point* create_point(double data)
{
    point* p = new point();
    p->data = data;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}

point* build_ideal_tree(int n)
{
    if (n == 0)
        return NULL;
    point* p = create_point(rand() % 100);
    int n1 = n / 2;
    int n2 = n - n1 - 1;
    p->left = build_ideal_tree(n1);
    p->right = build_ideal_tree(n2);

    return p;
}

void print_tree(point* root, int level)
{
    if (root != nullptr)
    {
        print_tree(root->right, level + 1);

        for (int i = 0; i < 5*level; i++)
            cout << " ";

        cout << root->data << endl;
        print_tree(root->left, level + 1);
    }
}

void find_min(point* root, double& min)
{
    if (root != nullptr)
    {
        if (root->data < min)
            min = root->data;
        find_min(root->left, min);
        find_min(root->right, min);
    }
}

double find_min_find_tree(point* root)
{
    while (root->left != nullptr)
        root = root->left;

    return root->data;
}

void destroy(point* root)
{
    if (root != NULL)
    {
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}

void add(point** root, double val)
{
    if ((*root) == NULL)
    {
        (*root) = create_point(val);
        return;
    }

    if (val > (*root)->data)
        add(&(*root)->right, val);
    else if (val < (*root)->data)
        add(&(*root)->left, val);
}

void build_find_tree(point* root, point** new_root)
{
    if (root != nullptr)
    {
        add(new_root, root->data);
        build_find_tree(root->left, new_root);
        build_find_tree(root->right, new_root);
    }
}
