#include<bits/stdc++.h>
using namespace std;

// Given an array, every element appears twice except for one. Find that single one.
// Time - O(n), Space - O(1)
int singleNumber(vector<int> &nums) {
	int res = 0;
	for (int num : nums)
		res ^= num;
	return res;
}

// Given an array, in which exactly two elements appear only once and all the other
// elements appear exactly twice. Find the two elements that appear only once.
// Time - O(n), Space - O(1)
vector<int> singleNumber2(vector<int> &nums) {
	long aXorb = 0;
	for (int num : nums)
		aXorb ^= num;

	// the last bit on right side where a and b differs
	int lastBit = aXorb ^ ((aXorb - 1) & aXorb), a = 0, b = 0;
	vector<int> res;
	for (int num : nums)
		(num & lastBit)	? a ^= num : b ^= num;
	return {a, b};
}

// Given an array, where every element appears three times except for one,
// which appears exactly once. Find the single element and return it.
int singleNumber3(vector<int> &nums) {
	int res = 0;
	for (int bit = 0; bit < 32; bit++) {
		int cnt = 0;
		for (int num : nums)
			if (((1 << bit) & num) == 1 << bit)
				cnt++;
		if (cnt % 3)
			res += 1 << bit;
	}
	return res;
}

int main() {
	vector<int> nums = {4, 1, 2, 1, 2};
	cout << "Single Number in nums: " << singleNumber(nums);

	vector<int> nums2 = {1, 2, 1, 3, 2, 5};
	vector<int> res = singleNumber2(nums2);
	cout << "\nSingle Numbers in nums2: " << res[0] << " " << res[1];

	vector<int> nums3 = {0, 1, 0, 1, 0, 1, 99};
	cout << "\nSingle Numbers in nums3: " << singleNumber3(nums3);

	return 0;
}