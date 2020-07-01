#include<bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

// All pairs shortest path problem
// Find shortest distances between every pair of vertices in a weighted directed Graph.

// using DP
void printSolution(int dist[][V])
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				cout << "INF ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

void floydWarshall(int graph[][V])
{
	int dist[V][V], i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}

	printSolution(dist);
}

int main()
{
	int graph[V][V] = { {0, 5, INF, 10},
		{INF, 0, 3, INF},
		{INF, INF, 0, 1},
		{INF, INF, INF, 0}
	};
	floydWarshall(graph);
	return 0;
}