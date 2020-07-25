#include<bits/stdc++.h>
using namespace std;

int maxProduct(int arr[], int n)
{
	int ans = arr[0], curMin = arr[0], curMax = arr[0];
	for (int i = 1; i < n; i++)
	{
		int temp = curMax;
		curMax = max(arr[i], max(curMax * arr[i], curMin * arr[i]));
		curMin = min(arr[i], min(temp * arr[i], curMin * arr[i]));
		ans = max(ans, curMax);
	}
	return ans;
}

int main()
{
	int arr[] = {1, 0, -1, 2, 3, -5, -2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxProduct(arr, n);
	return 0;
}