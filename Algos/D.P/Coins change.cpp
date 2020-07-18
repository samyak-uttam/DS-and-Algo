#include<bits/stdc++.h>
using namespace std;

// you have infinite supply of given valued money, Find the minimum number of
// money needed to make the change for n.

// using recursion, exponential Time complexity
int minCoins(int coins[], int v, int n)
{
	if (n == 0)
		return 0;
	int res = INT_MAX;
	for (int i = 0; i < v; i++)
	{
		if (coins[i] <= n)
		{
			int cur = minCoins(coins, v, n - coins[i]) + 1;
			if (cur != INT_MAX)
				res = min(res, cur);
		}
	}
	return res;
}

int minCoinsDP(int coins[], int v, int n)
{
	int dp[n + 1];
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = n + 1;
		for (int j = 0; j < v; j++)
		{
			if (coins[j] <= i)
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}
	return dp[n] > n ? -1 : dp[n];
}

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
	int coins[] = {9, 6, 5, 1};
	int v = sizeof(coins) / sizeof(coins[0]);
	int n = 11;
	cout << "Min coins: " << minCoinsDP(coins, v, n);

	int m = 4;
	int arr[] = {1, 2, 3};
	n = sizeof(arr) / sizeof(arr[0]);
	cout << "\nNo of ways: " << waysDP(arr, n, m);
	return 0;
}