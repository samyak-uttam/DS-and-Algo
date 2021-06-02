#include<bits/stdc++.h>
using namespace std;
/* Time complexitiy of Comparison based algorithms:
				     Best,		Average,	Worst
	Selection Sort - O(n^2),    O(n^2),		O(n^2)
	Bubble Sort -    O(n),      O(n^2),		O(n^2)
	Insertion Sort - O(n),      O(n^2),		O(n^2)
	Merge Sort -     O(nlog n), O(nlog n),	O(nlog n)
	Heap Sort -      O(nlog n), O(nlog n),	O(nlog n)
	Quick Sort -     O(nlog n), O(nlog n),	O(n^2)

	Time complexitiy of Non-comparison based algorithms:
	Radix Sort - 	 O(nk),		O(nk),		O(nk)
	Bucket Sort - 	 O(n + k),	O(n + k),	O(n^2)
	Counting Sort -  O(n + k),	O(n + k),	O(n + k)
*/

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


// Selection Sort
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int minInd = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minInd])
				minInd = j;
		}
		swap(&arr[i], &arr[minInd]);
	}
}


// Bubble Sort
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}


// Insertion Sort
void insertionSort(int arr[], int  n) {
	for (int i = 1; i < n; i++) {
		int k = i - 1, key = arr[i];
		while (k >= 0 && arr[k] > key) {
			arr[k + 1] = arr[k];
			k--;
		}
		arr[k + 1] = key;
	}
}


// Merge Sort
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int s1 = m - l + 1, s2 = r - m;
	int f1[s1], f2[s2];

	for (i = 0; i < s1; i++)
		f1[i] = arr[l + i];
	for (i = 0; i < s2; i++)
		f2[i] = arr[m + i + 1];

	i = 0, j = 0, k = l;
	while (i < s1 && j < s2) {
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

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}


// Heap Sort
void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] >= arr[largest])
		largest = l;

	if (r < n && arr[r] >= arr[largest])
		largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(&arr[i], &arr[0]);
		heapify(arr, i, 0);
	}
}


// Quick Sort
int partition(int arr[], int l, int h) {
	int pivot = arr[h];
	int i = l - 1;
	for (int j = l; j < h; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort(int arr[], int l, int h) {
	if (l < h) {
		int pivot = partition(arr, l, h);
		quickSort(arr, l, pivot - 1);
		quickSort(arr, pivot + 1, h);
	}
}


// Counting Sort
void countingSort(int arr[], int n) {
	int min = *min_element(arr, arr + n);
	int max = *max_element(arr, arr + n);
	int l = max - min + 1;

	int count[l + 1] = {};
	for (int i = 0; i < n; i++)
		count[arr[i] - min]++;

	for (int i = 1; i < l; i++)
		count[i] += count[i - 1];

	int temp[n];
	for (int i = n - 1; i >= 0; i--)
		temp[--count[arr[i] - min]] = arr[i];

	for (int i = 0; i < n; i++)
		arr[i] = temp[i];
}


// Radix Sort
void radixSort(int arr[], int n) {
	int min = *min_element(arr, arr + n);
	int max = *max_element(arr, arr + n);
	int temp[n];
	for (int e = 1; (max - min) / e > 0; e *= 10) {
		int count[10] = {};
		for (int i = 0; i < n; i++)
			count[((arr[i] - min) / e) % 10]++;

		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (int i = n - 1; i >= 0; i--)
			temp[--count[((arr[i] - min) / e) % 10]] = arr[i];

		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}
}


// Bucket Sort
void bucketSort(int arr[], int n) {

}


void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	int arr[] = {2, 1, -1, 3, 9, -2, 6, 5, -3, 4, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	// selectionSort(arr, n);
	// bubbleSort(arr, n);
	// insertionSort(arr, n);
	// mergeSort(arr, 0, n);
	// heapSort(arr, n);
	// quickSort(arr, 0, n - 1);

	radixSort(arr, n);
	cout << "Elements after sorting:\n";
	printArr(arr, n);

	return 0;
}
