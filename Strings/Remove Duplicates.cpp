#include<bits/stdc++.h>
using namespace std;

// Remove duplicates from a string
// Brute force method, O(n^2)
string remDup(string s, int l)
{
	string x;
	int i, j;
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < l; j++)
			if (s[i] == s[j])
				break;
		if (j == i)
			x += s[i];
	}
	return x;
}

// Efficient method, O(n)
string remDup2(string s, int l)
{
	int chars[256] = {0};
	string x;
	for (int i = 0; i < l; i++)
	{
		chars[s[i]]++;
		if (chars[s[i]] == 1)
			x += s[i];
	}
	return x;
}

int main()
{
	string s = "geeks for geeks";
	int l = s.length();
	cout << remDup2(s, l);
	return 0;
}