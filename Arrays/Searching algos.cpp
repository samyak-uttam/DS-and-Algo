#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int no)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == no)
			return i;
	}
	return -1;
}

int binarySearch(int arr[], int size, int no)
{
	int l = 0, r = size, m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (no == arr[m])
			return m;
		else if (no < arr[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

int binarySearchRec(int arr[], int l, int r, int no)
{
	if (l <= r)
	{
		int m = (l + r) / 2;
		if (no == arr[m])
			return m;
		else if (no < arr[m])
			return binarySearchRec(arr, l, m - 1, no);
		else
			return binarySearchRec(arr, m + 1, r, no);
	}
	return - 1;
}

int main()
{
	cout << "Enter the size of the array: ";
	int n;
	cin >> n;
	cout << "Enter the elements of the array: ";
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	while (1)
	{
		cout << "Enter 1 for searching with Linear Search, 2 with Binary Search, 3 with Binary Search using recursion\n";
		int choice;
		cin >> choice;
		cout << "Enter the number you want to search: ";
		int no, ind;
		cin >> no;
		switch (choice)
		{
		case 1: ind = linearSearch(arr, n, no);
			break;
		case 2: ind = binarySearch(arr, n, no);
			break;
		case 3: ind = binarySearchRec(arr, 0, n, no);
			break;
		default: cout << "Wrong choice.";
			break;
		}
		if (ind != -1)
			cout << "Element found at position: " << ind + 1 << "\n";
		else
			cout << "Element not found\n";
	}
	return 0;
}