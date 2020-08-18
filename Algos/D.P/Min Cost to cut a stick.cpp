#include<bits/stdc++.h>
using namespace std;

// Given a wooden stick of length n units. The stick is labelled from 0 to n.
// Given an array cuts which denotes the positions you should perform a cut at.
// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts.
// Find the min total cost of the cuts, if you can change the order of the cuts

// 1 <= cuts.length <= min(n - 1, 100)
// Top down approach (memoisation), O(n^3)
int dp[102][102];

int util(vector<int>& cuts, int i, int j)
{
	if (j - i <= 1)
		return 0;
	if (!dp[i][j])
	{
		dp[i][j] = INT_MAX;
		for (int k = i + 1; k < j; k++)
			dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + util(cuts, i, k) + util(cuts, k, j));
	}
	return dp[i][j];
}

int minCost(int n, vector<int>& cuts)
{
	cuts.push_back(0);
	cuts.push_back(n);
	sort(begin(cuts), end(cuts));

	return util(cuts, 0, cuts.size() - 1);
}

// using Bottom up approach
int minCost2(int n, vector<int> cuts)
{
	cuts.push_back(0);
	cuts.push_back(n);
	sort(begin(cuts), end(cuts));

	int l = cuts.size();
	int dp[l][l];
	memset(dp, 0, sizeof(dp));

	for (int i = l - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < l; j++)
		{
			for (int k = i + 1; k < j; k++)
				dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j],
				               cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
		}
	}
	return dp[0][l - 1];
}

int main()
{
	int n = 7;
	vector<int> cuts = {1, 3, 4, 5};
	cout << minCost2(n, cuts) << "\n";

	return 0;
}