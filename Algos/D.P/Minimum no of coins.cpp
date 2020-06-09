#include<bits/stdc++.h>
using namespace std;

// you have infinite supply of {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}
// valued money, Find the minimum number of money needed to make the change for Rs N.

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
		dp[i] = INT_MAX;
		for (int j = 0; j < v; j++)
		{
			if (coins[j] <= i)
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}
	return dp[n];
}

int main()
{
	int coins[] = {9, 6, 5, 1};
	int v = sizeof(coins) / sizeof(coins[0]);
	int n = 11;
	cout << minCoinsDP(coins, v, n);
	return 0;
}