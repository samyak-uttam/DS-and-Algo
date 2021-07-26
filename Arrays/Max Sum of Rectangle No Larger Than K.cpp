#include<bits/stdc++.h>
using namespace std;

// Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the
// matrix such that its sum is no larger than k.
int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
	int res = INT_MIN, m = mat.size(), n = mat[0].size();
	for (int l = 0; l < n; l++) {
		vector<int> sums(m);
		for (int c = l; c < n; c++) {
			for (int r = 0; r < m; r++)
				sums[r] += mat[r][c];
			set<int> s = {0};
			int curSum = 0;
			for (int& sum : sums) {
				curSum += sum;
				auto it = s.lower_bound(curSum - k);
				if (it != s.end())
					res = max(res, curSum - *it);
				s.insert(curSum);
			}
		}
	}
	return res;
}

int main() {
	vector<vector<int>> mat = {{1, 0, 1}, {0, -2, 3}};
	int k = 2;
	cout << maxSumSubmatrix(mat, k);
}