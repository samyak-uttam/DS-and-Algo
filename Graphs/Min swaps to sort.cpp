#include<bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n)
{
	pair<int, int> a[n];
	for (int i = 0; i < n; i++)
	{
		a[i].first = arr[i];
		a[i].second = i;
	}
	sort(a, a + n);

	vector<bool> vis(n, false);
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (vis[i] || a[i].second == i)
			continue;

		int j = i;
		int cycle_size = 0;

		while (!vis[j])
		{
			vis[j] = 1;
			j = a[j].second;
			cycle_size++;
		}
		if (cycle_size > 0)
			ans += (cycle_size - 1);
	}
	return ans;
}

int main()
{
	int arr[] = {2, 4, 5, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minSwaps(arr, n);
	return 0;
}