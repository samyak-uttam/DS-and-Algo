#include<bits/stdc++.h>
using namespace std;

void subsetSum(int s, int arr[], int n)
{
	bool dp[n + 1][s + 1];
	int i, j;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= s; j++)
		{
			if (j == 0)
				dp[i][j] = true;
			else if (i == 0)
				dp[i][j] = false;
			else if (arr[i - 1] <= j)
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][s];
	// if the sum is possible then backtrack to find the subset
	if (dp[n][s])
	{
		vector<int> vec;
		i = n, j = s;
		while (j > 0 && i > 0)
		{
			if (dp[i][j] == dp[i - 1][j])
				i--;
			else
			{
				vec.push_back(arr[i - 1]);
				j -= arr[i - 1], i--;
			}
		}
		cout << "\nSubset is given by: ";
		for (i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
	}
}

int main()
{
	int s = 11;
	int arr[] = {2, 3, 7, 8, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	subsetSum(s, arr, n);
}