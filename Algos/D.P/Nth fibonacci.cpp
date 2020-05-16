#include<bits/stdc++.h>
using namespace std;

// Generate the nth fibonacci number
// using recursion
int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

// using Dynamic Programming, O(n)
int fibDP(int n)
{
	int dp[n + 1];
	dp[0] = 0, dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}
// in O(1) space and O(n) time complexity
int fib3(int n)
{
	int a = 0, b = 1, c;
	if (n <= 1)
		return n;
	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

// using formula, O(1)
int fib4(int n)
{
	double x = ((1 + sqrt(5)) / 2);
	return round(pow(x, n)) / sqrt(5);
}

int main()
{
	int n = 8;
	cout << n << "th fibonacci number is: " << fib3(n);
	return 0;
}