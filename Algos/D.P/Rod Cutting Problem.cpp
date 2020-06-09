#include<bits/stdc++.h>
using namespace std;

// cut the rod such that total no of segments of length x, y & z is maximized.
// The segments can only be of length x, y, and z.
// using DP
int maxSegments(int l, int x, int y, int z)
{
	int dp[l + 1];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i <= l; i++)
	{
		if (dp[i] == -1)
			continue;
		if (i + x <= l)
			dp[i + x] = max(dp[i + x], 1 + dp[i]);
		if (i + y <= l)
			dp[i + y] = max(dp[i + y], 1 + dp[i]);
		if (i + z <= l)
			dp[i + z] = max(dp[i + z], 1 + dp[i]);
	}
	return dp[l];
}

int main()
{
	int l = 53;
	int x = 10, y = 11, z = 23;
	cout << "Maximum segments: " << maxSegments(l, x, y, z);
	return 0;
}