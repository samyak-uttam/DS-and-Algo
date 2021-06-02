#include<bits/stdc++.h>
using namespace std;

// Given an array which represents the value of coins, you play against
// an opponent in alternating way. In each turn, a player selects either
// first or last coin, and it goes until no coins left. Find the max amount
// of money you can win if you go first.

int optimalStrategy(int arr[], int n)
{
	pair<int, int> dp[n][n];

	// table filled in diagonal fashion
	for (int i = 0; i < n; i++)
		dp[i][i] = {arr[i], 0};

	for (int l = 2; l <= n; l++)
	{
		for (int i = 0; i <= n - l; i++)
		{
			int j = i + l - 1;
			dp[i][j].first = max(arr[i] + dp[i + 1][j].second, arr[j] + dp[i][j - 1].second);
			if (l % 2 != 0)
				dp[i][j].second = min(dp[i + 1][j].first, dp[i][j - 1].first);
			else
				dp[i][j].second = min(arr[i] + dp[i + 1][j].second, arr[j] + dp[i][j - 1].second);
		}
	}
	return dp[0][n - 1].first;
}

int main()
{
	int arr[] = {8, 15, 3, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << optimalStrategy(arr, n);
	return 0;
}