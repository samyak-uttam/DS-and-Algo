#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<int> *graph;
	bool isCyclicUtil(int v, bool visited[], bool recStack[]);
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
bool Graph::isCyclicUtil(int v, bool visited[], bool recStack[])
{
	if (visited[v] == false)
	{
		visited[v] = true;
		recStack[v] = true;
		for (auto i = graph[v].begin(); i != graph[v].end(); i++)
		{
			if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
				return true;
			else if (recStack[*i])
				return true;
		}
	}
	recStack[v] = false;
	return false;
}

bool Graph::isCyclic()
{
	bool visited[V] = {false};
	bool recStack[V] = {false};

	for (int i = 0; i < V; i++)
	{
		if (isCyclicUtil(i, visited, recStack))
			return true;
	}
	return false;
}

// Topological Sort, Graph should be DAG (Directed Acyclic Graph)
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