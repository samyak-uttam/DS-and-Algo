#include<bits/stdc++.h>
using namespace std;
# define MAX 1000

// SUM QUERY SEGMENT TREE WITH LAZY PROPAGATION

int tree[MAX] = {0};
int lazy[MAX] = {0};

// Range Update
// increment every element in the range rs and re by a value inc
void rangeUpdate(int index, int s, int e, int rs, int re, int inc)
{
	if (lazy[index] != 0)
	{
		tree[index] += (e - s + 1) * lazy[index];
		if (s != e)
		{
			lazy[2 * index + 1] += lazy[index];
			lazy[2 * index + 2] += lazy[index];
		}
		lazy[index] = 0;
	}

	// No overlap
	if (rs > e || re < s)
		return;

	// Complete overlap
	if (rs <= s && re >= e)
	{
		tree[index] += (e - s + 1) * inc;
		if (rs != re)
		{
			lazy[2 * index + 1] += inc;
			lazy[2 * index + 2] += inc;
		}
		return;
	}

	int mid = (s + e) / 2;
	rangeUpdate(2 * index + 1, s, mid, rs, re, inc);
	rangeUpdate(2 * index + 2, mid + 1, e, rs, re, inc);

	tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}

// get the sum of numbers in a range
int getSumUtil(int index, int s, int e, int rs, int re)
{
	if (lazy[index] != 0)
	{
		tree[index] += (e - s + 1) * lazy[index];
		if (s != e)
		{
			lazy[2 * index + 1] += lazy[index];
			lazy[2 * index + 2] += lazy[index];
		}
		lazy[index] = 0;
	}

	// No overlap
	if (rs > e || re < s)
		return 0;

	// Complete overlap
	if (rs <= s && re >= e)
		return tree[index];

	int mid = (s + e) / 2;
	int left = getSumUtil(2 * index + 1, s, mid, rs, re);
	int right = getSumUtil(2 * index + 2, mid + 1, e, rs, re);

	return left + right;
}

int getSum(int n, int rs, int re)
{
	if (rs < 0 || re > n - 1 || rs > re)
	{
		cout << "Invalid input.";
		return -1;
	}
	getSumUtil(0, 0, n - 1, rs, re);
}

// construct the segment tree
void constructSTUtil(int arr[], int n, int index, int s, int e)
{
	if (s == e)
	{
		tree[index] = arr[s];
		return;
	}

	int mid = (s + e) / 2;
	constructSTUtil(arr, n, 2 * index + 1, s, mid);
	constructSTUtil(arr, n, 2 * index + 2, mid + 1, e);

	int left = tree[2 * index + 1];
	int right = tree[2 * index + 2];
	tree[index] = left + right;
}

void constructST(int arr[], int n)
{
	constructSTUtil(arr, n, 0, 0, n - 1);
}

int main()
{
	int arr[] = {1, 3, 2, -2, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	constructST(arr, n);

	int rs, re, i, val, inc;
	int start = 0, end = n - 1;

	while (true)
	{
		int choice;
		cout << "\nEnter 1 for sum query, 2 for range update: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nEnter starting and ending index: ";
			cin >> rs >> re;
			cout << "Sum of no's between index " << rs << " and " << re << " is: ";
			cout << getSum(n, rs, re) << "\n";
			break;
		case 2:
			cout << "\nEnter starting, ending index and increment value: ";
			cin >> rs >> re >> inc;
			rangeUpdate(0, start, end, rs, re, inc);
			cout << "Range Updated.\n";
			break;
		default:
			exit(0);
			break;
		}
	}

	return 0;
}
