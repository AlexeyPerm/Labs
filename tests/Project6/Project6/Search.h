#pragma once
template <class S>
class SearchTree {
public:
	S data; // ������ ���� �
	SearchTree* left;								// ��������� �� ���� �����
	SearchTree* right;								// ��������� �� ���� ������
	SearchTree* parent;								// ��������� �� ������
	SearchTree(S); // �����������
	~SearchTree(); // ����������

	void deleteSearchTree() { delete this; }// ������� ������
	void printSearchTree(int);// �������������� ������ ������
	void inOrder(SearchTree<S>*);// ������������ ����� ������
	void setData(S dt) { data = dt; }// ���������� ������ ��� ����

	S getData() {
		if (this != nullptr) {
			return data;
		}
		else {
			return NULL;
		}
	}

	void insertNode(S); // �������� ����
	void deleteNode(S); // ������� ����

	SearchTree<S>* next(); // ����� ��������� �������
	SearchTree<S>* prev(); // ����� ���������� �������

	SearchTree<S>* findElement(S); // ����� �������
	SearchTree<S>* findMax(); // ����� ��������
	SearchTree<S>* findMin(); // ����� �������
};

template<class S>
SearchTree<S>::SearchTree(S dt) {					// ����������� ����
	data = dt;						// �������� ������ �� ���������
	left = nullptr;					// ������� ��� ���������
	right = nullptr;
	parent = nullptr;
}


template<class S>
SearchTree<S>::~SearchTree() {					// ���������� ������
	delete this->left;
	delete this->right;
}

template <class S>
void SearchTree<S>::insertNode(S dt) {
	SearchTree<S>* tree = this;
	while (tree != NULL) {
		if (dt >= tree->data) {
			if (tree->right != NULL) {
				tree = tree->right;
			}
			else {
				SearchTree<S>* t = new SearchTree<S>(dt);
				t->parent = tree;
				tree->right = t;
				break;
			}
		}
		else if (dt < tree->data) {
			if (tree->left != NULL) {
				tree = tree->left;
			}
			else {
				SearchTree<S>* t = new SearchTree<S>(dt);
				t->parent = tree;
				tree->left = t;
				break;
			}
		}
	}
}


template <class S>
SearchTree<S>* SearchTree<S>::next() {
	SearchTree* tree = this;
	if (tree->right != NULL) {
		return tree->right->findMin();
	}
	SearchTree<S>* t = tree->parent;
	while ((t != NULL) && (tree == t->right)) {
		tree = t;
		t = t->parent;
	}
	return t;
}

template <class S>
SearchTree<S>* SearchTree<S>::prev() {
	SearchTree* tree = this;
	if (tree->left != NULL) {
		return tree->left->findMax();
	}
	SearchTree<S>* t = tree->parent;
	while ((t != NULL) && (tree == t->left)) {
		tree = t;
		t = t->parent;
	}
	return t;
}

template <class S>
SearchTree<S>* SearchTree<S>::findElement(S dt) {
	if ((this == NULL) || (dt == this->data)) {
		return this;
	}
	if (dt < this->data) {
		return this->left->findElement(dt);
	}
	else {
		return this->right->findElement(dt);
	}
}

template <class S>
SearchTree<S>* SearchTree<S>::findMin() {
	if (this->left == NULL) {
		return this;
	}
	return this->left->findMin();
}
template <class S>
SearchTree<S>* SearchTree<S>::findMax() {
	if (this->right == NULL) {
		return this;
	}
	return this->right->findMax();
}

template<class S>
inline void SearchTree<S>::printSearchTree(int level) {
	if (this != NULL) {
		this->left->printSearchTree(level + 1);
		for (int i = 1; i < level; i++) cout << " ";
		cout << this->getData() << endl;
		this->right->printSearchTree(level + 1);
	}
}

template<class S>
void SearchTree<S>::deleteNode(S dt) {
	SearchTree<S>* e = this->findElement(dt);
	SearchTree<S>* p = e->parent;		//������ ���������� ��������
	if ((e->left == NULL) && (e->right == NULL)) {	// ������ ������: ��������� ������� �� ����� ��������
		if (p->left == e) {
			p->left = NULL;
		}
		if (p->right == e) {
			p->right = NULL;
		}
	}
	else if ((e->left == NULL) || (e->right == NULL)) {		// ������ ������: ��������� ������� ����� ������ �������
		if (e->left == NULL) {
			if (p->left == e) {
				p->left = e->right;
			}
			else {
				p->right = e->right;
			}
			e->right->parent = p;
		}
		else {
			if (p->left == e) {
				p->left = e->left;
			}
			else {
				p->right = e->left;
			}
			e->left->parent = p;
		}
	}
	else {
		SearchTree<S>* s = e->next();	// ��������� ������� �� ���������
		e->data = s->data;
		if (s->parent->left == s) {
			s->parent->left = s->right;
			if (s->right != NULL)
				s->right->parent = s->parent;
		}
		else {
			s->parent->right = s->right;
			if (s->right != NULL)
				s->right->parent = s->parent;
		}
	}
}

template <class T>
Tree<T>* Tree<T>::balancedTree(int n) {
	if (n == 0) {
		return NULL;
	}
	cout << "data= ";
	T dt{};
	cin >> dt;
	Tree<T>* tree = new Tree<T>(dt);
	tree->addLeftTree(balancedTree(n / 2));
	tree->addRightTree(balancedTree(n - n / 2 - 1));
	return tree;
}