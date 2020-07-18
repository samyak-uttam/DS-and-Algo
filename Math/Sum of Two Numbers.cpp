#include<bits/stdc++.h>
using namespace std;

// Find the sum of two integers without using + or - operator
int sum(int a, int b)
{
	int carry = 0;
	while (b)
	{
		carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return a;
}

int main()
{
	int a = -10, b = 5;
	cout << sum(a, b);
	return 0;
}