#include<bits/stdc++.h>
using namespace std;

// Remove all adjacent duplicates from a string
// Efficient approach, using stack and recursion
string remAdj(string s, int l)
{
	if (s.empty())
		return "";
	stack<char> st;
	for (int i = 0; i < l; i++)
		st.push(s[i]);
	s = "";
	int flag = 0, key = 0;
	char c = st.top();
	st.pop();

	while (!st.empty())
	{
		if (st.top() == c)
			flag = 1, key = 1;
		else
		{
			if (flag == 0)
				s += c;
			c = st.top();
			flag = 0;
		}
		st.pop();
	}
	if (flag == 0)
		s += c;
	reverse(begin(s), end(s));
	if (key)
		s = remAdj(s, s.length());
	return s;
}

int main()
{
	string str = "mississipie";
	int l = str.length();
	cout << remAdj(str, l);
	return 0;
}