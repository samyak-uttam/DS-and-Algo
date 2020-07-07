#include<bits/stdc++.h>
using namespace std;

// COunt the no prime numbers less than n

// Naive approach, O(n^1.5)
bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int countPrimes(int n)
{
	int ans = 0, i, j;
	for (i = 2; i <= n; i++)
		if (isPrime(i))
			ans++;
	return ans;
}

// Sieve of Eratosthenes, O(nloglog n)
int sieveOfEratosthenes(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	int ans = 0;
	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p])
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int i = 2; i <= n; i++)
		if (prime[i])
			ans++;
	return ans;
}

int main()
{
	int n = 11;
	cout << sieveOfEratosthenes(n);
	return 0;
}