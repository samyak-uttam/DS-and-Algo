#include<iostream>
using namespace std;
/* Time complexitiy of - Best, Average, Worst
	Selection Sort - O(n^2), O(n^2), O(n^2)
	Bubble Sort - O(n), O(n^2), O(n^2)
	Insertion Sort - O(n), O(n^2), O(n^2)
	Merge Sort - O(nlog n), O(nlog n), O(nlog n)
	Heap Sort - O(nlog n), O(nlog n), O(nlog n)
	Quick Sort - O(nlog n), O(nlog n), O(n^2)
*/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minInd = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minInd])
			{
				minInd = j;
			}
		}
		swap(&arr[i], &arr[minInd]);
	}
}


void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}


void insertionSort(int arr[], int  n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1, key = arr[i];
		while (k >= 0 && arr[k] > key)
		{
			arr[k + 1] = arr[k];
			k--;
		}
		arr[k + 1] = key;
	}
}


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int s1 = m - l + 1, s2 = r - m;
	int f1[s1], f2[s2];

	for (i = 0; i < s1; i++)
		f1[i] = arr[l + i];
	for (i = 0; i < s2; i++)
		f2[i] = arr[m + i + 1];

	i = 0, j = 0, k = l;
	while (i < s1 && j < s2)
	{
		if (f1[i] <= f2[j])
			arr[k++] = f1[i++];
		else
			arr[k++] = f2[j++];
	}

	while (i < s1)
		arr[k++] = f1[i++];

	while (j < s2)
		arr[k++] = f2[j++];
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}


void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] >= arr[largest])
		largest = l;

	if (r < n && arr[r] >= arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap(&arr[i], &arr[0]);
		heapify(arr, i, 0);
	}
}


int partition(int arr[], int l, int h)
{
	int pivot = arr[h];
	int i = l - 1;
	for (int j = l; j < h; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort(int arr[], int l, int h)
{
	if (l < h)
	{
		int pivot = partition(arr, l, h);

		quickSort(arr, l, pivot - 1);
		quickSort(arr, pivot + 1, h);
	}
}


int main()
{
	while (1)
	{
		cout << "Enter the size of the array: ";
		int n;
		cin >> n;
		cout << "Enter the elements of the array: ";
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << "Enter 1 for sorting with SelectionSort, 2 with BubbleSort, 3 with InsertionSort,";
		cout << "4 with Merge Sort, 5 with Heap Sort, 6 with Quick sort: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: selectionSort(arr, n);
			break;
		case 2: bubbleSort(arr, n);
			break;
		case 3: insertionSort(arr, n);
			break;
		case 4: mergeSort(arr, 0, n);
			break;
		case 5: heapSort(arr, n);
			break;
		case 6: quickSort(arr, 0, n - 1);
			break;
		default: cout << "Wrong choice.";
			exit(0);
		}
		cout << "Elements after sorting:\n";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
