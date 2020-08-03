#include<bits/stdc++.h>
using namespace std;

// brute force approach
vector<int> maxSlidingWindow(int arr[], int n, int k)
{
	vector<int> ans;
	for (int i = 0; i <= n - k; i++)
	{
		int cur = arr[i];
		for (int j = 1; j < k; j++)
			cur = max(cur, arr[i + j]);
		ans.push_back(cur);
	}
	return ans;
}

// efficient approach (using sliding window)
vector<int> maxSlidingWindow2(int arr[], int n, int k)
{
	deque<int> dq(k);
	vector<int> ans;
	for (int i = 0; i < k; i++)
	{
		while (!dq.empty() && arr[i] >= arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}

	for (int i = k; i < n; i++)
	{
		ans.push_back(arr[dq.front()]);
		while (!dq.empty() && dq.front() <= i - k)
			dq.pop_front();
		while (!dq.empty() && arr[i] >= arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	ans.push_back(arr[dq.front()]);
	return ans;
}

int main()
{
	int arr[] = {9, 10, 9, -7, -4, -8, 2, -6}, k = 5;
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> ans = maxSlidingWindow2(arr, n, k);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}