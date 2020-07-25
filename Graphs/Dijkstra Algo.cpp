#include<bits/stdc++.h>
using namespace std;

// Dijkstra algorithm doesn't work for graph woth negative weight edges.

#define V  9
#define iPair pair<int, int>

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


// Using Adjacency list and stl(Min Heap), O(Elog V)
class Graph
{
	int Ver;
	vector< iPair > *graph;

public:
	Graph(int Ver);
	void addEdge(int u, int v, int w);
	void dijkstra(int src);
};

Graph::Graph(int Ver)
{
	this->Ver = Ver;
	graph = new vector< iPair >[Ver];
}

void Graph::addEdge(int u, int v, int w)
{
	graph[u].push_back(make_pair(v, w));
	graph[v].push_back(make_pair(u, w));
}

void Graph::dijkstra(int src)
{
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
	vector<int> dist(Ver, INT_MAX);
	vector<bool> isSet(Ver, false);

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		isSet[u] = true;
		for (auto i : graph[u])
		{
			int v = i.first;
			int wt = i.second;

			if (!isSet[v] && dist[v] > dist[u] + wt)
			{
				dist[v] = dist[u] + wt;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	cout << "\nVertex\tDistance from src\n";
	for (int i = 0; i < Ver; i++)
		cout << i << "\t\t" << dist[i] << "\n";
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
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0	}
	};

	dijkstra(graph, 0);

	Graph g(V);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
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

	g.dijkstra(0);
	return 0;
}