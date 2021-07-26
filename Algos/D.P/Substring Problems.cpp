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

// Expand around centre, O(n^2)
int expandAroundCentre(string s, int l, int r)
{
	while (l >= 0 && r < s.length() && s[l] == s[r])
		l--, r++;
	return r - l - 1;
}

string longestPalSubStr2(string s, int l)
{
	int start = 0, end = 0;
	for (int i = 0; i < l; i++)
	{
		int l1 = expandAroundCentre(s, i, i);
		int l2 = expandAroundCentre(s, i, i + 1);
		int cur = max(l1, l2);
		if (cur > (end - start + 1))
		{
			start = i - ((cur - 1) / 2);
			end = i + (cur / 2);
		}
	}
	return s.substr(start, start + end + 1);
}

// using dynamic programming, O(n^2)
string longestPalSubStrDP(string s, int l)
{
	bool dp[l][l];
	memset(dp, 0, sizeof(dp));

	// for substrings of length 1
	for (int i = 0; i < l; i++)
		dp[i][i] = true;

	int start = 0, maxLen = 1;

	// for substrings of length > 1
	for (int k = 2; k <= l; k++)
	{
		for (int i = 0; i < l - k + 1; i++)
		{
			int j = i + k - 1;
			if ((k == 2 || dp[i + 1][j - 1]) && s[i] == s[j])
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
	cout << "Longest Palindromic Substring: " << longestPalSubStr2(str, l);

	int m = a.length(), n = b.length();
	cout << "\nLongest Common Substring: " << LCS(m, n);
	return 0;
}