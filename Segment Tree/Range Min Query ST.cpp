#include<bits/stdc++.h>
using namespace std;

// RANGE MIN QUERY SEGMENT TREE
// Construction - O(n)
// Query - O(log n)
// Node Update - O(log n)
// Range Update - O(n)

// Range Update
// increment every element in the range rs and re by a value inc
void rangeUpdate(int arr[], int *st, int index, int s, int e, int rs, int re, int inc) {
	// No overlap
	if (re < s || rs > e)
		return;

	// Reached Leaf Node
	if (s == e) {
		st[index] += inc;
		arr[s] += inc;
		return;
	}

	int mid = (s + e) / 2;
	rangeUpdate(arr, st, 2 * index + 1, s, mid, rs, re, inc);
	rangeUpdate(arr, st, 2 * index + 2, mid + 1, e, rs, re, inc);

	st[index] = min(st[2 * index + 1], st[2 * index + 2]);
}

// Node Update
void update(int arr[], int *st, int index, int s, int e, int i, int value) {
	// No overlap
	if (i < s || i > e)
		return;

	// Reached Leaf Node
	if (s == e && s == i) {
		st[index] = value;
		arr[i] = value;
		return;
	}

	int mid = (s + e) / 2;
	update(arr, st, 2 * index + 1, s, mid, i, value);
	update(arr, st, 2 * index + 2, mid + 1, e, i, value);

	st[index] = min(st[2 * index + 1], st[2 * index + 2]);
}

// return the minimum number in the given range
int queryUtil(int *st, int index, int s, int e, int rs, int re) {
	// Complete Overlap
	if (rs <= s && re >= e)
		return st[index];

	// No Overlap
	if (rs > e || re < s)
		return INT_MAX;

	// Partial Overlap
	int mid = (s + e) / 2;
	int left = queryUtil(st, 2 * index + 1, s, mid, rs, re);
	int right = queryUtil(st, 2 * index + 2, mid + 1, e, rs, re);

	return min(left, right);
}

int query(int *st, int n, int rs, int re) {
	if (rs < 0 || re > n - 1 || rs > re) {
		cout << "Invalid Input";
		return -1;
	}

	return queryUtil(st, 0, 0, n - 1, rs, re);
}

// construct the segment tree
void constructSTUtil(int arr[], int *st, int index, int s, int e) {
	if (s == e) {
		st[index] = arr[s];
		return;
	}

	int mid = (s + e) / 2;
	constructSTUtil(arr, st, 2 * index + 1, s, mid);
	constructSTUtil(arr, st, 2 * index + 2, mid + 1, e);

	int left = st[2 * index + 1];
	int right = st[2 * index + 2];
	st[index] = min(left, right);
}

int *constructST(int arr[], int n) {
	// exact formula for max size of segment tree - 2 * (2 ^ (ceil(log2n)))
	// which is approximately equal to 4n
	int *st = new int[4 * n];

	constructSTUtil(arr, st, 0, 0, n - 1);
	return st;
}

int main() {
	int arr[] = {1, 3, 2, -2, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	int *st = constructST(arr, n);

	int rs, re, i, val, inc;
	int start = 0, end = n - 1;

	while (true) {
		int choice;
		cout << "\nEnter 1 for query, 2 for node update, 3 for range update: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nEnter starting and ending index: ";
			cin >> rs >> re;
			cout << "Minimum no between index " << rs << " and " << re << " is: ";
			cout << query(st, n, rs, re) << "\n";
			break;
		case 2:
			cout << "\nEnter the index and the value: ";
			cin >> i >> val;
			update(arr, st, 0, start, end, i, val);
			cout << "Value updated.\n";
			break;
		case 3:
			cout << "\nEnter starting, ending index and increment value: ";
			cin >> rs >> re >> inc;
			rangeUpdate(arr, st, 0, start, end, rs, re, inc);
			cout << "Range Updated.\n";
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}
