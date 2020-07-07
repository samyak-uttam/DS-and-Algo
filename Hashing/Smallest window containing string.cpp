#include<bits/stdc++.h>
using namespace std;

// Smallest window in a string containing all the characters of another string
int l = 173;
string findSubStr(string a, string b)
{
	int m = a.length(), n = b.length();
	if (n > m)
	{
		cout << "No such window exists";
		return "";
	}
	int hasha[l] = {0};
	int hashb[l] = {0};
	for (int i = 0; i < n; i++)
		hashb[b[i]]++;

	int st = 0, st_ind = -1, min_len = INT_MAX, count = 0;
	for (int i = 0; i < m; i++)
	{
		hasha[a[i]]++;
		if (hashb[a[i]] != 0 && hasha[a[i]] <= hashb[a[i]])
			count++;
		if (count == n)
		{
			while (hasha[a[st]] > hashb[a[st]] || hashb[a[st]] == 0)
			{
				if (hasha[a[st]] > hashb[a[st]])
					hasha[a[st]]--;
				st++;
			}

			int cur = i - st + 1;
			if (min_len > cur)
			{
				min_len = cur;
				st_ind = st;
			}
		}
	}
	if (st_ind == -1)
	{
		cout << "No such window exists";
		return "";
	}
	return a.substr(st_ind, min_len);
}

int main()
{
	string a = "timetopractice";
	string b = "toc";
	cout << findSubStr(a, b);
	return 0;
}