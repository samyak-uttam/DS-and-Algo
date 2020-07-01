#include<bits/stdc++.h>
using namespace std;

// Find the min no of steps required to move from (0, 0) to (x, y) in
// a 2D matrix of 1's & 0's

int n, m, x, y;

bool isSafe(vector<vector<int>> mat, vector<vector<bool>> &vis, int i, int j)
{
	return ((i >= 0 && i < n) && (j >= 0 && j < m) && mat[i][j] && !vis[i][j]);
}

int minSteps(vector<vector<int>> mat, vector<vector<bool>> &vis, int cur, int b, int c)
{
	if (b == x && c == y)
		return cur;
	vis[b][c] = true;
	int a1 = INT_MAX, a2 = INT_MAX, a3 = INT_MAX, a4 = INT_MAX;
	if (isSafe(mat, vis, b - 1, c))
		a1 = minSteps(mat, vis, cur + 1, b - 1, c);
	if (isSafe(mat, vis, b + 1, c))
		a2 = minSteps(mat, vis, cur + 1, b + 1, c);
	if (isSafe(mat, vis, b, c - 1))
		a3 = minSteps(mat, vis, cur + 1, b, c - 1);
	if (isSafe(mat, vis, b, c + 1))
		a4 = minSteps(mat, vis, cur + 1, b, c + 1);

	int ans = min(a1, min(a2, min(a3, a4)));
	return ans;
}


// Find the minimum cost path from (0, 0) to (n-1, n-1), allowed moves are
// left, right, up, down
// similar to dijkstra's algorithm
struct cell
{
	int x, y;
	int dist;
	cell(int x, int y, int dist)
	{
		this->x = x;
		this->y = y;
		this->dist = dist;
	}
};

bool operator<(const cell& a, const cell& b)
{
	if (a.dist == b.dist)
	{
		if (a.x != b.x)
			return (a.x < b.x);
		else
			return (a.y < b.y);
	}
	return (a.dist < b.dist);
}

bool isSafe(int i, int j)
{
	return (i >= 0 && i < n) && (j >= 0 && j < n);
}

int minCost(vector<vector<int>> grid)
{
	int dist[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = INT_MAX;

	set<cell> s;
	s.insert(cell(0, 0, 0));
	dist[0][0] = grid[0][0];

	int dx[] = { -1, 1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	while (!s.empty())
	{
		cell k = *s.begin();
		s.erase(s.begin());

		for (int i = 0; i < 4; i++)
		{
			int x = k.x + dx[i];
			int y = k.y + dy[i];

			if (!isSafe(x, y))
				continue;
			if (dist[x][y] > dist[k.x][k.y] + grid[x][y])
			{
				if (dist[x][y] != INT_MAX)
					s.erase(s.find(cell(x, y, dist[x][y])));
				dist[x][y] = dist[k.x][k.y] + grid[x][y];
				s.insert(cell(x, y, dist[x][y]));
			}
		}
	}
	return dist[n - 1][n - 1];
}


int main()
{
	n = 9, m = 10;
	x = 3, y = 4;
	vector<vector<int>> mat =
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};
	vector<vector<bool>> vis(n, vector<bool> (m, false));
	if (!mat[0][0] || !mat[x][y])
		cout << -1 << "\n";
	else
	{
		int ans = minSteps(mat, vis, 0, 0, 0);
		if (ans == INT_MAX)
			cout << -1 << "\n";
		else
			cout << ans << "\n";
	}


	// Minimum cost path
	n = 5;
	vector<vector<int>> grid =
	{
		{ 31, 100, 65, 12, 18 },
		{ 10, 13, 47, 157, 6 },
		{ 100, 113, 174, 11, 33 },
		{ 88, 124, 41, 20, 140 },
		{ 99, 32, 111, 41, 20 }
	};
	cout << "Min Cost: " << minCost(grid);
}

