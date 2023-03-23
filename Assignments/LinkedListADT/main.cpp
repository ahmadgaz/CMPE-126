#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList<int> newList;

	// Push
	newList.push(1);
	newList.push(2);
	newList.push(3);
	newList.push(4);
	newList.push(5);
	newList.push(6);
	newList.print();
	cout << endl;

	// Pop
	newList.pop();
	newList.print();
	cout << endl;

	// Insert
	newList.insert(7, 3);
	newList.print();
	cout << endl;

	// Remove
	newList.remove(3);
	newList.print();
	cout << endl;

	// Next
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << endl;

	// Goto and next
	cout << newList.goTo(7) << endl;
	cout << newList.next() << endl;
	cout << newList.next() << endl;
	cout << endl;

	return 0;
}
