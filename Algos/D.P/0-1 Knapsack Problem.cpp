#include<bits/stdc++.h>
using namespace std;

// Given weights and values of n items, put these items in a knapsack
// of capacity W to get the maximum total value in the knapsack.

// Top down approach
int memo[1001][1001];
int knapsack(int W, int i, vector<int>& wt, vector<int>& val) {
	if (i == wt.size()) return 0;
	if (memo[i][W] == -1) {
		if (W < wt[i])
			memo[i][W] = knapsack(W, i + 1, wt, val);
		else
			memo[i][W] = max(val[i] + knapsack(W - wt[i], i + 1, wt, val), knapsack(W, i + 1, wt, val));
	}
	return memo[i][W];
}

// Bottom up approach
int knapsack2(int W, vector<int>& wt, vector<int>& val, int n) {
	int K[n + 1][W + 1];
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main() {
	vector<int> val = {60, 100, 120};
	vector<int> wt = {10, 20, 30};
	int W = 50;
	memset(memo, -1, sizeof(memo));
	cout << knapsack(W, 0, wt, val);
	return 0;
}