#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	Stack<int> newStack(5);

	// Push
	newStack.push(1);
	newStack.push(2);
	newStack.push(3);
	newStack.print();
	newStack.push(4);
	newStack.push(5);
	newStack.push(6);
	newStack.print();

	// Pop
	newStack.pop();
	newStack.pop();
	newStack.pop();
	newStack.print();
	newStack.pop();
	newStack.pop();
	newStack.pop();
	newStack.print();

	// Top
	newStack.push(1);
	newStack.push(2);
	newStack.push(3);
	newStack.print();
	cout << newStack.top() << endl;
	newStack.pop();
	newStack.print();
	cout << newStack.top() << endl;

	return 0;
}
