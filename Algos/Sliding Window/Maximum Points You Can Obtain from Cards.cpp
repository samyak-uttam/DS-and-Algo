#include<bits/stdc++.h>
using namespace std;

// There are cards arranged in a row each having points.
// In one step, you can take one card from the beginning or from the end of the row
// You have to take exactly k cards. return the maximum score you can obtain.

// using sliding window, O(k)
int maxScore(vector<int>& points, int k) {
	int l = k - 1, r = points.size() - 1;
	int sum = accumulate(points.begin(), points.begin() + k, 0), res = sum;
	while (l >= 0) {
		sum = sum - points[l--] + points[r--];
		res = max(res, sum);
	}
	return res;
}

int main() {
	vector<int> points = {1, 2, 3, 4, 5, 6, 1};
	int k = 3;

	cout << "Max score: " << maxScore(points, k);
	return 0;
}