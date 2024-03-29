#include<bits/stdc++.h>
using namespace std;

// A max-heap is a complete binary tree in which the value in each
// internal node is greater than or equal to the values in the children of that node.

// Time Complexities
// Heap Creation using heapify - O(n)
// Insertion - O(log n)
// Deletion - O(log n)

// Capacity and current size of the heap
int capacity = 11, size = 7;
int arr[11] = {3, 2, 1, 15, 5, 4, 45};

int parent(int i) {
	return (i - 1) / 2;
}

int left(int i) {
	return (2 * i + 1);
}

int right(int i) {
	return (2 * i + 2);
}

int getMax() {
	return arr[0];
}

void insertkey(int k) {
	if (size == capacity) {
		cout << "\nOverflow.";
		return;
	}
	arr[size++] = k;
	int i = size - 1;
	while (i >= 0 && arr[parent(i)] < arr[i]) {
		swap(arr[parent(i)], arr[i]);
		i = parent(i);
	}
}

void heapify(int i)
{
	int largest = i;
	int l = left(i);
	int r = right(i);

	if (l < size && arr[l] > arr[largest])
		largest = l;
	if (r < size && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(largest);
	}
}

int extractMax() {
	if (size <= 0)
		return -1;

	int x = arr[0];
	swap(arr[0], arr[size - 1]);
	size--;
	heapify(0);
	return x;
}

// removes element from position x in max heap
void deleteKey(int i) {
	if (i < 0 || i >= size)
		return;
	arr[i] = INT_MAX;
	while (i != 0 && arr[parent(i)] < arr[i])
	{
		swap(arr[parent(i)], arr[i]);
		i = parent(i);
	}
	extractMax();
}

void deleteMax() {
	swap(arr[--size], arr[0]);
	heapify(0);
}

void createMaxHeap() {
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(i);
}

void printArr() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	createMaxHeap();
	printArr();
	deleteKey(1);
	printArr();
	deleteMax();
	cout << extractMax();
	return 0;
}