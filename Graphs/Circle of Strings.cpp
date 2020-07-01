#include<bits/stdc++.h>
using namespace std;
#define m 26

// Given an array of strings, check if the strings can be chained together
// to form a circle. A string X can be chained with Y if the last char of
// X is same as first of Y

// For this we will check if
// 1. the graph has eulerian circuit(in and out degree of every vertex is same)
// 2. graph should be strongly connected

void dfs(vector<int> graph[], int u, vector<bool> &vis)
{
	vis[u] = true;
	for (auto i = graph[u].begin(); i != graph[u].end(); i++)
		if (!vis[*i])
			dfs(graph, *i, vis);
}

bool isConnected(vector<int> graph[], vector<bool> &mark, int s)
{
	vector<bool> vis(m, false);

	dfs(graph, s, vis);

	for (int i = 0; i < m; i++)
	{
		if (mark[i] && !vis[i])
			return false;
	}
	return true;
}

bool isCircle(string arr[], int n)
{
	vector<int> graph[m];

	vector<bool> mark(m, false);

	vector<int> in(m, 0), out(m, 0);

	for (int i = 0; i < n; i++)
	{
		int first = arr[i].front() - 'a';
		int last = arr[i].back() - 'a';

		mark[first] = mark[last] = true;
		in[first]++, out[last]++;

		graph[last].push_back(first);
	}

	for (int i = 0; i < m; i++)
		if (in[i] != out[i])
			return false;

	return isConnected(graph, mark, arr[0].front() - 'a');
}

int main()
{
	string arr[] = {"ab", "bc", "cd", "de", "ed", "da"};
	int n = sizeof(arr) / sizeof(arr[0]);
	if (isCircle(arr, n))
		cout << "Ordering is possible\n";
	else
		cout << "Ordering is not possible\n";
	return 0;
}