#include <iostream>
using namespace std;
#include "tree.h"

void main()
{
	Tree tree;
	int n = 0;

	tree.add(7);
	tree.add(3);
	tree.add(2);
	tree.add(6);
	tree.add(9);
	tree.add(5);
	tree.add(8);

	tree.inorder();

	n = tree.getDepth();
	cout << "depth = " << n << endl;

	n = tree.getCount();
	cout << "count = " << n << endl;

	tree.preorder();
	tree.postorder();
}
