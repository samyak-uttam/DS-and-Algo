#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& a)
{
	vector<int> ans;
	int m = a.size();
	if (m == 0)
		return {};
	int n = a[0].size();
	int rs = 0, re = m - 1, cs = 0, ce = n - 1;
	while (rs <= re && cs <= ce)
	{
		for (int i = cs; i <= ce; i++)
			ans.push_back(a[rs][i]);
		rs++;
		for (int i = rs; i <= re; i++)
			ans.push_back(a[i][ce]);
		ce--;
		if (rs <= re)
		{
			for (int i = ce; i >= cs; i--)
				ans.push_back(a[re][i]);
			re--;
		}
		if (cs <= ce)
		{
			for (int i = re; i >= rs; i--)
				ans.push_back(a[i][cs]);
			cs++;
		}
	}
	return ans;
}

int main()
{
	vector<vector<int>> vec = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};

	vector<int> ans = spiralOrder(vec);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}