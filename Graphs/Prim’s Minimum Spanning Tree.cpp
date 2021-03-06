#include<bits/stdc++.h>
#define iPair pair<int, int>
#define V 9
using namespace std;

vector<iPair> graph[V];

void addEdge(int u, int v, int wt)
{
	graph[u].push_back({v, wt});
	graph[v].push_back({u, wt});
}

int primMST()
{
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
	int src = 0;
	vector<int> parent(V, -1);
	vector<int> inMST(V, false);
	vector<int> key(V, INT_MAX);

	pq.push({0, src});
	key[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		inMST[u] = true;

		for (auto i : graph[u])
		{
			int v = i.first;
			int wt = i.second;

			if (inMST[v] == false && key[v] > wt)
			{
				key[v] =  wt;
				pq.push({key[v], v});
				parent[v] = u;
			}
		}
	}
	for (int i = 1; i < V; i++)
		cout << parent[i] << "-" << i << "\n";
	return 0;
}

int main()
{
	addEdge(0, 1, 4);
	addEdge(0, 7, 8);
	addEdge(1, 7, 11);
	addEdge(2, 3, 7);
	addEdge(2, 8, 2);
	addEdge(2, 5, 4);
	addEdge(3, 4, 9);
	addEdge(3, 5, 14);
	addEdge(4, 5, 10);
	addEdge(5, 6, 2);
	addEdge(6, 7, 1);
	addEdge(6, 8, 6);
	addEdge(7, 8, 7);

	cout << "Edges of MST are:\n";
	int mst_wt = primMST();

	cout << "Weight of MST is: " << mst_wt;

	return 0;
}