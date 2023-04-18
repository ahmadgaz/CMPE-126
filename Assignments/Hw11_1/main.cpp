#include <iostream>
using namespace std;

void swap(int&, int&);
void MergeSort(int*, int, int);
void QuickSort(int*, int, int);
void BubbleSort(int*, int &size);
void InsertionSort(int*, int &size);
void SelectionSort(int*, int &size);

int main() {
	int size = 11;

	int mergeSort[size] = { 12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45 };
	MergeSort(mergeSort, 0, size - 1);
	cout << endl << "MergeSort: ";
	for (int i = 0; i < size; i++) {
		cout << mergeSort[i] << " ";
	}

	int quickSort[size] = { 12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45 };
	QuickSort(quickSort, 0, size - 1);
	cout << endl << "QuickSort: ";
	for (int i = 0; i < size; i++) {
		cout << quickSort[i] << " ";
	}

	int bubbleSort[size] = { 12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45 };
	BubbleSort(bubbleSort, size);
	cout << endl << "BubbleSort: ";
	for (int i = 0; i < size; i++) {
		cout << bubbleSort[i] << " ";
	}

	int insertionSort[size] = { 12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45 };
	InsertionSort(insertionSort, size);
	cout << endl << "InsertionSort: ";
	for (int i = 0; i < size; i++) {
		cout << insertionSort[i] << " ";
	}

	int selectionSort[size] = { 12, 5, 99, 34, 23, 19, 33, 2, 90, 15, 45 };
	SelectionSort(selectionSort, size);
	cout << endl << "SelectionSort: ";
	for (int i = 0; i < size; i++) {
		cout << selectionSort[i] << " ";
	}
	return 0;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void MergeSort(int *arr, int first, int last) {
	if (first >= last)
		return;

	int mid = first + (last - first) / 2;

	MergeSort(arr, first, mid);
	MergeSort(arr, mid + 1, last);

	int temp[last - first + 1];
	int idx = 0;
	int ptr1 = first;
	int ptr2 = mid + 1;

	while ((ptr1 <= mid) && (ptr2 <= last)) {
		if (arr[ptr2] < arr[ptr1])
			temp[idx++] = arr[ptr2++];
		else
			temp[idx++] = arr[ptr1++];
	}

	while (ptr1 <= mid)
		temp[idx++] = arr[ptr1++];
	while (ptr2 <= last)
		temp[idx++] = arr[ptr2++];

	for (int i = first; i <= last; i++)
		arr[i] = temp[i - first];

	return;
}
void QuickSort(int *arr, int first, int last) {
	if (first >= last) {
		return;
	}

	// Find median of start, middle, and end values
	int mid = first + (last - first) / 2;
	if ((arr[first] <= arr[mid] && arr[mid] <= arr[last])
			|| (arr[last] <= arr[mid] && arr[mid] <= arr[first])) {
		swap(arr[mid], arr[first]);
	} else if ((arr[mid] <= arr[first] && arr[first] <= arr[last])
			|| (arr[last] <= arr[first] && arr[first] <= arr[mid])) {
		// do nothing
	} else {
		swap(arr[last], arr[first]);
	}

	int pivot = arr[first];
	int i = first + 1;
	int j = last;

	while (i <= j) {
		while (i <= last && arr[i] < pivot) {
			i++;
		}
		while (j >= first && arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	swap(arr[first], arr[j]);

	QuickSort(arr, first, j - 1);
	QuickSort(arr, j + 1, last);

	return;
}
void BubbleSort(int *arr, int &size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	return;
}
void InsertionSort(int *arr, int &size) {
	int key, j;
	for (int i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	return;
}
void SelectionSort(int *arr, int &size) {
	int i, j, min_idx;
	for (i = 0; i < size - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
	return;
}
