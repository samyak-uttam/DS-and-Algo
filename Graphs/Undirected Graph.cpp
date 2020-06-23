#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<int> *graph;
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	graph = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
	graph[v].push_back(w);
	graph[w].push_back(v);
}

// Detect cycle in undirected graph
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
	visited[v] = true;
	for (auto i = graph[v].begin(); i != graph[v].end(); i++)
	{
		if (!visited[*i] && isCyclicUtil(*i, visited, v))
			return true;
		else if (*i != parent)
			return true;
	}
	return false;
}

bool Graph::isCyclic()
{
	bool visited[V] = {false};

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			if (isCyclicUtil(i, visited, -1))
				return true;
	}
	return false;
}

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 2);

	cout << g.isCyclic();
	return 0;
}