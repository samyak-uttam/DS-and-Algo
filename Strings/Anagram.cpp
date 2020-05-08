#include<bits/stdc++.h>
using namespace std;

// Check whether two strings are anagram of each other or not
// using sorting, O(nlog n)
bool checkAnagram(string a, string b)
{
	int m = a.length(), n = b.length();
	if (m != n)
		return false;

	sort(begin(a), end(a));
	sort(begin(b), end(b));

	if (a == b)
		return true;
	else
		return false;
}

// by counting no of characters in each string, O(n)
bool checkAnagram2(string a, string b)
{
	int m = a.length(), n = b.length();
	if (m != n)
		return false;

	int count[256] = {};
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
		count[b[i]]--;
	}

	for (int i = 0; i < 256; i++)
		if (count[i])
			return false;
	return true;
}

int main()
{
	string a = "act", b = "tac";
	cout << checkAnagram2(a, b);
	return 0;
}