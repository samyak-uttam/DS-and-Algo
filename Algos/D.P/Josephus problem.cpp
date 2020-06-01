#include<bits/stdc++.h>
using namespace std;

// There are n persons and a number k, kth person is killed in circle in a
// fixed direction & k-1 persons are skipped. The task is to choose the
// safe place in the circle so that you are the last one remaining and survive.
// recursive solution, O(n)
int josephus(int n, int k)
{
	if (n == 1)
		return 1;
	return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
	int n = 3, k = 2;
	cout << josephus(n , k);
	return 0;
}