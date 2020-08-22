#include<bits/stdc++.h>
using namespace std;

// how far (or close) the array is from being sorted
// two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

// brute force approach
int invCount(int arr[], int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				ans++;
	return ans;
}

// efficient way
// uses enhanced merge sort
int merge(int arr[], int temp[], int l, int m, int r)
{
	int i, j, k;
	int count = 0;

	i = l, j = m, k = l;
	while ((i <= m - 1) && (j <= r))
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			count += (m - i);
		}
	}
	while (i <= m - 1)
		temp[k++] = arr[i++];

	while (j <= r)
		temp[k++] = arr[j++];

	for (i = l; i <= r; i++)
		arr[i] = temp[i];

	return count;
}

int mergeSort(int arr[], int temp[], int l, int r)
{
	int m, count = 0;
	if (r > l)
	{
		m = (l + r) / 2;

		count += mergeSort(arr, temp, l, m);
		count += mergeSort(arr, temp, m + 1, r);

		count += merge(arr, temp, l, m + 1, r);
	}
	return count;
}

int mergeSort(int arr[], int n)
{
	int temp[n];
	return mergeSort(arr, temp, 0, n - 1);
}

int main()
{
	int arr[] = {1, 20, 6, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Number of inversions: " << mergeSort(arr, n);
	return 0;
}