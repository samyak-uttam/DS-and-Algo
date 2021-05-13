#include<bits/stdc++.h>
using namespace std;

// reverse bits of a number
unsigned int reverseBits(unsigned int n) {
	unsigned int rev = 0;
	while (n > 0) {
		rev <<= 1;

		if (n & 1)
			rev ^= 1;
		n >>= 1;
	}
	return rev;
}

// xor of values from 0 to n
int XORuptoN(int N) {
	switch (N & 3) {	// equivalent to N % 4
	case 0:
		return N;
	case 1:
		return 1;
	case 2:
		return N + 1;
	case 3:
		return 0;
	}
	// would never reach this point
	return 0;
}

// Given an integer n and an integer start, Define an array nums where
// nums[i] = start + 2*i (0-indexed) and n == nums.length.
// Return the bitwise XOR of all elements of nums.
int xorOperation(int n, int start) {
	// to find XOR of values within the range of [a,b], we simply XOR XORforN(b) with XORforN(a-1).
	return (start & 1 & n) | ((XORuptoN((start >> 1) - 1) ^ XORuptoN((start >> 1) + n - 1)) << 1);
}

int main()
{
	unsigned int n = 11;
	cout << "No after reversing bits: " << reverseBits(n);

	n = 4;
	int start = 3;
	cout << "\n" << xorOperation(n, start);
	return 0;
}