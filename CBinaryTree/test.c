#include <stdio.h>
#include <malloc.h>

typedef struct _treeNode {
	struct _treeNode *lchild;
	int data;
	struct _treeNode *rchild;
} TreeNode;

typedef struct _tree {
	TreeNode *root;
	int count;
} Tree;

void initTree(Tree *tree)
{
	tree->root = NULL;
	tree->count = 0;
}

void addNode(TreeNode *node, int x) 
{
	if (x > node->data) {
		if (node->rchild == NULL) {
			TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
			newNode->lchild = NULL;
			newNode->data = x;
			newNode->rchild = NULL;
			node->rchild = newNode;
		} else {
			addNode(node->rchild, x);
		}
	} else {
		if (node->lchild == NULL) {
			TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
			newNode->lchild = NULL;
			newNode->data = x;
			newNode->rchild = NULL;
			node->lchild = newNode;
		} else {
			addNode(node->lchild, x);
		}
	}
}

void inorder(TreeNode *node) 
{
	if (node->lchild != NULL) inorder(node->lchild);
	printf("%d ", node->data);
	if (node->rchild != NULL) inorder(node->rchild);
}

void preorder(TreeNode *node) 
{
	printf("%d ", node->data);
	if (node->lchild != NULL) preorder(node->lchild);
	if (node->rchild != NULL) preorder(node->rchild);
}

void postorder(TreeNode *node) 
{
	if (node->lchild != NULL) postorder(node->lchild);
	if (node->rchild != NULL) postorder(node->rchild);
	printf("%d ", node->data);
}

int getDepth(TreeNode *node)
{
	int n1 = 0;
	int n2 = 0;

	if (node->lchild != NULL) n1 = getDepth(node->lchild);
	if (node->rchild != NULL) n2 = getDepth(node->rchild);
	if (n1 > n2) return n1 + 1;
	else return n2 + 1;
}

int getCount(TreeNode *node)
{
	int n1 = 0;
	int n2 = 0;

	if (node->lchild != NULL) n1 = getCount(node->lchild);
	if (node->rchild != NULL) n2 = getCount(node->rchild);
	return n1 + n2 + 1;
}

void add(Tree *tree, int x)
{
	tree->count++;
	if (tree->root == NULL) {
		TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
		newNode->lchild = NULL;
		newNode->data = x;
		newNode->rchild = NULL;
		tree->root = newNode;
		return;
	}
	addNode(tree->root, x);
}

void inorderTree(Tree *tree)
{
	printf("[ ");
	if (tree->root == NULL) {
		printf("]");
		return;
	}
	inorder(tree->root);
	printf("]\n");
}

void preorderTree(Tree *tree)
{
	printf("[ ");
	if (tree->root == NULL) {
		printf("]");
		return;
	}
	preorder(tree->root);
	printf("]\n");
}

void postorderTree(Tree *tree)
{
	printf("[ ");
	if (tree->root == NULL) {
		printf("]");
		return;
	}
	postorder(tree->root);
	printf("]\n");
}

int getTreeDepth(Tree *tree) 
{
	if (tree->root == NULL) {
		return 0;
	}
	return getDepth(tree->root);
}

int getNodeCount(Tree *tree) 
{
	if (tree->root == NULL) {
		return 0;
	}
	return getCount(tree->root);
}


main()
{
	Tree tree;
	int n = 0;

	initTree(&tree);

	add(&tree, 7);
	add(&tree, 3);
	add(&tree, 2);
	add(&tree, 6);
	add(&tree, 9);
	add(&tree, 5);
	add(&tree, 8);

	inorderTree(&tree);

	n = getTreeDepth(&tree);
	printf("depth = %d\n", n);

	n = getNodeCount(&tree);
	printf("count = %d\n", n);

	preorderTree(&tree);

	postorderTree(&tree);

	printf("%d\n", tree.count);
}

/*
typedef struct _treeNode {
	struct _treeNode *lchild;
	int data;
	struct _treeNode *rchild;
} TreeNode;

void addNode(TreeNode *node, int x) 
{
	if (x > node->data) {
		if (node->rchild == NULL) {
			TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
			newNode->lchild = NULL;
			newNode->data = x;
			newNode->rchild = NULL;
			node->rchild = newNode;
		} else {
			addNode(node->rchild, x);
		}
	} else {
		if (node->lchild == NULL) {
			TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
			newNode->lchild = NULL;
			newNode->data = x;
			newNode->rchild = NULL;
			node->lchild = newNode;
		} else {
			addNode(node->lchild, x);
		}
	}
}

void inorder(TreeNode *node) 
{
	if (node->lchild != NULL) inorder(node->lchild);
	printf("%d ", node->data);
	if (node->rchild != NULL) inorder(node->rchild);
}

int getDepth(TreeNode *node)
{
	int n1 = 0;
	int n2 = 0;

	if (node->lchild != NULL) n1 = getDepth(node->lchild);
	if (node->rchild != NULL) n2 = getDepth(node->rchild);
	if (n1 > n2) return n1 + 1;
	else return n2 + 1;
}

int getCount(TreeNode *node)
{
	int n1 = 0;
	int n2 = 0;

	if (node->lchild != NULL) n1 = getCount(node->lchild);
	if (node->rchild != NULL) n2 = getCount(node->rchild);
	return n1 + n2 + 1;
}

void add(TreeNode **tree, int x)
{
	if (*tree == NULL) {
		TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
		newNode->lchild = NULL;
		newNode->data = x;
		newNode->rchild = NULL;
		*tree = newNode;
		return;
	}
	addNode(*tree, x);
}

void inorderTree(TreeNode *tree)
{
	printf("[ ");
	if (tree == NULL) {
		printf("]");
		return;
	}
	inorder(tree);
	printf("]\n");
}

int getTreeDepth(TreeNode *tree) 
{
	if (tree == NULL) {
		return 0;
	}
	return getDepth(tree);
}

int getNodeCount(TreeNode *tree) 
{
	if (tree == NULL) {
		return 0;
	}
	return getCount(tree);
}


main()
{
	TreeNode *tree = NULL;
	int n = 0;

	add(&tree, 7);
	add(&tree, 3);
	add(&tree, 2);
	add(&tree, 6);
	add(&tree, 9);
	add(&tree, 5);
	add(&tree, 8);

	inorderTree(tree);

	n = getTreeDepth(tree);
	printf("depth = %d\n", n);

	n = getNodeCount(tree);
	printf("count = %d\n", n);
}
*/