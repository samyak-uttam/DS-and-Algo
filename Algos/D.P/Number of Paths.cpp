#include<bits/stdc++.h>
using namespace std;

// count all the possible paths from top left to bottom right of a
// nxm matrix but moving is possible only in right or down directions.
int n = 3, m = 3;

// using recursion
int paths(int a, int b)
{
	if (a == n || b == m)
		return 1;
	return paths(a + 1, b) + paths(a, b + 1);
	// + paths(a+1,b+1), if diag movement is allowed
}

// using D.P
int paths()
{
	int dp[n][m];

	for (int i = 0; i < n; i++)
		dp[i][0] = 1;
	for (int i = 0; i < m; i++)
		dp[0][i] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		// + dp(i-1,j-1), if diag movement is allowed
	}
	return dp[n - 1][m - 1];
}

int main()
{
	cout << paths() << "\n";
	return 0;
}