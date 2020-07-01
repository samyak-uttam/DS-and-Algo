#include<bits/stdc++.h>
using namespace std;

// Naive approach
int maxLen(int arr[], int n)
{
	int max_len = 0;
	for (int i = 0; i < n; i++)
	{
		int cur_sum = 0;
		for (int j = i; j < n; j++)
		{
			cur_sum += arr[j];
			if (cur_sum == 0)
				max_len = max(max_len, j - i + 1);
		}
	}
	return max_len;
}

// Efficient approach
int maxLenEff(int arr[], int n)
{
	unordered_map<int, int> presum;

	int sum = 0;
	int max_len = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];

		if (arr[i] == 0 && max_len == 0)
			max_len = 1;
		if (sum == 0)
			max_len = i + 1;

		if (presum.find(sum) != presum.end())
			max_len = max(max_len, i - presum[sum]);
		else
			presum[sum] = i;
	}
	return max_len;
}

int main()
{
	int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxLenEff(arr, n);
	return 0;
}