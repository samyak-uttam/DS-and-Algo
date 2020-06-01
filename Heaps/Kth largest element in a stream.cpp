#include<bits/stdc++.h>
using namespace std;

// we can do it using min heap, instead of creating it from scratch,
// we will use min heap using priority queue
void kthLargest(int arr[], int n, int k)
{
	priority_queue < int, vector <int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
	{
		if (i < k)
		{
			cout << -1 << " ";
			pq.push(arr[i - 1]);
			continue;
		}
		if (i == k)
		{
			pq.push(arr[i - 1]);
			cout << pq.top() << " ";
			continue;
		}
		if (arr[i - 1] <= pq.top())
		{
			cout << pq.top() << " ";
			continue;
		}
		pq.pop();
		pq.push(arr[i - 1]);
		cout << pq.top() << " ";
	}
	cout << "\n";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	kthLargest(arr, n, k);
	return 0;
}