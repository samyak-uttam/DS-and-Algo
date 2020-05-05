#include<bits/stdc++.h>
using namespace std;

// naive approach, O(n^2)
int findWater(int arr[], int n)
{
	int l, r, i, j;
	int vol = 0;
	for (i = 1; i < n - 1; i++)
	{
		l = arr[i], r = arr[i];
		for (j = i - 1; j >= 0; j--)
			l = max(l, arr[j]);

		for (j = i + 1; j < n; j++)
			r = max(r, arr[j]);

		vol += min(l, r) - arr[i];
	}
	return vol;
}

// Efficient approach
// Pre compute highest bars on left and right, O(n)
int findWater2(int arr[], int n)
{
	int i, l[n], r[n];
	l[0] = arr[0];
	for (i = 1; i < n; i++)
		l[i] = max(l[i - 1], arr[i]);

	r[n - 1] = arr[n - 1];
	for (i = n - 2; i >= 0; i--)
		r[i] = max(r[i + 1], arr[i]);

	int ans = 0;
	for (i = 0; i < n; i++)
		ans += min(l[i], r[i]) - arr[i];
	return ans;
}

// Space efficient solution
int findWater3(int arr[], int n)
{
	int ans = 0;
	int l_max = 0, r_max = 0;
	int l = 0, r = n - 1;
	while (l <= r)
	{
		if (arr[l] > arr[r])
		{
			if (arr[r] > r_max)
				r_max = arr[r];
			else
				ans += r_max - arr[r];
			r--;
		}
		else
		{
			if (arr[l] > l_max)
				l_max = arr[l];
			else
				ans += l_max - arr[l];
			l++;
		}
	}
	return ans;
}

int main()
{
	int a[] = {3, 0, 0, 2, 0, 4};
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Water holded is: " << findWater(a, n);
	int b[] = {3, 0, 0, 2, 0, 4};
	n = sizeof(b) / sizeof(b[0]);
	cout << "\nWater holded is: " << findWater3(b, n);
	return 0;
}