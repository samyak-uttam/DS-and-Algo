#include<bits/stdc++.h>
using namespace std;

// Dijkstra algorithm doesn't work for graph woth negative weight edges.

#define V  9

// using Adjacency matrix, O(V^2)
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++)
	{
		if (!sptSet[i] && dist[i] < min)
			min = dist[i], min_index = i;
	}
	return min_index;
}

void printPath(int parent[], int i)
{
	if (i == -1)
		return;
	printPath(parent, parent[i]);
	cout << i << " ";
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	// sptSet[i] will be true if shortest distance from src to i is finalized
	bool sptSet[V];
	// for finding path
	int parent[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;
	parent[src] = -1;

	for (int cnt = 0; cnt < V - 1; cnt++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;

		for (int v = 0; v < V; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
			        && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	cout << "Vertex\tDistance from src\tPath\n";
	for (int i = 0; i < V; i++)
	{
		cout << "\n" << i << "\t\t" << dist[i] << "\t\t";
		printPath(parent, i);
	}
}

int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0	 }
	};

	dijkstra(graph, 0);
	return 0;
}