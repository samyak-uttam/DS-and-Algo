#include<bits/stdc++.h>
using namespace std;

// given array denoting heights of towers, and k, you can either dec or inc
// height of each tower by k once. Find the min diff of heights of shortest
// ans longest towers.

int minDiff(int arr[], int n, int k)
{
	if (n <= 1)
		return 0;
	sort(arr, arr + n);
	int ans = arr[n - 1] - arr[0];
	int small = arr[0] + k, big = arr[n - 1] - k;
	if (small > big)
		swap(small, big);
	for (int i = 1; i < n - 1; i++)
	{
		int x = arr[i] - k, y = arr[i] + k;
		if (x >= small || y <= big)
			continue;
		if (big - x <= y - small)
			small = x;
		else
			big = y;
	}
	return min(ans, big - small);
}

int main()
{
	int arr[] = {3, 9, 12, 16, 20};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << "Min diff in heights: " << minDiff(arr, n, k);
	return 0;
}