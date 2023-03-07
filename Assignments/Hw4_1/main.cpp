#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
	LinkedList<int> list;

	list.appendNode(2);
	list.appendNode(4);
	list.appendNode(1);
	list.appendNode(4);
	list.appendNode(1);
	list.appendNode(5);
	list.appendNode(4);

	cout << "List:\n";
	list.displayList();
	cout << "\n\n";

	list.deleteSmallest();

	cout << "Smallest deleted:\n";
	list.displayList();
	cout << "\n\n";

	list.deleteAll(4);

	cout << "Deleted all 4's:\n";
	list.displayList();
	cout << "\n\n";

	list.findKthNode(2);

	list.deleteKthNode(2);

	cout << "\nDeleted 2nd element:\n";
	list.displayList();

	return 0;
}
