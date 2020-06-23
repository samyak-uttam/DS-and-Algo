#include<bits/stdc++.h>
using namespace std;

// find the length of longest unique substring
// naive approach, O(n^3)
int longestUniqueSubstr(string s, int l)
{
	int len = 0;
	for (int i = 0; i < l; i++)
	{
		int x = l;
		for (int j = i; j < x; j++)
		{
			for (int k = j + 1; k < x; k++)
			{
				if (s[j] == s[k])
				{
					x = k;
					break;
				}
			}
		}
		len = max(len, x - i);
	}
	return len;
}

int main()
{
	string str = "abacde";
	int l = str.length();
	cout << longestUniqueSubstr2(str, l);
	return 0;
}