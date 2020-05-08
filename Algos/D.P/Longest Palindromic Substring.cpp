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

int main()
{
	string str = "aaaabbaa";
	int l = str.length();
	cout << longestPalSubStrDP(str, l);
	return 0;
}