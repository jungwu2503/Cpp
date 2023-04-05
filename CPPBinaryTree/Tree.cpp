#include <iostream>
using namespace std;
#include "tree.h"

void Tree::TreeNode::add(int x) 
{
	if (x > data) {
		if (rchild == NULL) {
			TreeNode *newNode = new TreeNode(x);
			rchild = newNode;
		} else {
			rchild->add(x);
		}
	} else {
		if (lchild == NULL) {
			TreeNode *newNode = new TreeNode(x);
			lchild = newNode;
		} else {
			lchild->add(x);
		}
	}
}

void Tree::TreeNode::inorder() 
{
	if (lchild != NULL) lchild->inorder();
	cout << data << " ";
	if (rchild != NULL) rchild->inorder();
}

void Tree::TreeNode::preorder() 
{
	cout << data << " ";
	if (lchild != NULL) lchild->preorder();
	if (rchild != NULL) rchild->preorder();
}

void Tree::TreeNode::postorder() 
{
	if (lchild != NULL) lchild->postorder();
	if (rchild != NULL) rchild->postorder();
	cout << data << " ";
}

int Tree::TreeNode::getDepth()
{
	int n1 = 0;
	int n2 = 0;

	if (lchild != NULL) n1 = lchild->getDepth();
	if (rchild != NULL) n2 = rchild->getDepth();
	if (n1 > n2) return n1 + 1;
	else return n2 + 1;
}

int Tree::TreeNode::getCount()
{
	int n1 = 0;
	int n2 = 0;

	if (lchild != NULL) n1 = lchild->getCount();
	if (rchild != NULL) n2 = rchild->getCount();
	return n1 + n2 + 1;
}

Tree::Tree() 
{
	root = NULL;
	count = 0;
}

void Tree::add(int x)
{
	count++;
	if (root == NULL) {
		TreeNode *newNode = new TreeNode(x);
		root = newNode;
		return;
	}
	root->add(x);
}

void Tree::inorder()
{
	cout << "[ ";
	if (root == NULL) {
		cout << "]" << endl;
		return;
	}
	root->inorder();
	cout << "]" << endl;
}

void Tree::preorder()
{
	cout << "[ ";
	if (root == NULL) {
		cout << "]" << endl;
		return;
	}
	root->preorder();
	printf("]\n");
}

void Tree::postorder()
{
	cout << "[ ";
	if (root == NULL) {
		cout << "]" << endl;
		return;
	}
	root->postorder();
	printf("]\n");
}

int Tree::getDepth() 
{
	if (root == NULL) {
		return 0;
	}
	return root->getDepth();
}