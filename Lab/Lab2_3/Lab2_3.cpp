#include <iostream>
#include <algorithm>

template<typename T>
T* reverseArray(T *arr, int size) {
	T *newArr = new T[size];
	std::reverse_copy(arr, arr + size, newArr);
	return newArr;
}

template<typename T>
void displayArray(T *arr, int size) {
	std::cout << "Array elements: ";
	for (int i = 0; i < size; i++) {
		std::cout << *(arr + i) << " ";
	}
	std::cout << std::endl;
}

int main() {
	const int SIZE = 5;
	int arr[SIZE] = { 1, 2, 3, 4, 5 };
	displayArray(arr, SIZE);
	int *reversedArr = reverseArray(arr, SIZE);
	displayArray(reversedArr, SIZE);
	delete[] reversedArr;
	return 0;
}
