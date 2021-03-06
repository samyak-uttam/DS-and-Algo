#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
	int res = 1;
	for (int i = 2; i <= n; i++)
		res = res * i;
	return res;
}

// niave method
int nCr1(int n, int r)
{
	return fact(n) / (fact(r) * fact(n - r));
}

// space and time efficient solution
// Time - O(n)
// Space - O(1)
int nCr2(int n, int r)
{
	if (r > n - r)
		r = n - r;

	int res = 1;
	for (int i = 0; i < r; i++)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

//

int main()
{
	int n = 20, r = 10;

	return 0;
}