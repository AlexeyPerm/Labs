/*
	*	Implementation of Tidy Drawings of Trees by CHARLES WETHERELL AND ALFRED SHANNON (Algorithm3)
	*	INPUT: root and height of an already constructed binary tree, calling bst_init from bst.h file
	*	OUTPUT: Drawing of the tree in OpenGL
	*
	*	This file does the intermediate processing of finding the coordinates of center of each node.
	*	These coordinates are then passed to draw.h which then draws the tree using midpoint line and circle algos in openGL
	*
	*	Compilation: g++ main.cpp -lglut -lGL -lGLU
*/

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>

#include "bst.h"									//constructing a sample binary tree
#include "draw.h"									//draw the tree
using namespace std;

/* Program entry point */
/*Node structure
struct Node{
	int data;
	int x, y;										//x and y coordinates, y also stores the height of the node
	int modifier;									//amount of shift for the subtree
	struct Node *left, *right;						//left and right subtrees
};
*/

//Shortcuts
#define inf INT_MAX
#define _inf INT_MIN

//globals
int next_pos[100] = { 0 };							//next available position for each level, initialized with 0

//This function does the processing of the tree, assigns coordinates, modifiers
struct Node* process(struct Node* root) {
	struct Node* left = root->left, * right = root->right;
	int height = root->y, prov_pos = _inf, actual_pos, modifier = 0;

	if (left == NULL && right == NULL) {				//if leaf node actual will simply be the 1st available pos on its level
		actual_pos = next_pos[height];
		modifier = 0;
	}
	else if (left == NULL || right == NULL) {			//only one child
		if (left == NULL) {							//only right child
			right = process(right);
			prov_pos = right->x - 1;
		}
		else {										//only left child
			left = process(left);
			prov_pos = left->x + 1;
		}
		actual_pos = max(prov_pos, next_pos[height]);
		if (next_pos[height] > prov_pos) modifier = next_pos[height] - prov_pos;
	}
	else {											//if both children present
		left = process(left);
		right = process(right);
		prov_pos = (left->x + right->x) / 2;
		actual_pos = max(prov_pos, next_pos[height]);
		if (next_pos[height] > prov_pos) modifier = next_pos[height] - prov_pos;
	}

	next_pos[height] = actual_pos + 2;				//incrementing next available position on this level
	root->x = actual_pos;
	root->modifier = modifier;
	return root;
}

//Does the approprite shifting of the subtrees based on modifier
struct Node* modify(struct Node* root, int shft) {
	if (root == NULL) return NULL;
	root->x = root->x + shft;						//shift towards right
	root->left = modify(root->left, shft + root->modifier);
	root->right = modify(root->right, shft + root->modifier);
	return root;
}

//Inorder traversal of tree
void inorder(struct Node* root) {
	//Inorder traversal of tree
	if (root == NULL) return;
	inorder(root->left);
	printf("data=%d, x=%d, y=%d, modifier=%d\n", root->data, root->x, root->y, root->modifier);
	inorder(root->right);
}

int main(int argc, char* argv[]) {

	pair<struct Node*, int> p = bst_init();			//pair that stores the root and height of the tree
	struct Node* root = p.first;                    //root of the tree
	int height = p.second;                          //height of the tree

	root = process(root);							//assign coordinates
	root = modify(root, 0);							//shift based on modifier
	inorder(root);

	draw_main(root, height, argc, argv);			//draw tree, function in draw.h

	return 0;
}