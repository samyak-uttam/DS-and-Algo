#include<bits/stdc++.h>
using namespace std;
#define mod 	1000000007

/*
We have an array nums, and an array of requests where requests[i] = [starti, endi].
The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi].

Return the maximum total sum of all requests among all permutations of nums.
*/

int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req)
{
	int n = nums.size();
	vector<int> freq(n, 0);
	// Important piece of code
	for (auto i : req)
	{
		freq[i[0]]++;
		if (i[1] + 1 < n)
			freq[i[1] + 1]--;
	}
	for (int i = 1; i < n; i++)
		freq[i] += freq[i - 1];

	sort(nums.begin(), nums.end(), greater<int>());
	sort(freq.begin(), freq.end(), greater<int>());

	long ans = 0;
	for (int k = 0; k < n; k++)
		ans = (ans + nums[k] * freq[k]) % mod;
	return ans;
}

int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 10};
	vector<vector<int>> requests = {{0, 2}, {1, 3}, {1, 1}};
	cout << maxSumRangeQuery(nums, requests);
	return 0;
}