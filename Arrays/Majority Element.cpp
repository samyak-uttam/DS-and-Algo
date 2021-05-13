#include<bits/stdc++.h>
using namespace std;

// Given an array, return the majority element.
// The majority element is one that appears more than ⌊n / 2⌋ times.

// using hashmap
// Time: O(n), Space: O(n)
int majorityElement(vector<int>& nums)
{
	int n = nums.size();
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		mp[nums[i]]++;
		if (mp[nums[i]] > n / 2)
			return nums[i];
	}
	return nums[0];
}

// using Boyer-Moore Voting Algorithm
// Time: O(n), Space: O(1)
int majorityElement2(vector<int>& nums)
{
	int candidate, count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (count == 0)
			candidate = nums[i];
		count += candidate == nums[i] ? 1 : -1;
	}
	return candidate;
}

int main()
{
	vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
	cout << "Majority Element is: " << majorityElement2(nums);
	return 0;
}