#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template<class T>
class LinkedList {
private:
	struct ListNode {
		T value;
		struct ListNode *next;
	};

	ListNode *head;   // List head pointer

public:
	// Constructor
	LinkedList() {
		head = nullptr;
	}

	// Destructor
	~LinkedList();

	// Linked list operations
	void appendNode(T);
	void findKthNode(int);
	void deleteKthNode(int);
	void deleteNode(T);
	void deleteAll(T);
	void deleteSmallest();
	void displayList() const;
};

template<class T>
void LinkedList<T>::appendNode(T newValue) {
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list

	// Allocate a new node and store newValue there.
	newNode = new ListNode;
	newNode->value = newValue;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

template<class T>
void LinkedList<T>::displayList() const {
	ListNode *nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr) {
		// Display the value in this node.
		cout << nodePtr->value << endl;
		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

template<class T>
void LinkedList<T>::findKthNode(int index) {
	ListNode *nodePtr;       // To traverse the list
	int position = index;

	// If the list is empty, do nothing.
	if (!head) {
		cout << "List Empty\n";
		return;
	}

	if (index < 0) {
		cout << "Out of bounds\n";
		return;
	}

	nodePtr = head;

	while (--index > 0 && nodePtr) {
		nodePtr = nodePtr->next;
	}

	if (nodePtr) {
		cout << "Value at " << position << ": " << nodePtr->value << endl;
		return;
	} else {
		cout << "Out of bounds\n";
		return;
	}
}

template<class T>
void LinkedList<T>::deleteKthNode(int index) {
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node
	ListNode *targetNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head) {
		cout << "List Empty\n";
		return;
	}

	if (index < 0) {
		cout << "Out of bounds\n";
		return;
	}

	targetNode = head;

	while (--index > 0 && targetNode) {
		targetNode = targetNode->next;
	}

	if (!targetNode) {
		cout << "Out of bounds\n";
		return;
	}

	// Determine if the first node is the one.
	if (head == targetNode) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	} else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes not equal to smallestValueNode
		while (nodePtr != nullptr && nodePtr != targetNode) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<class T>
void LinkedList<T>::deleteNode(T searchValue) {
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == searchValue) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	} else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != searchValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<class T>
void LinkedList<T>::deleteAll(T searchValue) {
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	if (head->value == searchValue) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}

	nodePtr = head;

	while (nodePtr != nullptr) {
		while (nodePtr != nullptr && nodePtr->value != searchValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
			nodePtr = previousNode->next;
		}
	}
}

template<class T>
void LinkedList<T>::deleteSmallest() {
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node
	ListNode *smallestValueNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	nodePtr = head;
	smallestValueNode = nodePtr;

	while (nodePtr != nullptr) {
		if (nodePtr->value < smallestValueNode->value) {
			smallestValueNode = nodePtr;
		}
		nodePtr = nodePtr->next;
	}

	// Determine if the first node is the one.
	if (head == smallestValueNode) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	} else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes not equal to smallestValueNode
		while (nodePtr != nullptr && nodePtr != smallestValueNode) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<class T>
LinkedList<T>::~LinkedList() {
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

#endif
