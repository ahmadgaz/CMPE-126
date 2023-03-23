#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
	T *stack;
	int maxSize;
	int size;
public:
	Stack(int maxSize) :
			stack(new T[maxSize]), maxSize(maxSize), size(0) {
	}
	bool isEmpty();
	bool isFull();
	T top();
	void push(T);
	void pop();
	void print();

	~Stack() {
		delete[] stack;
	}
};

template<typename T>
bool Stack<T>::isEmpty() {
	return size <= 0;
}
template<typename T>
bool Stack<T>::isFull() {
	return size >= maxSize;
}
template<typename T>
T Stack<T>::top() {
	return stack[size - 1];
}
template<typename T>
void Stack<T>::push(T item) {
	if (isFull()) {
		cout << "Stack is full!" << endl;
		return;
	}
	stack[size++] = item;
}
template<typename T>
void Stack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack is empty!" << endl;
		return;
	}
	stack[--size] = {};
}
template<typename T>
void Stack<T>::print() {
	for (int i = 0; i < size; i++) {
		cout << stack[i] << " ";
	}
	cout << endl;
}
#endif
