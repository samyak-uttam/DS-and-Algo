#include<bits/stdc++.h>
using namespace std;

// Bellman Ford is a single source shortest path algorithm, and its advantage is
// that it can work on graphs with negative weighted edges.

// This algorithm doesn't work if the graph has negative weight cycle
// Time Complexity - O(V * E)
void bellmanFord(int src, int& V, vector<vector<int>>& edges) {
	vector<int> dist(V, INT_MAX);
	dist[src] = 0;
	for (int i = 0; i < V; i++) {
		for (auto& e : edges) {
			int u = e[0], v = e[1], wt = e[2];
			if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
				dist[v] = dist[u] + wt;
		}
	}
	cout << "\nVertex\tDistance from src\n";
	for (int i = 0; i < V; i++)
		cout << i << "\t\t" << dist[i] << "\n";
}


int main() {
	int V = 4;
	vector<vector<int>> edges = {{1, 0, 1}, {1, 2, 1}, {2, 3, 1}};
	bellmanFord(1, V, edges);
	return 0;
}