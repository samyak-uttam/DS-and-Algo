#include<bits/stdc++.h>
using namespace std;

// Find the minimum window in a string S which will contain all the
// characters in string T
string minWindow(string s, string t)
{
	map<char, int> need;
	for (int i = 0; i < t.length(); i++)
		need[t[i]]++;
	int left = 0, minLen = 0, l = 0, r = 0;
	int missing = t.length();
	while (r < s.length())
	{
		if (need[s[r]] > 0)
			missing--;
		need[s[r++]]--;
		while (missing == 0)
		{
			if (minLen == 0 || (r - l) < minLen)
				left = l, minLen = r - l;
			need[s[l]]++;
			if (need[s[l]] > 0)
				missing++;
			l++;
		}
	}
	return s.substr(left, minLen);
}

int main()
{
	string s = "acbdnracbn", t = "abn";

	cout << minWindow(s, t);
	return 0;
}