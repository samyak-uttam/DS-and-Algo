#include<bits/stdc++.h>
using namespace std;

// Given two strings of big integers find their product

string multiply(string a, string b)
{
	int l1 = a.length(), l2 = b.length();
	string ans(l1 + l2, '0');
	for (int i = l1 - 1; i >= 0; i--)
	{
		for (int j = l2 - 1; j >= 0 ; j--)
		{
			int cur = (a[i] - '0') * (b[j] - '0') + (ans[i + j + 1] - '0');
			ans[i + j + 1] = cur % 10 + '0';
			ans[i + j] += cur / 10;
		}
	}
	for (int i = 0; i < l1 + l2; i++)
	{
		if (ans[i] != '0')
			return ans.substr(i);
	}
	return "0";
}

int main()
{
	string a = "123", b = "456";
	cout << multiply(a, b);
	return 0;
}