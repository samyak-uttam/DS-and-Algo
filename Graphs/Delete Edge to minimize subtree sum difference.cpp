#include<bits/stdc++.h>
using namespace std;

// Given an undirected tree whose each node is has a weight. We need to delete an
// edge in such a way that difference between sum of weight in one subtree to sum of weight in other subtree is minimized.

void dfs(int v, int parent, int totSum, vector<int> edge[], vector<int>& data, int &ans)
{
	int sum = data[v];
	for (auto i = edge[v].begin(); i != edge[v].end(); i++)
	{
		if (*i != parent)
		{
			dfs(*i, v, totSum, edge, data, ans);
			sum += data[*i];
		}
	}

	data[v] = sum;
	if (v != 0 && abs(totSum - 2 * sum) < ans)
		ans = abs(totSum - 2 * sum);
}

int getMinSubtreeSumdiff(vector<int> data, vector<vector<int>> edges)
{
	int totSum = accumulate(data.begin(), data.end(), 0);

	vector<int> edge[data.size()];

	for (int i = 0; i < edges.size(); i++)
	{
		edge[edges[i][0]].push_back(edges[i][1]);
		edge[edges[i][1]].push_back(edges[i][0]);
	}

	int ans = INT_MAX;

	dfs(0, -1, totSum, edge, data, ans);
	return ans;
}

int main()
{
	vector<int> data = {4, 2, 1, 6, 3, 5, 2};
	vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}};

	cout << getMinSubtreeSumdiff(data, edges);
	return 0;
}