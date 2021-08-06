#include<bits/stdc++.h>
using namespace std;
/* Time complexity -
	D.F.S - O(V+E)
	B.F.S - O(V+E)
	V - no. of vertices, E - no. of edges
*/

class Graph {
	int V;
	vector<int> *graph;
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS();
	void BFS(int s);
};

Graph::Graph(int V) {
	this->V = V;
	this->graph = new vector<int> [V];
}

void Graph::addEdge(int v, int w) {
	graph[v].push_back(w);
}

void Graph::DFSUtil(int u, bool visited[]) {
	visited[u] = true;
	cout << u << " ";

	for (auto& v : graph[u])
		if (!visited[v])
			DFSUtil(v, visited);
}

void Graph::DFS() {
	bool visited[V] = {false};

	// taking loop for the case of disconnected graphs
	for (int i = 0; i < V; i++) {
		if (!visited[i])
			DFSUtil(i, visited);
	}
}

void Graph::BFS(int s) {
	bool visited[V] = {};
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		s = q.front(); q.pop();
		cout << s << " ";

		for (auto& v : graph[s]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

int main() {
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