#include<bits/stdc++.h>
using namespace std;

// Given an integer n, return the number of structurally unique BST's which has
// exactly n nodes of unique values from 1 to n
long numTrees(int n)
{
	long dp[n + 1];
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 0;
		for (int j = 1; j <= i; j++)
		{
			long l = dp[j - 1], r = dp[i - j];
			if (!l || !r)
				dp[i] += l + r;
			else
				dp[i] += l * r;
		}
	}
	return dp[n];
}

int main()
{
	int n = 5;
	cout << "Number of unique BST's = " << numTrees(n) << "\n";
	return 0;
}