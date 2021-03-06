#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int maxPreSum; // maximum prefix sum
	int maxSuffSum; // maximum suffix sum
	int sum; // sum of all the elements in that subarray
	int ans; // maximum sum subarray
};

#define MAX 50000
Node tree[4 * MAX];

Node query(int index, int s, int e, int rs, int re)
{
	// No overlap
	if (rs > e || re < s)
		return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};

	// Complete Overlap
	if (rs <= s && re >= e)
		return tree[index];

	int mid = (s + e) / 2;
	Node left = query(2 * index + 1, s, mid, rs, re);
	Node right = query(2 * index + 2, mid + 1, e, rs, re);

	Node cur;
	cur.sum = left.sum + right.sum;
	cur.maxPreSum = max(left.sum + right.maxPreSum, left.maxPreSum);
	cur.maxSuffSum = max(right.sum + left.maxSuffSum, right.maxSuffSum);
	cur.ans = max({left.maxSuffSum + right.maxPreSum,
	               left.ans, right.ans
	              });
	return cur;
}

void constructST(int arr[], int index, int s, int e)
{
	if (s == e)
	{
		tree[index] = {arr[s], arr[s], arr[s], arr[s]};
		return;
	}

	int mid = (s + e) / 2;
	int left = 2 * index + 1, right = 2 * index + 2;

	constructST(arr, left, s, mid);
	constructST(arr, right, mid + 1, e);

	tree[index].maxPreSum = max(tree[left].sum + tree[right].maxPreSum, tree[left].maxPreSum);
	tree[index].maxSuffSum = max(tree[right].sum + tree[left].maxSuffSum, tree[right].maxSuffSum);
	tree[index].sum = tree[left].sum + tree[right].sum;
	tree[index].ans = max({tree[left].maxSuffSum + tree[right].maxPreSum,
	                       tree[left].ans, tree[right].ans
	                      });
}

int main()
{
	int arr[] = { -1, 2, 3, -4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	constructST(arr, 0, 0, n - 1);
	cout << query(0, 0, n - 1, 0, 4).ans << "\n";
	return 0;
}