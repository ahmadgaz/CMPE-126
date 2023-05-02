#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class TreeNode {
public:
	T value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(T value) :
			value(value), left(nullptr), right(nullptr) {
	}
};

template<typename T>
class BinaryTree {
private:
	TreeNode<T> *root;
	void insertHelper(TreeNode<T>*);
	int countHelper(TreeNode<T> *nodePtr);
	int countLeafsHelper(TreeNode<T> *nodePtr);
	vector<TreeNode<T>*> preOrderHelper(TreeNode<T> *nodePtr,
			vector<TreeNode<T>*> sortedPtrs = { });
	vector<TreeNode<T>*> inOrderHelper(TreeNode<T> *nodePtr,
			vector<TreeNode<T>*> sortedPtrs = { });
	vector<TreeNode<T>*> postOrderHelper(TreeNode<T> *nodePtr,
			vector<TreeNode<T>*> sortedPtrs = { });
public:
	BinaryTree() :
			root(nullptr) {
	}
	BinaryTree(T value) {
		root = new TreeNode<T>(value);
	}

	// Methods
	void insert(T);
	void remove(T);
	int count();
	int countLeafs();
	TreeNode<T>* find(T);
	TreeNode<T>* findParent(T);

	// Traversals
	vector<TreeNode<T>*> preOrder();
	vector<TreeNode<T>*> inOrder();
	vector<TreeNode<T>*> postOrder();

	// Destructor
	~BinaryTree();
};

template<typename T>
void BinaryTree<T>::insert(T value) {
	TreeNode<T> *newNode = new TreeNode<T>(value);

	insertHelper(newNode);

	return;
}

template<typename T>
void BinaryTree<T>::insertHelper(TreeNode<T> *newNode) {
	if (!root) {
		root = newNode;
		return;
	}

	TreeNode<T> *nodePtr = root;

	// Traverse the tree
	do {
		// Go left if possible
		if (newNode->value < nodePtr->value) {
			if (!nodePtr->left)
				break;

			nodePtr = nodePtr->left;
		}
		// Go right if possible
		if (newNode->value > nodePtr->value) {
			if (!nodePtr->right)
				break;

			nodePtr = nodePtr->right;
		}
		// Return if duplicate is found
		if (newNode->value == nodePtr->value)
			return;

	} while (nodePtr->left || nodePtr->right);

	// At the end of the loop, we've reached either a leaf node, or a node with one branch.
	if (newNode->value <= nodePtr->value)
		nodePtr->left = newNode;

	if (newNode->value > nodePtr->value)
		nodePtr->right = newNode;

	return;
}

template<typename T>
void BinaryTree<T>::remove(T value) {
	TreeNode<T> *nodePtr = find(value);
	TreeNode<T> *tempNode = nullptr;
	TreeNode<T> *misplacedBranch = nullptr;

	// Value not found
	if (!nodePtr) {
		return;
	}

	// Node does not contain branches
	if (!nodePtr->left && !nodePtr->right) {
		nodePtr = nullptr;
		return;
	}

	// Node contains both branches
	if (nodePtr->left && nodePtr->right) {
		tempNode = nodePtr;
		misplacedBranch = tempNode->right;
		nodePtr = findParent(nodePtr->value);
		if (nodePtr->left->value == tempNode->value)
			nodePtr->left = tempNode->left;
		if (nodePtr->right->value == tempNode->value)
			nodePtr->right = tempNode->left;
		delete tempNode;
		insert(misplacedBranch);
		return;
	}

	// Node contains left branch only
	if (nodePtr->left) {
		tempNode = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNode;
		return;
	}

	// Node contains right branch only
	if (nodePtr->right) {
		tempNode = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNode;
		return;
	}
}

template<typename T>
int BinaryTree<T>::count() {
	return countHelper(root);
}

template<typename T>
int BinaryTree<T>::countHelper(TreeNode<T> *nodePtr) {
	if (!nodePtr)
		return 0;

	return countHelper(nodePtr->left) + countHelper(nodePtr->right) + 1;
}

