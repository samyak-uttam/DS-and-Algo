#include<bits/stdc++.h>
using namespace std;

/*
 A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

// Given a column title as appear in an Excel sheet, return its corresponding column number.
int titleToNumber(string s)
{
	int ans = 0;
	long x = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		ans += x * (s[i] - 'A' + 1);
		x *= 26;
	}
	return ans;
}

// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
string convertToTitle(int n)
{
	string ans;
	while (n > 0)
	{
		int mod = n % 26;
		if (mod == 0)
		{
			ans.insert(begin(ans), 'Z');
			n = n / 26 - 1;
		}
		else
		{
			ans.insert(begin(ans), 'A' + mod - 1);
			n /= 26;
		}
	}
	return ans;
}

int main()
{
	string s = "ZY";
	int ans = titleToNumber(s);
	cout << "Title to Number: " << ans;

	string str = convertToTitle(ans);
	cout << "\nNumber to Title: " << str;

	return 0;
}