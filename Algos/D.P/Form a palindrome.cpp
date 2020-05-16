#include<bits/stdc++.h>
using namespace std;

// minimum number of insertions to form a palindrome
// naive recursive approach
int minInsertions(string s, int l, int h)
{
	if (l > h)
		return INT_MAX;
	if (l == h)
		return 0;
	if (l == h - 1)
		return (s[l] == s[h]) ? 0 : 1;

	return (s[l] == s[h]) ? minInsertions(s, l + 1, h - 1) :
	       (min(minInsertions(s, l + 1, h),
	            minInsertions(s, l, h - 1)) + 1);
}

// using dynamic prrogramming, O(n^2)
int minInsertionsDP(string s, int n)
{
	int dp[n][n], gap, l, h;
	memset(dp, 0, sizeof(dp));

	for (gap = 1; gap < n; gap++)
	{
		for (l = 0, h = gap; h < n; l++, h++)
			dp[l][h] = (s[l] == s[h]) ? dp[l + 1][h - 1] :
			           (min(dp[l][h - 1], dp[l + 1][h]) + 1);
	}
	return dp[0][n - 1];
}

int main()
{
	string str = "abcda";
	int l = str.length();
	cout << "Minimum insertions: " << minInsertionsDP(str, l);
	return 0;
}