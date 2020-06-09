#include<bits/stdc++.h>
using namespace std;

// using recursion
int eggDrop(int n, int k)
{
	if (k == 1 || k == 0 || n == 1)
		return k;

	int ans = INT_MAX;
	for (int i = 1; i <= k; i++)
		ans = min(ans, 1 + max(eggDrop(n - 1, i - 1), eggDrop(n, k - i)));
	return ans;
}

// using DP, O(n*k^2)
int eggDropDP(int n, int k)
{
	int dp[n + 1][k + 1];

	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = 1;
		dp[i][0] = 0;
	}

	for (int i = 1; i <= k; i++)
		dp[1][i] = i;

	for (int e = 2; e <= n; e++)
	{
		for (int f = 2; f <= k; f++)
		{
			dp[e][f] = INT_MAX;
			for (int i = 1; i <= f; i++)
				dp[e][f] = min(dp[e][f], 1 + max(dp[e - 1][i - 1], dp[e][f - i]));
		}
	}
	return dp[n][k];
}

int main()
{
	// n - no of eggs, k - no of floors
	int n = 2, k = 10;
	cout << "Minimum number of trials in worst case: "
	     << eggDropDP(n, k);
	return 0;
}