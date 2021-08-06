#include<bits/stdc++.h>
using namespace std;

// A vertex in an undirected connected graph is an articulation point (or cut vertex)
// if removing it (and edges through it) disconnects the graph.
// Articulation points represent vulnerabilities in a connected network – single points whose
// failure would split the network into 2 or more components. They are useful for designing reliable networks.

class Graph {
	int V;
	vector<int> *graph;
	void tarjanAPUtil(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void tarjanAP();
};

Graph::Graph(int V) {
	this->V = V;
	graph = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
	graph[v].push_back(w);
}

// using tarjan's algorithm, O(V + E)
void Graph::tarjanAPUtil(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap) {
	static int time = 0;
	disc[u] = low[u] = time++;
	int children = 0;
	for (int& v : graph[u]) {
		if (disc[v] == -1) {
			children++;
			parent[v] = u;
			tarjanAPUtil(v, disc, low, parent, ap);
			low[u] = min(low[u], low[v]);

			// Case 1. u is root
			if (parent[u] == -1 && children > 1)
				ap[u] = true;

			// Case 2. Atleast one component will get separated
			if (parent[u] != -1 && low[v] >= disc[u])
				ap[u] = true;
		}
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void Graph::tarjanAP() {
	vector<int> disc(V, -1), low(V, -1), parent(V, -1);
	vector<bool> ap(V);

	for (int i = 0; i < V; i++) {
		if (disc[i] == -1)
			tarjanAPUtil(i, disc, low, parent, ap);
	}

	cout << "Articulation Points: ";
	for (int i = 0; i < V; i++) {
		if (ap[i] == true)
			cout << i << " ";
	}
}

int main() {
	Graph g(6);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(1, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 3);
	g.tarjanAP();
	return 0;
}