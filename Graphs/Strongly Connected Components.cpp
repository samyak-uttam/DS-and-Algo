#include<bits/stdc++.h>
using namespace std;

// Find the Strongly Connected Components(if every vertex is reachable from every other vertex)
// Using Kosaraju's algorithm, O(V + E), (3 graph traversals are required)

class Graph {
	int V;
	vector<int> *graph;
	void fillOrder(int v, bool visited[], stack<int> &Sst);
	void DFSUtil(int v, bool visited[]);
	void tarjanUtil(int u, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& inStack);
public:
	Graph(int V);
	void addEdge(int v, int w);
	int kosaraju();
	Graph getTranspose();
	void tarjan();
};

Graph::Graph(int V) {
	this->V = V;
	graph = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
	graph[v].push_back(w);
}

Graph Graph::getTranspose() {
	Graph gr(V);
	for (int v = 0; v < V; v++) {
		for (auto& i : graph[v])
			gr.addEdge(i, v);
	}
	return gr;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &st) {
	visited[v] = true;
	for (auto i = graph[v].begin(); i != graph[v].end(); i++)
		if (!visited[*i])
			fillOrder(*i, visited, st);
	st.push(v);
}

void Graph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";
	for (auto i = graph[v].begin(); i != graph[v].end(); i++)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

int Graph::kosaraju() {
	stack<int> st;
	bool visited[V] = {false};

	for (int i = 0; i < V; i++)
		if (!visited[i])
			fillOrder(i, visited, st);

	Graph gr = getTranspose();

	memset(visited, false, sizeof(visited));
	int ans = 0;

	while (!st.empty()) {
		int v = st.top(); st.pop();

		if (!visited[v]) {
			ans ++;
			gr.DFSUtil(v, visited);
			cout << endl;
		}
	}
	return ans;
}


// Using Tarjan's algorithm, O(V + E), (single graph traversal)
void Graph::tarjanUtil(int u, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& inStack) {
	static int time = 0;
	disc[u] = low[u] = time++;
	st.push(u);
	inStack[u] = true;
	for (int& v : graph[u]) {
		if (disc[v] == -1) {
			tarjanUtil(v, disc, low, st, inStack);
			low[u] = min(low[u], low[v]);
		}
		else if (inStack[v])
			low[u] = min(low[u], disc[v]);
	}
	// if u is head node of SCC
	if (low[u] == disc[u]) {
		while (st.top() != u) {
			cout << st.top() << " ";
			inStack[st.top()] = false;
			st.pop();
		}
		cout << st.top() << '\n';
		inStack[st.top()] = false;
		st.pop();
	}
}

void Graph::tarjan() {
	vector<int> disc(V, -1), low(V, -1);
	vector<bool> inStack(V, false);
	stack<int> st;
	for (int i = 0; i < V; i++) {
		if (disc[i] == -1)
			tarjanUtil(i, disc, low, st, inStack);
	}
}

int main() {
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.tarjan();
	cout << "SSC's: ";
	return 0;
}