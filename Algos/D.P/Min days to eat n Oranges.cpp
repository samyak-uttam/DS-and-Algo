#include<bits/stdc++.h>
using namespace std;

/* There are n oranges sand you decided to eat some of these oranges every day as follows:

    Eat one orange.
    If the no of remaining oranges (n) is divisible by 2 then you can eat  n/2 oranges.
    If the no of remaining oranges (n) is divisible by 3 then you can eat  2*(n/3) oranges.

	You can only choose one of the actions per day.
	Find the minimum number of days to eat n oranges.
*/

// bottom up approach(tabulation)
int minDays2(int n)
{
	int dp[n + 1] = {};
	dp[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		else if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	return dp[n];
}

// efficient approach
// using memoization(top down approach)
unordered_map<int, int> dp;

int minDays(int n)
{
	if (n <= 1)
		return n;
	if (dp[n] == 0)
		dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
	return dp[n];
}

int main()
{
	int n = 10;

	cout << "Min Days: " << minDays(n);

	return 0;
}