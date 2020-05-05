#include<bits/stdc++.h>
using namespace std;

// Naive appraoch would be to sort the array and get the k-th element

// efficient approach is to use min/max heap
void heapify(int arr[], int n, int i)
{
	int s = i, l = (2 * i + 1), r = (2 * i + 2);
	if (l < n && arr[l] < arr[s])
		s = l;
	if (r < n && arr[r] < arr[s])
		s = r;
	if (s != i)
	{
		swap(arr[s], arr[i]);
		heapify(arr, n, s);
	}
}

int kthsmallest(int arr[], int n, int k)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = 1; i < k; i++)
	{
		swap(arr[0], arr[n - i]);
		heapify(arr, n - i, 0);
	}
	return arr[0];
}

int main()
{
	int arr[] = {7, 10, 4, 20, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	cout << "K'th smallest element is: " << kthsmallest(arr, n, k);
	return 0;
}
