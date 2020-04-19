#include<bits/stdc++.h>
using namespace std;

void dLeftRots(int arr[], int n, int d)
{
	int a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = arr[(i + d) % n];
	}
	copy(a, a + n, arr);
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i];
	cout << endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	dLeftRots(arr, n, 3);
	printArr(arr, n);
}