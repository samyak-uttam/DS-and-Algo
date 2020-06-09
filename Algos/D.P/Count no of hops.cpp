#include<bits/stdc++.h>
using namespace std;

// A frog jumps 1, 2 or 3 steps to go to top. In how many ways can it
// reach the top.
// using recursion
int ways(int n)
{
	if (n <= 2)
		return max(1, n);
	return ways(n - 1) + ways(n - 2) + ways(n - 3);
}

// using DP, O(n)
int waysDP(int n)
{
	int dp[n + 1];
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	return dp[n];
}

int main()
{
	int n = 5;
	cout << waysDP(n);
	return 0;
}