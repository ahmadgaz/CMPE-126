#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template<typename T>
class ListNode {
public:
	T value;
	ListNode<T> *next;

	ListNode(T value) :
			value(value), next(nullptr) {
	}
};

template<typename T>
class LinkedList {
private:
	ListNode<T> *head;
	ListNode<T> *tail;
	ListNode<T> *cur;
public:
	LinkedList() :
			head(nullptr), tail(nullptr), cur(nullptr) {
	}
	void push(T);
	void pop();
	void insert(T, T);
	void remove(T);
	void print();

	T next();
	T goTo(T);

	ListNode<T>* findNode(T);

	~LinkedList();
};

template<typename T>
void LinkedList<T>::push(T item) {
	ListNode<T> *newNode = new ListNode<T>(item);

	if (!head) {
		head = newNode;
		cur = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
}
template<typename T>
void LinkedList<T>::pop() {
	if (!head) {
		return;
	}

	if (head == tail) {
		head = nullptr;
		cur = nullptr;
		delete tail;
		tail = nullptr;
		return;
	}

	ListNode<T> *ptr = head;
	while (ptr) {
		if (ptr->next == tail) {
			if (cur == tail) {
				cur = ptr;
			}
			ptr->next = nullptr;
			delete tail;
			tail = ptr;
			return;
		}
		ptr = ptr->next;
	}
}
template<typename T>
void LinkedList<T>::insert(T item, T ref) {
	ListNode<T> *ptr = findNode(ref);
	if (!ptr) {
		return;
	}
	ListNode<T> *newNode = new ListNode<T>(item);
	newNode->next = ptr->next;
	ptr->next = newNode;

}
template<typename T>
void LinkedList<T>::remove(T ref) {
	ListNode<T> *refPtr = findNode(ref);
	if (!refPtr) {
		return;
	}

	if (refPtr == head) {
		if (tail == refPtr) {
			tail = head->next;
		}
		if (cur == refPtr) {
			cur = head->next;
		}
		head = head->next;
		delete refPtr;
		return;
	}

	ListNode<T> *nodePtr = head;
	while (nodePtr) {
		if (nodePtr->next == refPtr) {
			if (tail == refPtr) {
				tail = nodePtr;
			}
			if (cur == refPtr) {
				cur = nodePtr;
			}
			nodePtr->next = refPtr->next;
			delete refPtr;
			return;
		}
		nodePtr = nodePtr->next;
	}
}
template<typename T>
void LinkedList<T>::print() {
	ListNode<T> *ptr = head;
	while (ptr) {
		cout << ptr->value << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
template<typename T>
T LinkedList<T>::next() {
	if (!head) {
		return {};
	}

	if (cur->next) {
		cur = cur->next;
		return cur->value;
	} else {
		cur = head;
		return cur->value;
	}
}
template<typename T>
T LinkedList<T>::goTo(T ref) {
	ListNode<T> *ptr = findNode(ref);
	if (!ptr) {
		return {};
	}
	cur = ptr;
	return cur->value;
}
template<typename T>
ListNode<T>* LinkedList<T>::findNode(T ref) {
	ListNode<T> *ptr = head;
	while (ptr) {
		if (ptr->value == ref) {
			return ptr;
		}
		ptr = ptr->next;
	}

	return nullptr;
}
template<typename T>
LinkedList<T>::~LinkedList() {
	while(head){
		pop();
	}
}

#endif
