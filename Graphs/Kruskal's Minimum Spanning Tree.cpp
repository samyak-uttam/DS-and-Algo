#include<bits/stdc++.h>
using namespace std;

#define V 5
#define iPair pair<int, int>
int parent[V];

/*
	Kruskal's Algorithm
	1. Sort all the edges in ascending order of their weight.
	2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed
	   so far. If cycle is not formed, include this edge. Else, discard it.
	3. Repeat step 2 until there are (V-1) edges in the spanning tree.
*/

// using adjacency matrix, very inefficient way
// using union find method
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void KruskalMST(int cost[][V])
{
	int mincost = 0;

	for (int i = 0; i < V; i++)
		parent[i] = i;

	int edge_count = 0;
	while (edge_count < V - 1)
	{
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (find(i) != find(j) && cost[i][j] < min)
				{
					min = cost[i][j];
					a = i, b = j;
				}
			}
		}
		union1(a, b);
		cout << "Edge " << edge_count++ << ": (" << a << ", " << b << ") cost: " << min << "\n";
		mincost += min;
	}
	cout << "Minimum cost = " << mincost;
}

// using adjacency list, efficient way
// using min heap
int find(vector<int> &parent, int u)
{
	while (u != parent[u])
		u = parent[u];
	return u;
}

int KruskalMST(vector<vector<int>>& points)
{
	int n = points.size(), mst_wt = 0, vert = 0;

	vector<int> parent(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;

	vector<array<int, 3>> edges;
	for (int i = 0; i < n; i++)
		edges.push_back({points[i][2], points[i][0], points[i][1]});

	make_heap(edges.begin(), edges.end(), greater<array<int, 3>>());

	while (vert < n - 1 && !edges.empty())
	{
		pop_heap(edges.begin(), edges.end(), greater<array<int, 3>>());
		array<int, 3> cur = edges.back();
		int dist = cur[0], u = cur[1], v = cur[2];
		edges.pop_back();

		int set_u = find(parent, u), set_v = find(parent, v);
		if (set_u != set_v)
		{
			mst_wt += dist;
			cout << u << " - " << v << "\n";
			parent[set_u] = set_v;
		}
	}
	return mst_wt;
}

int main()
{
	int cost[][V] = {
		{ INT_MAX, 2, INT_MAX, 6, INT_MAX },
		{ 2, INT_MAX, 3, 8, 5 },
		{ INT_MAX, 3, INT_MAX, INT_MAX, 7 },
		{ 6, 8, INT_MAX, INT_MAX, 9 },
		{ INT_MAX, 5, 7, 9, INT_MAX },
	};

	KruskalMST(cost);


	vector<vector<int>> points = {{0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 8, 2},
		{2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
		{6, 8, 6}, {7, 8, 7}
	};

	cout << "\n\nEdges of MST are:\n";
	int mst_wt = KruskalMST(points);

	cout << "Weight of MST is: " << mst_wt;

	return 0;
}