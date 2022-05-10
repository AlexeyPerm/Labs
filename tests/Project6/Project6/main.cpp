#include "Tree.h"
#include "Search.h"

int main() {

	//Tree<int>* tree = new Tree<int>('A');
	//tree->insertLeft('B');
	//tree->getLeft()->insertLeft('D');
	//tree->getLeft()->getLeft()->insertLeft('G');
	//tree->getLeft()->insertRight('E');
	//tree->getLeft()->getLeft()->insertRight('H');
	//tree->insertRight('C');
	//tree->getRight()->insertRight('F');
	//tree->getRight()->getRight()->insertLeft('I');
	//tree->getRight()->getRight()->insertRight('J');

	//SearchTree<int>* tree = new SearchTree<int>(2);
	//tree->insertNode(1);
	//tree->insertNode(3);
	//tree->insertNode(6);
	//tree->insertNode(4);
	//tree->insertNode(7);
	//tree->insertNode(1);
	//tree->printSearchTree(1);


	cout << "n=";
	int n;
	cin >> n;
	Tree<int>* tree = Tree<int>::balancedTree(n);
	tree->printTree(1);


	return 0;
}