#include <iostream>

void enterArrayData(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "Enter element " << i + 1 << ": ";
		std::cin >> *(arr + i);
	}
}

void outputArrayData(int *arr, int size) {
	std::cout << "Array elements: ";
	for (int i = 0; i < size; i++) {
		std::cout << *(arr + i) << " ";
	}
	std::cout << std::endl;
}

void sumArray(int *arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(arr + i);
	}
	std::cout << "Sum of array elements: " << sum << std::endl;
}

int main() {
	const int SIZE = 5;
	int arr[SIZE];
	enterArrayData(arr, SIZE);
	outputArrayData(arr, SIZE);
	sumArray(arr, SIZE);
	return 0;
}
