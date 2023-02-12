#ifndef arrayListType_h
#define arrayListType_h
#include <iostream>
#include <iomanip>
using namespace std;
/*
 ---------------------------------------
 arrayListType<Type>
 ---------------------------------------
 +/- list: Type *
 +/- length: int
 +/- maxSize: int
 ---------------------------------------
 + operator=(const arrayListType<Type>&):
 const arrayListType<Type>
 + isEmpty() const: bool
 + isFull() const: bool
 + listSize() const: int
 + maxListSize() const: int
 + void print();
 + isItemAtEqual(int, const Type&) const: bool
 + insertAt(int, const Type&): void
 + insertEnd(const Type&): void
 + retrieveAt(int, Type&) const: void
 + replaceAt(int, const Type&): void
 + clearList(): void
 + insert(const Type&): void
 + arrayListType(int)
 + arrayListType(const arrayListType<Type>&)
 + ~arrayListType()
 ---------------------------------------
 */
template<class Type>
class arrayListType {
protected:
	Type *list;      //holds list of elements
	int length;      //stores the length of the list
	int maxSize;    //stores the maximum size of the list

public:
	const arrayListType<Type>& operator=(const arrayListType<Type>&);
	bool isEmpty() const {
		return (length == 0);
	}
	bool isFull() const {
		return (length == maxSize);
	}
	int listSize() const {
		return length;
	}
	int maxListSize() const {
		return maxSize;
	}
	void print();
	bool isItemAtEqual(int location, const Type &item) const {
		return (list[location] == item);
	}
	void insertAt(int location, const Type &insertItem);
	void insertEnd(const Type &insertItem);

	void retrieveAt(int location, Type &retItem) const;
	void replaceAt(int location, const Type &repItem);
	void clearList() {
		length = 0;
	}
	void removeAt(int location);
	int sequentialSearch(const Type &searchItem);

	arrayListType(int = 100);
	arrayListType(const arrayListType<Type> &otherList);
	~arrayListType() {
		delete[] list;
	}
};
template<class Type>
int arrayListType<Type>::sequentialSearch(const Type &searchItem) {
	for (int i = 0; i < length; i++) {
		if (searchItem == list[i]) {
			return i;
		}
	}

	return -1;
}
//print(): prints array in simple format
//Arguments: none | Returns: void
template<class Type>
void arrayListType<Type>::print() {

	for (int i = 0; i < length; i++) {
		cout << list[i] << endl;
	}
	cout << endl;
}
//insertAt(): inserts an item at a given location
//Arguments: location (int), insertItem (const Type&) | Returns: void
template<class Type>
void arrayListType<Type>::insertAt(int location, const Type &insertItem) {
	if (location < 0 || location >= maxSize)
		cerr << "The position of the item to be inserted " << "is out of range"
				<< endl;
	else if (length >= maxSize)  //list is full
		cerr << "Cannot insert in a full list" << endl;
	else {
		for (int i = length; i > location; i--)
			list[i] = list[i - 1];   //move the elements down
		list[location] = insertItem;  //insert item at position
		length++;
	}
} //end insertAt
//insertEnd(): inserts given item at end of list
//Arguments: insertItem(const Type&) | Returns: void
template<class Type>
void arrayListType<Type>::insertEnd(const Type &insertItem) {

	if (length >= maxSize)  //the list is full
		cerr << "Cannot insert in a full list" << endl;
	else {
		list[length] = insertItem; //insert the item at the end
		length++;
	}
} //end insertEnd
//removeAt(): removes list element by location
//Arguments: location (int) | Returns: void
template<class Type>
void arrayListType<Type>::removeAt(int location) {
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed " << "is out of range"
				<< endl;
	else {
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
	}
} //end removeAt
//retrieveAt(): retrieves a list item by location
//Arguments: location (int), retItem (Type&) | Returns: void
//retItem is sent by reference and is set to the list item
//retrieved by location
template<class Type>
void arrayListType<Type>::retrieveAt(int location, Type &retItem) const {
	if (location < 0 || location >= length)
		cerr << "The location of the item to be retrieved is "
				<< "out of range." << endl;
	else
		retItem = list[location];
} //end retrieveAt
//replaceAt(): replaces a list item by location
//Arguments: location (int), repItem (const Type&) | Returns: void
template<class Type>
void arrayListType<Type>::replaceAt(int location, const Type &repItem) {
	if (location < 0 || location >= length)
		cerr << "The location of the item to be replaced is " << "out of range."
				<< endl;
	else
		list[location] = repItem;

} //end replaceAt
//remove(): removes an item from the list
//Arguments: removeItem (const Type&) | Returns: void
//This function only removes the first instance of the item
//(in the event duplicates were somehow inserted into the list
//arrayListType(): constructor
//Arguments: array size (int)
template<class Type>
arrayListType<Type>::arrayListType(int size) {
	if (size < 0) {
		cerr << "The array size must be positive. Creating "
				<< "an array of size 100. " << endl;
		maxSize = 100;
	} else
		maxSize = size;
	length = 0;
	list = new Type[maxSize];  //dynamic array
} // end constructor
//arrayListType(): copy constructor
//Arguments: otherList (const arrayListType<Type>&)
template<class Type>
arrayListType<Type>::arrayListType(const arrayListType<Type> &otherList) {
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new Type[maxSize]; //create the array
	for (int j = 0; j < length; j++)  //copy otherList
		list[j] = otherList.list[j];
} //end copy constructor

//operator=(): overloads assignment operator
//Arguments: otherList (const arrayListType<Type>&)
//Returns: *this
template<class Type>
const arrayListType<Type>& arrayListType<Type>::operator=(
		const arrayListType<Type> &otherList) {
	if (this != &otherList)   //avoid self-assignment
			{
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new Type[maxSize];  //create the array
		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}
	return *this;
}
#endif /* arrayListType_h */
