#include<bits/stdc++.h>
using namespace std;

// Find all unique triplets in the array which gives the sum of zero.

// Naive approach, will have duplicates too
void threeSum(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if (arr[i] + arr[j] + arr[k] == 0)
					cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
}

// Efficient approach, with no duplicates
void threeSumEff(int arr[], int n)
{
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; i++)
	{
		if (i != 0 && arr[i] == arr[i - 1])
			continue;
		int target = 0 - arr[i];
		int l = i + 1, h = n - 1;
		while (l < h)
		{
			if (arr[l] + arr[h] < target)
				l++;
			else if (arr[l] + arr[h] > target)
				h--;
			else
			{
				cout << arr[i] << " " << arr[l] << " " << arr[h] << "\n";
				while (l < h && arr[l] == arr[l + 1]) l++;
				while (l < h && arr[h] == arr[h - 1]) h--;
				l++;
				h--;
			}
		}
	}
}

int main()
{
	int arr[] = { -1, 0, 1, 2, -1, -4};
	int n = sizeof(arr) / sizeof(arr[0]);
	threeSumEff(arr, n);
	return 0;
}