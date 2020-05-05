#include<iostream>
using namespace std;

// Capacity and current size of the heap
int capacity = 11, size = 7;
int arr[11] = {3, 2, 1, 15, 5, 4, 45};

int parent(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
	return (2 * i + 1);
}

int right(int i)
{
	return (2 * i + 2);
}

int getMin()
{
	return arr[0];
}

void insertkey(int k)
{
	if (size == capacity)
	{
		cout << "\nOverflow.";
		return;
	}
	arr[size++] = k;
	int i = size - 1;
	while (i >= 0 && arr[parent(i)] > arr[i])
	{
		swap(arr[parent(i)], arr[i]);
		i = parent(i);
	}
}

void heapify(int i)
{
	int smallest = i;
	int l = left(i);
	int r = right(i);

	if (l < size && arr[l] < arr[smallest])
		smallest = l;
	if (r < size && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(arr[i], arr[smallest]);
		heapify(smallest);
	}
}

void deleteKey()
{
	swap(arr[--size], arr[0]);
	heapify(0);
}

void createMinHeap()
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(i);
}

void printArr()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	createMinHeap();
	printArr();
	deleteKey();
	printArr();
	return 0;
}