#include<bits/stdc++.h>
using namespace std;

// sqrt of a number
int sqrt(int x)
{
	long l = 1, h = x, ans = 0;
	while (l < h)
	{
		long m = (l + h) / 2;
		if (m * m == x)
			return m;
		else if (m * m < x)
			l = m + 1, ans = m;
		else
			h = m - 1;
	}
	return ans;
}

// calculate x^n
// Recursive Soln
double powRec(double x, int n)
{
	if (n == 0)
		return 1;
	double t;
	t = pow(x, n / 2);
	if (n % 2 == 0)
		return t * t;
	else
	{
		if (n > 0)
			return x * t * t;
		else
			return (t * t) / x;
	}
}

// iterative version of pow
double pow(double x, int n)
{
	if (n < 0)
		x = 1 / x, n = -n;
	double y = 1;
	while (n > 0)
	{
		if (n & 1)
			y *= x;
		x = x * x;
		n = n >> 1;
	}
	return y;
}

int main()
{
	int n = 8;
	cout << sqrt(n);

	double x = 2.1;
	n = 3;
	cout << "\n" << pow(x, n);
	cout << "\n" << power(3, 3);

	return 0;
}