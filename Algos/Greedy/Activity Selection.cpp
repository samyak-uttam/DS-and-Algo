#include<bits/stdc++.h>
using namespace std;

// Given N activities with their start and finish times. Select the max no
// of activities that can be performed, assuming that only 1 activity
// can be done at a time.
struct Activity
{
	int start, end;
};

bool compare(Activity a1, Activity a2)
{
	return a1.end < a2.end;
}

// using greedy approach
int maxActivities(Activity arr[], int n)
{
	sort(arr, arr + n, compare);
	int act = 1, k = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].start >= arr[k].end)
		{
			act++;
			k = i;
		}
	}
	return act;
}

int main()
{
	Activity arr[] = {{1, 2}, {3, 4}, {2, 3}, {5, 6}};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Max no of possible activities: " << maxActivities(arr, n);

	return 0;
}