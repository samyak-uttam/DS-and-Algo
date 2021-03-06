#include<bits/stdc++.h>
using namespace std;

// Given a collection of distinct integers, find all possible permutations.
void printPerm(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void permute(int arr[], int l, int r, int n)
{
	if (l == r)
		printPerm(arr, n);
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(arr[l], arr[i]);
			permute(arr, l + 1, r, n);
			swap(arr[l], arr[i]);
		}
	}
}

int main()
{
	int arr[] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	permute(arr, 0, n - 1, n);

	return 0;
}