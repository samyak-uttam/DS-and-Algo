#include<bits/stdc++.h>
using namespace std;

// given an array nums of +ve integers, and two +ve integers left and right (left <= right).
//Return the number of (contiguous, non-empty) subarrays such that the value of the maximum
// array element in that subarray is at least left and at most right.
int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
	int l = 0, r = -1, res = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] > R)
			l = i + 1, r = i;
		else if (A[i] < L)
			res += r - l + 1;
		else
			res += i - l + 1, r = i;
	}
	return res;
}

int main() {
	vector<int> nums = {2, 1, 4, 3};
	int L = 2, R = 3;
	cout << numSubarrayBoundedMax(nums, L, R);
	return 0;
}