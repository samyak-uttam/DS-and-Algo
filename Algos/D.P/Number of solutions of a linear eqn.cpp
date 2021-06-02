#include<bits/stdc++.h>
using namespace std;

// brute force approach, using recursion
int countSol(vector<int> &coeff, int start, int rhs) {
	if (rhs == 0)
		return 1;

	int res = 0;
	for (int i = start; i < coeff.size(); i++) {
		if (coeff[i] <= rhs)
			res += countSol(coeff, i, rhs - coeff[i]);
	}
	return res;
}

// using dynamic programming, Time - O(n*rhs), Space - O(rhs)
int countSolDP(vector<int> &coeff, int rhs) {
	int n = coeff.size();
	vector<int> dp(rhs + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coeff[i]; j <= rhs; j++)
			dp[j] += dp[j - coeff[i]];
	}
	return dp[rhs];
}

int main() {
	vector<int> coeff = {2, 2, 3};
	int rhs = 4;
	cout << "Number of solutions: " << countSolDP(coeff, rhs);
	return 0;
}