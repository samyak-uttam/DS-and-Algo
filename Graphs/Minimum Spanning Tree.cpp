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
class Graph
{
private:
	int v, e;
	vector<pair<int, iPair>> edges;

public:
	Graph(int v, int e)
	{
		this->v = v;
		this->e = e;
	}

	void addEdge(int u, int v, int w)
	{
		edges.push_back({w, {u, v}});
	}

	int KruskalMST();
};

class DisjointSets
{
private:
	int *parent, *rank;
	int n;

public:
	DisjointSets(int n)
	{
		this->n = n;
		parent = new int[n+1];
		rank = new int[n+1];

		for(int i = 0; i <= n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find(int u)
	{
		while(u != parent[u])
			u = parent[u];
		return u;
	}

	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		if(rank[x] > rank[y])
			parent[y] = x;
		else
			parent[x] = y;

		if(rank[x] == rank[y])
			rank[y]++;
	}
};

int Graph::KruskalMST()
{
	int mst_wt = 0;

	sort(begin(edges), end(edges));

	DisjointSets ds(v);

	int edge_count = 0;
	for (auto it = edges.begin(); edge_count < v - 1 && it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if(set_u != set_v)
		{
			cout << u << " - " << v << "\n";

			mst_wt += it->first;

			ds.merge(set_u, set_v);
			edge_count++;
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


	int v = 9, e = 14;
	Graph g(v, e);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout<<"\n\nEdges of MST are:\n";
    int mst_wt = g.KruskalMST();

    cout<<"Weight of MST is: "<<mst_wt;
	
	return 0;
}