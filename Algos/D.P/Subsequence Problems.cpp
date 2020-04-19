#include<bits/stdc++.h>
using namespace std;

void LPS(string s)
{
	int n = s.length(), i, l, j;
	int dp[n][n];
	for (i = 0; i < n; i++)
		dp[i][i] = 1;

	for (l = 2; l <= n; l++)
	{
		for (i = 0; i < n - l + 1; i++)
		{
			j = i + l - 1;
			if (l == 2 && s[i] == s[j])
				dp[i][j] = 2;
			else if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	cout << "\nLength of Longest Palindromic Subsequence is: ";
	cout << dp[0][n - 1];
}

void LIS(int arr[], int n)
{
	int dp[n] = {1}, i, j;
	for (i = 1; i < n; i++)
	{
		dp[i] = 1;
		for (j = 0; j < n; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = *max_element(dp, dp + n);
	cout << "\nLength of Longest Increasing Subsequence is: " << ans;
}

void LCS(string a, string b)
{
	int m = a.length(), n = b.length();
	int dp[m + 1][n + 1], i , j;
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	i = m, j = n;
	string ans;
	// BackTracing to find the subsequence
	while (dp[i][j] > 0)
	{
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else
		{
			ans += a[i - 1];
			i--, j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << "Length of Longest Common Subsequence is: " << dp[m][n];
	cout << "\nAnd the subsequence is: " << ans;
}

int main()
{
	// Longest Common Subsequence
	string a = "AGGTAB", b = "GXTXAYB";
	LCS(a, b);

	// Longest Increasing Subsequence
	int arr[] = {3, 4, -1, 0, 6, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	LIS(arr, n);

	// Longest Palindromic Subsequence
	string s = "agbdba";
	LPS(s);

	return 0;
}