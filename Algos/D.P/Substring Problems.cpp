#include<bits/stdc++.h>
using namespace std;

// Longest palindromic Substring of a string
// Using Brute force, O(n^3)
string longestPalSubStr(string s, int l)
{
	int beg = 0, end = 0;
	for (int i = 0; i < l; i++)
	{
		for (int j = i + 1; j < l; j++)
		{
			int k = i, l = j, check = 0;
			while (k <= l)
			{
				if (s[k++] != s[l--])
					check = 1;
			}
			if (check == 0)
			{
				if (end - beg < j - i)
					beg = i, end = j;
			}
		}
	}
	return s.substr(beg, end - beg + 1);
}

// using dynamic programming, O(n^2)
string longestPalSubStrDP(string s, int l)
{
	bool dp[l][l];
	memset(dp, 0, sizeof(dp));

	// for substrings of length 1
	for (int i = 0; i < l; i++)
		dp[i][i] = true;

	int start = 0, maxLen = 1;;

	// for substrings of length 2
	for (int i = 0; i < l - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = true;
			start = i;
			maxLen = 2;
		}
	}

	// for substrings of length > 2
	for (int k = 3; k <= l; k++)
	{
		for (int i = 0; i < l - k + 1; i++)
		{
			int j = i + k - 1;
			if (dp[i + 1][j - 1] && s[i] == s[j])
			{
				dp[i][j] = true;
				if (k > maxLen)
				{
					start = i;
					maxLen = k;
				}
			}
		}
	}
	return s.substr(start, maxLen);
}


// Longest common substring
// using recursion
string a = "acdghr", b = "abcdgh";

int lcs(int i, int j, int x)
{
	if (i == 0 || j == 0)
		return 0;
	if (a[i - 1] == b[j - 1])
		x = max(x, lcs(i - 1, j - 1, x + 1));
	x = max(x, max(lcs(i, j - 1, 0), lcs(i - 1, j, 0)));
	return x;
}

// using Dynamic Programming
int LCS(int m, int n)
{
	int dp[m + 1][n + 1];
	int ans = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	return ans;
}

int main()
{
	string str = "aaaabbaa";
	int l = str.length();
	cout << "Longest Palindromic Substring: " << longestPalSubStrDP(str, l);

	int m = a.length(), n = b.length();
	cout << "\nLongest Common Substring: " << LCS(m, n);
	return 0;
}