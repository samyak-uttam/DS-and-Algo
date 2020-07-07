#include<bits/stdc++.h>
using namespace std;

// Sort array a relative to b
void relSort(int a[], int b[], int m, int n)
{
	map<int, int> mp;
	for (int i = 0; i < m; i++)
		mp[a[i]]++;

	for (int i = 0; i < n; i++)
	{
		if (mp[b[i]] != 0)
		{
			for (int j = 0; j < mp[b[i]]; j++)
				cout << b[i] << " ";
			mp[b[i]] = 0;
		}
	}
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		if (i->second)
		{
			for (int j = 0; j < i->second; j++)
				cout << i->first << " ";
		}
	}
}

int main()
{
	int a[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
	int b[] = {2, 1, 8, 3};

	int m = sizeof(a) / sizeof(a[0]);
	int n = sizeof(b) / sizeof(b[0]);
	relSort(a, b, m, n);

	return 0;
}