#include<bits/stdc++.h>
using namespace std;

void subsetSum(int s, int arr[], int n) {
	bool dp[n + 1][s + 1];
	int i, j;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= s; j++) {
			if (j == 0)
				dp[i][j] = true;
			else if (i == 0)
				dp[i][j] = false;
			else if (arr[i - 1] <= j)
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][s];
	// if the sum is possible then backtrack to find the subset
	if (dp[n][s]) {
		vector<int> vec;
		i = n, j = s;
		while (j > 0 && i > 0) {
			if (dp[i][j] == dp[i - 1][j])
				i--;
			else {
				vec.push_back(arr[i - 1]);
				j -= arr[i - 1], i--;
			}
		}
		cout << "\nSubset is given by: ";
		for (i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
	}
}

// using only, O(sum) space
bool subsetSum(vector<int>& nums, int sum) {
	int n = nums.size();
	vector<bool> dp(sum + 1);
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		for (int s = sum; s >= nums[i]; s--)
			dp[s] = dp[s] || dp[s - nums[i]];
	}
	return dp[sum];
}

// Subset of non-adjacent elements having maximum sum
void maxSubsetSum(int arr[], int n) {
	if (n == 1) {
		cout << "\nMaximum Subset sum is: " << arr[0];
		return;
	}
	int dp[n];
	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(max(dp[i - 1], arr[i]), dp[i - 2] + arr[i]);
	}
	cout << "\nMaximum Subset sum is: " << dp[n - 1];
}


// smallest positive number that can't be represented as sum of some elements of the array
int smallestPositive(vector<int> arr, int n) {
	sort(arr.begin(), arr.end());

	int ans = 1;
	for (int i = 0; i < n && arr[i] <= ans; i++)
		ans += arr[i];
	return ans;
}

int main() {
	int s = 11;
	int arr[] = {2, 3, 7, 8, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	// Whether there is a subset of the array with given sum;
	subsetSum(s, arr, n);

	// Subset of non-adjacent elements having maximum sum
	int a[] = { -2, 1, 3, -4, 5};
	n = sizeof(a) / sizeof(a[0]);
	maxSubsetSum(a, n);


	// smallest positive number that can't be represented as sum of some elements of the array
	vector<int> a2 = {1, 1, 3, 5, 8, 21};
	n = a2.size();

	cout << "\nSmallest positive number not present in array is: " << smallestPositive(a2, n);

	return 0;
}