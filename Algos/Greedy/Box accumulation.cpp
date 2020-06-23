#include<bits/stdc++.h>
using namespace std;

// Given boxes and their strengths which denotes how many boxes it can have
// on its top. We have to construct piles from all boxes. Find the min no of
// piles needed to be constructed

int noOfPiles(int a[], int n)
{
	sort(a, a + n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		if (!pq.empty() && pq.top() <= a[i])
		{
			a[i] = pq.top() + 1;
			pq.pop();
			pq.push(a[i]);
		}
		else
			pq.push(1);
	}
	return pq.size();
}

int main()
{
	int a[] = {0, 1, 0, 1, 0, 1, 1, 2, 10};
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Required piles: " << noOfPiles(a, n);
}