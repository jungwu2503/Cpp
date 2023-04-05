#include <stdio.h>
#include <malloc.h>


class Tree {
	class TreeNode {
		TreeNode *lchild;
		int data;
		TreeNode *rchild;
	public:
		TreeNode(int x) {
			lchild = rchild = NULL;
			data = x;
		}
		void add(int x);
		void inorder();
		void preorder();
		void postorder();
		int getDepth();
		int getCount();
	};
	TreeNode *root;
	int count;
public:
	Tree();
	void add(int x);
	void inorder();
	void preorder();
	void postorder();
	int getDepth();
	inline int getCount() { return count; }
};