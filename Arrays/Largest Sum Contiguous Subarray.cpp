#include<bits/stdc++.h>
using namespace std;

// using Kadane's algorithm, doesn't work for all -ve numbers
int maxSubArraySum(int arr[], int n)
{
	int maxSum = 0, curSum = 0;
	for (int i = 0; i < n; i++)
	{
		curSum += arr[i];
		if (curSum < 0)
			curSum = 0;
		else if (maxSum < curSum)
			maxSum = curSum;
	}
	return maxSum;
}

// using dp works for all -ve numbers also
int maxSubArraySumDP(int arr[], int n)
{
	int maxSum = arr[0], curSum = arr[0];
	for (int i = 1; i < n; i++)
	{
		curSum = max(arr[i], curSum + arr[i]);
		maxSum = max(curSum, maxSum);
	}
	return maxSum;
}

int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Largest Sum is: " << maxSubArraySum(a, n);
	cout << "\nLargest Sum is(DP): " << maxSubArraySumDP(a, n);
	return 0;
}