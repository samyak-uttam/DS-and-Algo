#include<bits/stdc++.h>
using namespace std;

// Find the maximum Number of Non-Overlapping Subarrays With Sum Equals Target
// using DP, O(n^2)
int maxNonOverlapping(vector<int>& a, int target)
{
	int n = a.size();
	int dp[n + 1] = {};
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j >= 0; j--)
		{
			sum += a[j];
			dp[i + 1] = max(dp[i + 1], dp[j] + (sum == target ? 1 : 0));
		}
	}
	return dp[n];
}

// Efficient approach
// using hash map
int maxNonOverlapping2(vector<int>& a, int target)
{
	map<int, int> mp;
	mp[0] = 0;
	int sum = 0, ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		sum += a[i];
		if (mp.find(sum - target) != mp.end())
			ans = max(ans, mp[sum - target] + 1);
		mp[sum] = ans;
	}
	return ans;
}

int main()
{
	vector<int> v = { -2, 6, 6, 3, 5, 4, 1, 2, 8};
	int target = 10;
	cout << maxNonOverlapping2(v, target);

	return 0;
}