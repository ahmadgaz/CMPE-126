#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

int main() {
	BinaryTree<int> tree(31);
	tree.insert(19);
	tree.insert(7);
	tree.insert(59);
	tree.insert(43);

	vector<TreeNode<int>*> preOrder = tree.preOrder();
	for (TreeNode<int> *node : preOrder) {
		cout << node->value << " ";
	}
	cout << endl;

	vector<TreeNode<int>*> inOrder = tree.inOrder();
	for (TreeNode<int> *node : inOrder) {
		cout << node->value << " ";
	}
	cout << endl;

	vector<TreeNode<int>*> postOrder = tree.postOrder();
	for (TreeNode<int> *node : postOrder) {
		cout << node->value << " ";
	}
	cout << endl;

	tree.insert(63);
	tree.insert(42);
	tree.insert(64);
	tree.insert(62);

	inOrder = tree.inOrder();
	for (TreeNode<int> *node : inOrder) {
		cout << node->value << " ";
	}
	cout << endl;

	tree.remove(59);

	inOrder = tree.inOrder();
	for (TreeNode<int> *node : inOrder) {
		cout << node->value << " ";
	}
	cout << endl;

	cout << tree.count() << endl;
	cout << tree.countLeafs() << endl;


	return 0;
}
