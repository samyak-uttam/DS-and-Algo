#include<bits/stdc++.h>
using namespace std;

// Mininum operations to reach a no from 0, when 2 operations are available
// 1. Double the number, 2. Add one to the no
// Using recursion
int operations(int n)
{
	if (n == 0)
		return 0;
	else if (n % 2 == 0)
		return operations(n / 2) + 1;
	else
		return operations(n - 1) + 1;
}

int operationsDP(int n)
{
	int dp[n + 1];
	dp[1] = 1;
	int prev = 1;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			dp[i] = dp[i / 2] + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	return dp[n];
}

int main()
{
	int n = 7896;
	cout << "Mininum operations: " << operationsDP(n);
	return 0;
}