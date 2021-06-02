#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<int> *graph;
	bool isCyclicUtil(int v, int visited[]);
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
	void topologicalSort();
	void topologicalSort2();
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

// Detect cycle in directed graph, O(V + E)
bool Graph::isCyclicUtil(int u, int visited[])
{
	if (visited[u] == 0)
	{
		visited[u] = 1;
		for (auto v = graph[u].begin(); v != graph[u].end(); v++)
		{
			if (visited[*v] == 1)
				return true;
			else if (visited[*v] == 0 && isCyclicUtil(*v, visited))
				return true;
		}
		visited[u] = 2;
	}
	return false;
}

bool Graph::isCyclic()
{
	int visited[V] = {};

	for (int i = 0; i < V; i++)
	{
		if (isCyclicUtil(i, visited))
			return true;
	}
	return false;
}

// Topological Sorting of a DAG (Directed Acyclic Graph) is a linear ordering of vertices such
// that for every directed edge u v, vertex u comes before v in the ordering.
// DFS based approach, O(V + E)
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &st)
{
	visited[v] = true;
	for (auto i = graph[v].begin(); i != graph[v].end(); i++)
	{
		if (!visited[*i])
			topologicalSortUtil(*i, visited, st);
	}
	st.push(v);
}

void Graph::topologicalSort()
{
	bool visited[V] = {false};
	stack<int> st;
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			topologicalSortUtil(i, visited, st);
	}

	cout << "\nTopological Sorting: ";
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}

// using Kahn's method (by computing in-degree), O(V + E)
void Graph::topologicalSort2()
{
	vector<int> in_degree(V, 0);
	for (int i = 0; i < V; i++)
	{
		for (auto j = graph[i].begin(); j != graph[i].end(); j++)
			in_degree[*j]++;
	}

	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	cout << "\nTopological Sorting: ";
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (auto i = graph[x].begin(); i != graph[x].end(); i++)
		{
			if (--in_degree[*i] == 0)
				q.push(*i);
		}
	}
}

int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << g.isCyclic();
	g.topologicalSort2();
	return 0;
}