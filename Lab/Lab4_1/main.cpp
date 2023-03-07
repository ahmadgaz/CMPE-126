#include <iostream>
#include "arrayListType.h"
#include "extArrayListType.h"
using namespace std;

int main() {
	extArrayListType<int>* arr = new extArrayListType<int>(5);
	arr->insertEnd(10);
	arr->insertEnd(15);
	arr->insertEnd(5);
	arr->insertEnd(10);
	arr->insertEnd(25);

	cout << "The list created for you is:" << endl;
	arr->print();
	cout << "Min: " << arr->min() << endl;
	cout << "Max: " << arr->max() << endl;
	cout << "Enter the position of the item to be deleted:" << endl;

	int choice;
	cin >> choice;
	arr->removeAt(choice);

	cout << "\nAfter removing the element at " << choice << ", the list is:"
			<< endl;
	arr->print();
	cout << "Min: " << arr->min() << endl;
	cout << "Max: " << arr->max() << endl;

	cout << "\nRemoving all instances of 10:" << endl;
	arr->removeAll(10);
	arr->print();
	cout << "Min: " << arr->min() << endl;
	cout << "Max: " << arr->max() << endl;

	return 0;
}
