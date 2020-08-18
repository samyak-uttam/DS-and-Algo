#include<bits/stdc++.h>
using namespace std;

/* Find the sum of magic nodes for a given tree, magic nodes are nodes whose sum of
//left subtree nodes is even and right subtree nodes is odd
Tree represented like this
    			11(root)
    	23(L)				44(R)
    13(LL)	9(LR)		21(RL)	  7(RR)
    				6(RLL)	15(RLR)
*/

int magicNodes(int root, int n, vector<int> values, vector<string> pos)
{
	unordered_map<string, pair<int, int>> mp;
	for (int i = 0; i < n - 1; i++)
	{
		string cur = "";
		for (int j = 0; j < pos[i].size(); j++)
		{
			if (pos[i][j] == 'L')
				mp[cur].first += values[i];
			else
				mp[cur].second += values[i];
			cur += pos[i][j];
		}
	}
	int ans = 0;
	if (mp[""].first % 2 == 0 && mp[""].second % 2 != 0)
		ans += root;
	for (int i = 0; i < n - 1; i++)
	{
		if (mp.find(pos[i]) == mp.end())
			continue;
		if (mp[pos[i]].first % 2 == 0 && mp[pos[i]].second % 2 != 0)
			ans += values[i];
	}
	return ans;
}

int main()
{
	int root = 11, n = 9;
	vector<int> values = {23, 44, 13, 9, 22, 7, 6, 15};
	vector<string> pos = {"L", "R", "LL", "LR", "RL", "RR", "RLL", "RLR"};

	cout << magicNodes(root, n, values, pos);
	return 0;
}