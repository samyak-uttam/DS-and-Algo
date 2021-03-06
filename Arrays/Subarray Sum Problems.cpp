#include<bits/stdc++.h>
using namespace std;

// find the starting and ending index of subarray with given sum
// for +ve no's only
void subArraySum(int arr[], int n, int sum)
{
	int curSum = arr[0], beg = 0;
	for (int i = 1; i <= n; i++)
	{
		while (curSum > sum && beg < i - 1)
			curSum -= arr[beg++];
		if (curSum == sum)
		{
			cout << beg + 1 << " " << i;
			return;
		}
		if (i < n)
			curSum += arr[i];
	}
	cout << -1;
}

// for -ve no's also
void subArraySum2(int arr[], int n, int sum)
{
	unordered_map<int, int> mp;
	int curSum = 0;
	for (int i = 0; i < n; i++)
	{
		curSum += arr[i];
		if (curSum == sum)
		{
			cout << 1 << " " << i + 1;
			return;
		}
		if (mp.find(curSum - sum) != mp.end())
		{
			cout << mp[curSum - sum] + 2 << " " << i + 1;
			return;
		}
		mp[curSum] = i;
	}
	cout << -1;
}

// Count pairs of elements whose sum is equal to k
int countPairs(int arr[], int n, int k)
{
	int ans = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		if (mp[k - arr[i]])
			ans += mp[k - arr[i]];
		mp[arr[i]]++;
	}
	return ans;
}

// Count no of subarrays having sum divisible by k
int subCount(vector<int> vec, int k)
{
	unordered_map<int, int> mp;
	int n = vec.size(), sum = 0, ans = 0;
	mp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		sum = (sum + vec[i]) % k;
		if (sum < 0)
			sum += k;
		ans += mp[sum];
		mp[sum]++;
	}
	return ans;
}

int main()
{

	int arr[] = {1, 2, 3, 7, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 12;

	subArraySum(arr, n, sum);

	cout << "\nNo of pairs: " << countPairs(arr, n, sum);

	vector<int> vec = {4, 5, 0, -2, -3, 1};
	int k = 5;
	cout << "\nNo of Subarrays: " << subCount(vec, k);

	return 0;
}