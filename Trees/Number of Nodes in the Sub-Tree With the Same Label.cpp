#include<bits/stdc++.h>
using namespace std;

// Given a tree having n nodes numbered 0 to n-1 and exactly n-1 edges. The root of the tree
// is the node 0 and each node of the tree has a label which is a lower-case character given in the string labels
// (i.e. The node with the number i has the label labels[i]). Return an array of size n where
// ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

void dfs(int i, string labels, vector<vector<int>> adj, int cnt[], vector<int> &ans)
{
	if (ans[i] == 0)
	{
		ans[i] = 1;
		for (auto j : adj[i])
		{
			int cnt1[26] = {};
			dfs(j, labels, adj, cnt1, ans);
			for (int k = 0; k < 26; k++)
				cnt[k] += cnt1[k];
		}
		ans[i] = ++cnt[labels[i] - 'a'];
	}
}

vector<int> counSubTrees(int n, vector<vector<int>> edges, string labels)
{
	vector<vector<int>> adj(n);
	for (auto e : edges)
	{
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	vector<int> ans(n);
	int cnt[26] = {};
	dfs(0, labels, adj, cnt, ans);
	return ans;
}

int main()
{
	int n = 5;
	vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {0, 4}};
	string labels = "aabab";

	vector<int> ans = counSubTrees(n, edges, labels);
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}