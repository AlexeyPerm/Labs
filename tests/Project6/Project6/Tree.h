#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Tree {
private:
	T data;											// ������ ���� �
	Tree* left;										// ��������� �� ���� �����
	Tree* right;									// ��������� �� ���� ������
	Tree* parent;									// ��������� �� ������
public:
	Tree(T);										// �����������
	~Tree();										// ����������

	void insertLeft(T);							// �������� ���� �����
	void insertRight(T);							// �������� ���� ������

	void addLeftTree(Tree<T>* tree) { left = tree; }	// �������� ��������� �����
	void addRightTree(Tree<T>* tree) { right = tree; }	// �������� ��������� ������

	Tree<T>* ejectLeft();							// ������� ��������� �����
	Tree<T>* ejectRight();							// ������� ��������� ������

	void deleteLeft();								// ������� ��������� �����
	void deleteRight();								// ������� ��������� ������

	void setData(T dt) { data = dt; } // ���������� ������ ��� ����

	/* ������ ������ � ������� ���������
	� ������ ������� (������ ����) */
	static void preOrder(Tree<T>*);

	/* ������ ������ � ������� ��������� �
	������������ ������� (����� �������) */
	static void inOrder(Tree<T>*);

	/* ������ ������ � ������� ���������
	� �������� ������� (����� �����) */
	static void postOrder(Tree<T>*);

	Tree<T>* copyTree();							// ����������� ������

	T getData() {
		if (this != nullptr) {
			return data;
		}
		else {
			return NULL;
		}
	}

	void printTree(int);							// ������ ������ �������������
	void printVTree(int);							// ������ ������ �����������

	/* ����������� �� ������ � ������ � ���� */
	void obhod(Tree<T>* node);

	void printVTree2();								// ������ ������ ����������� (2)

	int getAmountOfNodes();							// �������� ���������� ��������� ������
		/* �������� ������ ������
		(������� � �������� ���� �� ����������� � �������) */
	int getHeight();

	/* ��������� �� ������� ������ ������
	������� � ����� � ������� �������� */
	void levelScan();
	void deleteTree() { delete this; }				// ������� ������
	/* ���� ������ ��������, ������� ��� ������
	(����������� ���� ���������� ������ NULL) */


	Tree<T>* getLeft() { return left; }				// �������� ����� ����
	Tree<T>* getRight() { return right; }			// �������� ������ ����
	Tree<T>* getParent() { return parent; }			// �������� ��������


	void findElement_insertLeft(Tree<T>*, T, T);	//����� ������� � �������� � ���� ����� ����
	void findElement_insertRight(Tree<T>*, T, T);	//����� ������� � �������� � ���� ������ ����

	/* ��������� �������� ����������������
	������ �� ������� ���������� ��������� */
	static Tree<T>* balancedTree(int n);
};

template<class T>
int Tree<T>::getAmountOfNodes() {
	if (this == NULL) {
		return 0;
	}
	if ((this->left == NULL) && (this->right == NULL)) {
		return 1;
	}
	int l = 0;
	int r = 0;
	if (this->left != NULL) {
		l = this->left->getAmountOfNodes();
	}
	if (this->right != NULL) {
		r = this->right->getAmountOfNodes();
	}
	return (l + r + 1);
}

template <class T>
int Tree<T>::getHeight() {
	int h1 = 0, h2 = 0, hadd = 0;
	if (this == NULL) {
		return 0;
	}
	if (this->left != NULL) {
		h1 = this->left->getHeight();
	}
	if (this->right != NULL) {
		h2 = this->right->getHeight();
	}
	if (h1 >= h2) {
		return h1 + 1;
	}
	else {
		return h2 + 1;
	}
}

template<class T>
void Tree<T>::levelScan() {
	vector<Tree<T>*> V;
	Tree<T>* p = this;
	V.push_back(p);
	for (int i = 0; i < this->getAmountOfNodes(); i++) {
		if (V[i]->left != NULL) {
			V.push_back(V[i]->left);
		}
		if (V[i]->right != NULL) {
			V.push_back(V[i]->right);
		}
	}
	for (int i = 0; i < V.size(); i++) {
		cout << V.at(i)->getData() << " ";
	}
	cout << endl;
}

template <class T>
int getLevel(Tree<T>* tree);

template<class T>
Tree<T>::Tree(T dt) {					// ����������� ����
	data = dt;						// �������� ������ �� ���������
	left = nullptr;					// ������� ��� ���������
	right = nullptr;
	parent = nullptr;
}

template<class T>
Tree<T>::~Tree() {					// ���������� ������
	delete this->left;
	delete this->right;
}

template <class T>
void Tree<T>::insertLeft(T dt) {
	Tree<T>* node = new Tree(dt);
	if (this->left != nullptr) {
		this->left->parent = node;	//������� ���, ����� ��� ������� ��� ����� ���� */
	}
	node->left = this->left;		//������ � ������ ���� ����� ������� � ��� ����� ������� ����������� ���� */
	this->left = node;				//� ���������� ���� ������ ����� ������ ������� � ��� ����� ���� */
	node->parent = this;			//���������, ��� � ������ ���� ������ ������� �������� ������� ���� */
}

template<class T>
void Tree<T>::insertRight(T dt) {
	Tree<T>* node = new Tree(dt);
	if (this->right != nullptr) {
		this->right->parent = node;
	}
	node->right = this->right;
	this->right = node;
	node->parent = this;
}

// ������ ����� (������ ����)
template<class T>
void Tree<T>::preOrder(Tree<T>* node) {
	if (node != NULL) {
		cout << node->getData() << "";
		reorder(node->left);
		reorder(node->right);
	}
}

// ������������ ����� (����� �������)
template<class T>
void Tree<T>::inOrder(Tree<T>* node) {
	if (node != NULL) {
		inOrder(node->left);
		cout << node->getData() << "";
		inOrder(node->right);
	}
}

// �������� ����� (����� �����)
template<class T>
void Tree<T>::postOrder(Tree<T>* node) {
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		cout << node->getData() << "";
	}
}

template<class T>
Tree<T>* Tree<T>::ejectLeft() {		// ����������
	if (this->left != NULL) {
		Tree<T>* temp = this->left;
		this->left = NULL;
		return temp;
	}
	return NULL;
}

template<class T>
void Tree<T>::deleteLeft() {		// ��������
	Tree<T>* temp = this->ejectLeft();
	delete temp;
}

template<class T>
Tree<T>* Tree<T>::ejectRight() {
	if (this->right != NULL) {
		Tree<T>* temp = this->right;
		this->right = NULL;
		return temp;
	}
	return NULL;
}

template<class T>
void Tree<T>::deleteRight() {
	Tree<T>* temp = this->ejectRight();
	delete temp;
}

template<class T>
void Tree<T>::printTree(int level) {
	if (this != NULL) {
		this->left->printTree(level + 1);
		for (int i = 1; i < level; i++) cout << " ";
		cout << this->getData() << endl;
		this->right->printTree(level + 1);
	}
}

template<class T>
Tree<T>* Tree<T>::copyTree() {
	Tree<T>* tree = new Tree<T>(this->data);
	if (this->parent != NULL) {
		tree->parent = this->parent;
	}
	if (this->left != NULL) {
		tree->left = this->left->copyTree();
	}
	if (this->right != NULL) {
		tree->right = this->right->copyTree();
	}
	return tree;
}





