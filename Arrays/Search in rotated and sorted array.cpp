#include<bits/stdc++.h>
using namespace std;

// search in sorted and rotated array
// using divide and conquer approach, O(log n)
int search(int arr[], int l, int h, int k)
{
	if (l > h)
		return -1;
	int m = (l + h) / 2;
	if (arr[m] == k)
		return m;
	else if (arr[l] <= arr[m])
	{
		if (k >= arr[l] && k < arr[m])
			return search(arr, l, m - 1, k);
		return search(arr, m + 1, h, k);
	}
	else
	{
		if (k <= arr[h] && k > arr[m])
			return search(arr, m + 1, h, k);
		return search(arr, l, m - 1, k);
	}
}


int main()
{
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 10;
	cout << "Index of " << k << " is: " << search(arr, 0, n - 1, k);
	return 0;
}