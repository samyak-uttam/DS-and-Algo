#include<bits/stdc++.h>
using namespace std;

// given two arrays of length n. The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) +
// (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).
// Rearrange the elements of nums2 such that the resulting XOR sum is minimized.
// Return the XOR sum after the rearrangement.

// Brute force, using BackTracking
int res = INT_MAX;
void backTrack(vector<int>& a, vector<int>& b, int i, int cur) {
	if (i == b.size())
		res = min(res, cur);
	else {
		for (int j = i; j < b.size(); j++) {
			swap(b[i], b[j]);
			backTrack(a, b, i + 1, cur + (a[i] ^ b[i]));
			swap(b[i], b[j]);
		}
	}
}

// using Bit Manipulation and DP, O(n*2^n)
vector<int> dp;
int dfs(vector<int>& a, vector<int>& b, int i, int mask) {
	if (i >= b.size())
		return 0;
	if (dp[mask] == INT_MAX) {
		for (int j = 0; j < b.size(); j++) {
			if (!(mask & (1 << j)))
				dp[mask] = min(dp[mask], (a[i] ^ b[j]) + dfs(a, b, i + 1, mask + (1 << j)));
		}
	}
	return dp[mask];
}

int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
	dp = vector<int>(16384, INT_MAX);
	return dfs(nums1, nums2, 0, 0);
}


int main() {
	vector<int> nums1 = {1, 0, 3}, nums2 = {5, 3, 4};
	cout << minimumXORSum(nums1, nums2);
	return 0;
}