template<typename T>
int BinaryTree<T>::countLeafs() {
	return countLeafsHelper(root);
}

template<typename T>
int BinaryTree<T>::countLeafsHelper(TreeNode<T> *nodePtr) {
	if (!nodePtr)
		return 0;

	if (!nodePtr->left && !nodePtr->right)
		return countLeafsHelper(nodePtr->left) + countLeafsHelper(nodePtr->right) + 1;
	else
		return countLeafsHelper(nodePtr->left) + countLeafsHelper(nodePtr->right);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::find(T value) {
	TreeNode<T> *nodePtr = root;

	do {
		// Go left if possible
		if (value < nodePtr->value) {
			if (!nodePtr->left)
				return nullptr;

			nodePtr = nodePtr->left;
		}
		// Go right if possible
		if (value > nodePtr->value) {
			if (!nodePtr->right)
				return nullptr;

			nodePtr = nodePtr->right;
		}
		// Return if duplicate is found
		if (value == nodePtr->value)
			break;

	} while (nodePtr->left || nodePtr->right);

	return nodePtr;
}

template<typename T>
TreeNode<T>* BinaryTree<T>::findParent(T value) {
	TreeNode<T> *nodePtr = root;
	TreeNode<T> *prevPtr = nullptr;

	if (!nodePtr) {
		return nullptr;
	}

	do {
		// Go left if possible
		if (value < nodePtr->value) {
			if (!nodePtr->left)
				return nullptr;

			prevPtr = nodePtr;
			nodePtr = nodePtr->left;
		}
		// Go right if possible
		if (value > nodePtr->value) {
			if (!nodePtr->right)
				return nullptr;

			prevPtr = nodePtr;
			nodePtr = nodePtr->right;
		}
		// Return if duplicate is found
		if (value == nodePtr->value)
			break;

	} while (nodePtr->left || nodePtr->right);

	return prevPtr;
}

template<typename T>
vector<TreeNode<T>*> BinaryTree<T>::preOrder() {
	return preOrderHelper(root);
}

template<typename T>
vector<TreeNode<T>*> BinaryTree<T>::preOrderHelper(TreeNode<T> *nodePtr,
		vector<TreeNode<T>*> sortedList) {
	if (!nodePtr)
		return sortedList;

	sortedList.push_back(nodePtr);
	sortedList = preOrderHelper(nodePtr->left, sortedList);
	sortedList = preOrderHelper(nodePtr->right, sortedList);

	return sortedList;
}

template<typename T>
vector<TreeNode<T>*> BinaryTree<T>::inOrder() {
	return inOrderHelper(root);
}

template<typename T>
vector<TreeNode<T>*> BinaryTree<T>::inOrderHelper(TreeNode<T> *nodePtr,
		vector<TreeNode<T>*> sortedList) {
	if (!nodePtr)
		return sortedList;

	sortedList = inOrderHelper(nodePtr->left, sortedList);
	sortedList.push_back(nodePtr);
	sortedList = inOrderHelper(nodePtr->right, sortedList);

	return sortedList;
}

template<typename T>
vector<TreeNode<T>*> BinaryTree<T>::postOrder() {
	return postOrderHelper(root);
}

template<typename T>
vector<TreeNode<T>*> BinaryTree<T>::postOrderHelper(TreeNode<T> *nodePtr,
		vector<TreeNode<T>*> sortedList) {
	if (!nodePtr)
		return sortedList;

	sortedList = postOrderHelper(nodePtr->left, sortedList);
	sortedList = postOrderHelper(nodePtr->right, sortedList);
	sortedList.push_back(nodePtr);

	return sortedList;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	vector<TreeNode<T>*> ptrList = preOrder();
	for (TreeNode<T> *node : ptrList) {
		delete node;
	}
	ptrList.clear();
}

#endif // BINARYTREE_H
