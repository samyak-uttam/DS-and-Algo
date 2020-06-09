#include<bits/stdc++.h>
using namespace std;

// Given an array, each element represents the max steps that can be made
// forward from that element, find min no of jumps to reach the end of the array
// recursive approach
int minJumps(int arr[], int n)
{
	if (n == 1)
		return 0;
	int ans = INT_MAX;
	for (int i = n - 2; i >= 0; i--)
	{
		if (i + arr[i] >= n - 1)
		{
			int cur = minJumps(arr, i + 1);
			if (cur != INT_MAX)
				ans = min(ans, cur + 1);
		}
	}
	return ans;
}

// using DP
int minJumpsDP(int arr[], int n)
{
	if (arr[0] == 0)
		return -1;
	int dp[n];
	dp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		dp[i] = INT_MAX;
		for (int j = 0; j < i; j++)
		{
			if (i <= j + arr[j] && dp[j] != INT_MAX)
			{
				dp[i] = min(dp[i], dp[j] + 1);
				break;
			}
		}
	}
	if (dp[n - 1] == INT_MAX)
		return -1;
	return dp[n - 1];
}

// O(n) solution
int minJumps3(int arr[], int n)
{
	if (n <= 1)
		return 0;
	if (arr[0] == 0)
		return -1;
	int step = arr[0], jump = 1, maxReach = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (i == n - 1)
			return jump;
		maxReach = max(maxReach, i + arr[i]);
		step--;
		if (step == 0)
		{
			jump++;
			if (i >= maxReach)
				return -1;
			step = maxReach - i;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minJumps3(arr, n);
	return 0;
}