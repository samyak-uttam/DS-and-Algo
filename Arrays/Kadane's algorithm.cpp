#include<bits/stdc++.h>
using namespace std;

// Largest Sum Contagious Subarray
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


// Maximum Product Subarray
int maxProduct(int arr[], int n)
{
	int ans = arr[0], curMin = arr[0], curMax = arr[0];
	for (int i = 1; i < n; i++)
	{
		int temp = curMax;
		curMax = max(arr[i], max(curMax * arr[i], curMin * arr[i]));
		curMin = min(arr[i], min(temp * arr[i], curMin * arr[i]));
		ans = max(ans, curMax);
	}
	return ans;
}

int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Largest Sum is: " << maxSubArraySum(a, n);
	cout << "\nLargest Sum is(DP): " << maxSubArraySumDP(a, n);

	int arr[] = {1, 0, -1, 2, 3, -5, -2};
	n = sizeof(arr) / sizeof(arr[0]);
	cout << "\nMax product: ";
	cout << maxProduct(arr, n);
	return 0;
}