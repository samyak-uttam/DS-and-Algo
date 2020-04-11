#include<iostream>
using namespace std;

void merge(int a[], int b[], int m, int n)
{
	for(int i = n-1; i >= 0; i--)
	{
		int j, last = a[m-1];
		for(j = m-2; j >= 0 && a[j] > b[i]; j--)
			a[j+1] = a[j];

		if(j != m - 2 || last > b[i])
		{
			a[j+1] = b[i];
			b[i] = last;
		}
	}
}

int main()
{
	int a[] = {1, 5, 9, 10, 15, 20};
	int b[] = {2, 3, 8, 13};
	int m = sizeof(a) / sizeof(a[0]);
	int n = sizeof(b) / sizeof(b[0]);

	merge(a, b, m, n);
	cout<<"Merged array:\n";
	for(int i = 0; i < m; i++)
		cout<<a[i]<<" ";
	for(int i = 0; i < n; i++)
		cout<<b[i]<<" ";
	return 0;
}