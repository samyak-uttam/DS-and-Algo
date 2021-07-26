#include<bits/stdc++.h>
using namespace std;

// You have a cubic storeroom where the width, length, and height of the room are all equal to n units.
// You have to place n boxes in this room where each box is a cube of unit side length.

// There are however some rules to placing the boxes:
// You can place the boxes anywhere on the floor.
// If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
// Given an integer n, return the minimum possible number of boxes touching the floor.

// Explanation
// https://leetcode.com/problems/building-boxes/discuss/1032603/C%2B%2B-detailed-explanation

int minimumBoxes(int n) {
	int bottom = 1, total = 1, h = 1;
	while (total + bottom + h + 1 <= n) {
		bottom += ++h;
		total += bottom;
	}
	int rem = n - total, l = 0, r = h + 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (m * (m + 1) / 2 >= rem)
			r = m - 1;
		else
			l = m + 1;
	}
	return bottom + l;
}

int main() {
	int n = 10;
	cout << "Minimum boxes: " << minimumBoxes(n);
	return 0;
}