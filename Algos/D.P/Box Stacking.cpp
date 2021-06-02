#include<bits/stdc++.h>
using namespace std;

// You are given n boxes, you have to form a stack with max height, a box can be placed on
// top of another box only if the 2D base of first is strictly greater than 2nd box. You can
// perform rotations on a box and use the rotated boxes also.
// dp concept similar to longest increasing subsequence, O(n^2)

struct Box
{
	// length, width, height
	int l, w, h;
};

vector<Box> createRotations(int length[], int width[], int height[], int n)
{
	vector<Box> rot(3 * n);

	int k = 0;
	for (int i = 0; i < n; i++)
	{
		rot[k].h = height[i];
		rot[k].l = max(width[i], length[i]);
		rot[k].w = min(width[i], length[i]);
		k++;

		rot[k].h = width[i];
		rot[k].l = max(height[i], length[i]);
		rot[k].w = min(height[i], length[i]);
		k++;

		rot[k].h = length[i];
		rot[k].l = max(width[i], height[i]);
		rot[k].w = min(width[i], height[i]);
		k++;
	}
	return rot;
}

int maxStackHeight(int length[], int width[], int height[], int n)
{
	vector<Box> rot = createRotations(length, width, height, n);

	sort(begin(rot), end(rot), [](Box const & b1, Box const & b2) {
		return b1.l * b1.w > b2.l * b2.w;
	});

	int ans = 0;
	n = n * 3;
	int dp[n] = {};
	for (int i = 0; i < n; i++)
	{
		dp[i] = rot[i].h;
		for (int j = i - 1; j >= 0; j--)
		{
			if (rot[i].l < rot[j].l && rot[i].w < rot[j].w)
				dp[i] = max(dp[i], dp[j] + rot[i].h);
		}
	}
	return *max_element(dp, dp + n);
}

int main()
{
	int length[] = {7, 3, 6, 32};
	int width[] = {6, 2, 5, 12};
	int height[] = {4, 1, 4, 10};

	int n = sizeof(length) / sizeof(length[0]);

	cout << "Max Height of stack: " << maxStackHeight(length, width, height, n);

	return 0;
}