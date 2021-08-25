#include<bits/stdc++.h>
using namespace std;

// Split the given array into K sub-arrays such that maximum sum of all sub arrays is minimum
bool check(int cur, int& K, vector<int>& A) {
	int count = 1, sum = 0;
	for (int& i : A) {
		if (i > cur) return false;
		sum += i;
		if (sum > cur) {
			sum = i;
			count++;
		}
	}
	return count <= K;
}

int getMinSum(vector<int>& A, int K) {
	int l = 0, r = 0, res = -1;
	for (int& i : A) {
		l = max(l, i);
		r += i;
	}
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m, K, A)) {
			res = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return res;
}

int main() {
	vector<int> A = {1, 2, 3, 4};
	int K = 3;
	cout << getMinSum(A, K);
	return 0;
}