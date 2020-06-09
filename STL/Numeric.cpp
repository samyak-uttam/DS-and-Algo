#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int parUserDef(int x, int y)
{
	return x + 2 * y;
}

int main()
{
	// count, the no of elements in [first,last) equal to val.
	vector<int> vec{3, 2, 1, 3, 3, 5, 3};
	cout << "Number of times 3 appears : ";
	cout << count(begin(vec), end(vec), 3);


	// accumulate, the sum of the values in range [first, last)
	cout << "\nSum is: " << accumulate(begin(vec), end(vec), 0);


	// partial_sum, the partial sum of all values in
	// [first, last) and stores it in another array b.
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int b[n];
	partial_sum(arr, arr + n, b);
	cout << "\n";

	// using user defined function
	printArr(b, n);
	partial_sum(arr, arr + n, b, parUserDef);
	printArr(b, n);


	// inner_product
	int x[] = {10, 20, 30};
	int y[] = {1, 2, 3};
	n = sizeof(x) / sizeof(x[0]);
	cout << "Inner product of x & y is: " << inner_product(x, x + n, y, 0);


	// adjacent_difference
	int a[] = {1, 2, 3, 5, 9, 11, 12};
	n = sizeof(a) / sizeof(a[0]);
	int res[n];
	adjacent_difference(a, a + n, res);
	cout << "\nAdjacent difference: ";
	printArr(res, n);

	return 0;
}