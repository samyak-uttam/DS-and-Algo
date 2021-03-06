#include<bits/stdc++.h>
using namespace std;

/*
Alice and Bob have an undirected graph of n nodes and 3 types of edges:

    Type 1: Can be traversed by Alice only.
    Type 2: Can be traversed by Bob only.
    Type 3: Can by traversed by both Alice and Bob.

Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi,
find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob.
or -1 if it's impossible for the graph to be fully traversed by Alice and Bob.
*/

class UnionFind
{
    int distinctComp;
    vector<int> components;
public:
    UnionFind(int n)
    {
        distinctComp = n;
        for (int i = 0; i <= n; i++)
            components.push_back(i);
    }
    int findComponent(int a)
    {
        if (components[a] != a)
            components[a] = findComponent(components[a]);
        return components[a];
    }
    bool unite(int a, int b)
    {
        if (findComponent(a) == findComponent(b))
            return false;
        components[findComponent(a)] = b;
        distinctComp--;
        return true;
    }
    bool united()
    {
        return distinctComp == 1;
    }
};

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    int x = 0;
    UnionFind bob(n), alice(n);

    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {return a[0] > b[0];});
    for (auto e : edges)
    {
        int a1 = e[0], a2 = e[1], a3 = e[2];
        switch (a1)
        {
        case 1:
            x += alice.unite(a2, a3);
            break;
        case 2:
            x += bob.unite(a2, a3);
            break;
        case 3:
            x += bob.unite(a2, a3) | alice.unite(a2, a3);
            break;
        }
    }
    return (bob.united() && alice.united()) ? edges.size() - x : -1;
}

int main()
{
    vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    int n = 4;

    cout << maxNumEdgesToRemove(n, edges);

    return 0;
}