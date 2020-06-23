#include<bits/stdc++.h>
using namespace std;

// given a string representing a number, find if the no can be split into
// two parts, the left part divisible by a and right by b, both having
// no leading zeros

void areDivisible(string s, int l, int a, int b)
{
	vector<int> rem_a(l);
	rem_a[0] = (s[0] - '0') % a;
	for (int i = 1; i < l; i++)
		rem_a[i] = (10 * rem_a[i - 1] + s[i] - '0') % a;

	vector<int> rem_b(l);
	rem_b[l - 1] = (s[l - 1] - '0') % b;
	for (int i = l - 2, p = 10; i >= 0; i--)
	{
		rem_b[i] = (rem_b[i + 1] + p * (s[i] - '0')) % b;
		p = (p * 10) % b;
	}

	int ans = -1;
	for (int i = 0; i < l - 1; i++)
	{
		if (s[i + 1] != '0' && rem_a[i] == 0 && rem_b[i + 1] == 0)
			ans = i;
	}
	if (ans == -1 || s[0] == '0')
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << s.substr(0, ans + 1) << "\n";
	cout << s.substr(ans + 1);
}

int main()
{
	string s = "284254589153928171911281811000";
	int l = s.length();
	int a = 1009, b = 1000;
	areDivisible(s, l, a, b);
	return 0;
}