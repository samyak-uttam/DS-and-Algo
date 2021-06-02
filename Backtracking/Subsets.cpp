#include<bits/stdc++.h>
using namespace std;

// Given a set of distinct integers, find all subsets (the power set).

// Brute Force approach, O(n2^n)
void printPowerSet(vector<int> &nums) {
	int n = nums.size();
	unsigned int size = 1 << n;
	for (int counter = 0; counter < size; counter++) {
		for (int i = 0; i < n; i++)
			if (counter & (1 << i))
				cout << nums[i] << " ";
		cout << "\n";
	}
}

// using backtracking, O(2^n)
void util(vector<int> &vec, vector<vector<int>> &ans,
          vector<int> &sub, int ind)
{
	ans.push_back(sub);
	for (int i = ind; i < vec.size(); i++)
	{
		sub.push_back(vec[i]);
		util(vec, ans, sub, i + 1);
		sub.pop_back();
	}
}

vector<vector<int>> subsets(vector<int> &vec)
{
	vector<int> sub;
	vector<vector<int>> ans;

	util(vec, ans, sub, 0);
	return ans;
}

int main()
{
	vector<int> vec = {1, 2, 3};
	vector<vector<int>> ans = subsets(vec);

	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}

	printPowerSet(vec);
	return 0;
}