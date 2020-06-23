#include<bits/stdc++.h>
using namespace std;

int maxBalls(int a[], int n, int b[], int m)
{
	int ans = 0;
	int x = 0, y = 0;
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (a[i] < b[j])
			x += a[i++];
		else if (b[j] < a[i])
			y += b[j++];
		else
		{
			ans += max(x, y) + a[i];
			int t1 = a[i], t2 = b[j];
			x = y = 0;
			i++, j++;
			while (i < n && a[i] == t1)
				ans += a[i++];
			while (j < m && b[j] == t2)
				ans += b[j++];
		}
	}
	while (i < n)
		x += a[i++];
	while (j < m)
		y += b[j++];
	ans += max(x, y);
	return ans;
}

int main()
{
	int a[] = {1, 4, 5, 6, 8};
	int b[] = {2, 3, 4, 6, 9};
	int n = sizeof(a) / sizeof(a[0]);
	int m = sizeof(b) / sizeof(b[0]);
	cout << "Max balls: " << maxBalls(a, n, b, m);
	return 0;
}