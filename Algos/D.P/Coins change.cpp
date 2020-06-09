#include<bits/stdc++.h>
using namespace std;

// given total n and infinite supply of fix denominations of coins, find
// the no of ways you can get this total
// using recursion
int ways(int arr[], int n, int m)
{
	if (m == 0)
		return 1;
	if (m < 0)
		return 0;
	if (n <= 0 && m >= 1)
		return 0;

	return ways(arr, n - 1, m) + ways(arr, n, m - arr[n - 1]);
}

// using DP, O(n*m)
int waysDP(int arr[], int n, int m)
{
	int dp[m + 1] = {0};
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = arr[i]; j <= m; j++)
			dp[j] += dp[j - arr[i]];
	}
	return dp[m];
}

int main()
{
	int m = 4;
	int arr[] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "No of ways: " << waysDP(arr, n, m);
	return 0;
}