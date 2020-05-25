#include<bits/stdc++.h>
using namespace std;

// Find the next greater element for each element of the array
// brute force method
void nge(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int nex = -1;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				nex = arr[j];
				break;
			}
		}
		cout << arr[i] << " -> " << nex << "\n";
	}
}

// efficient approach, using stack
void ngeEff(int arr[], int n)
{
	stack<int> st;
	st.push(arr[0]);

	for (int i = 1; i < n; i++)
	{
		while (!st.empty() && st.top() < arr[i])
		{
			cout << st.top() << " -> " << arr[i] << "\n";
			st.pop();
		}
		st.push(arr[i]);
	}
	while (!st.empty())
	{
		cout << st.top() << " -> " << -1 << "\n";
		st.pop();
	}
}

// if output is serially required
void nge2(int arr[], int n)
{
	int ans[n];
	stack<int> st;

	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= arr[i])
			st.pop();
		ans[i] = st.empty() ? -1 : st.top();
		st.push(arr[i]);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}

int main()
{
	int arr[] = {11, 13, 21, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	nge2(arr, n);
	return 0;
}