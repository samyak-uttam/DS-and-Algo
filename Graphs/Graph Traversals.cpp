#include<bits/stdc++.h>
using namespace std;
/* Time complexity -
	D.F.S - O(V+E)
	B.F.S - O(V+E)
	V - no. of vertices, E - no. of edges
*/

class Graph
{
	int V;
	vector<int> *graph;
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS();
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	this->graph = new vector<int> [V];
}

void Graph::addEdge(int v, int w)
{
	graph[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	vector<int>::iterator i;
	for (i = graph[v].begin(); i < graph[v].end(); i++)
	{
		if (!visited[*i])
			DFSUtil(*i, visited);
	}
}

void Graph::DFS()
{
	bool visited[V] = {false};

	// taking loop for the case of disconnected graphs
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			DFSUtil(i, visited);
	}
}

void Graph::BFS(int s)
{
	bool visited[V];
	memset(visited, false, sizeof(visited));

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	vector<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (i = graph[s].begin(); i != graph[s].end(); i++)
		{
			if (!visited[*i])
			{
				queue.push_back(*i);
				visited[*i] = true;
			}
		}
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "The DFS is (starting from vertex 2) \n";
	g.DFS();
	cout << endl;
	g.BFS(2);
	return 0;
}