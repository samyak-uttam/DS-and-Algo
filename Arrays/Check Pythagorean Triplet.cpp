#include<bits/stdc++.h>
using namespace std;

// naive approach, O(n^3)
bool isTriplet(int arr[], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				int x = arr[i] * arr[i], y = arr[j] * arr[j], z = arr[k] * arr[k];

				if (x == y + z || y == x + z || z == x + y)
					return true;
			}
		}
	}
	return false;
}

// efficient approach (using sorting), O(n^2)
bool isTripletEff(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = arr[i] * arr[i];

	sort(arr, arr + n);

	for (int i = n - 1; i >= 2; i--)
	{
		int l = 0, r = i - 1;
		while (l < r)
		{
			if (arr[l] + arr[r] == arr[i])
				return true;
			(arr[l] + arr[r] < arr[i]) ? l++ : r--;
		}
	}
	return false;
}

int main()
{
	int arr[] = {3, 1, 4, 6, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	isTripletEff(arr, n) ? cout << "Yes" : cout << "No";
	return 0;
}