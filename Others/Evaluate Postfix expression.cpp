#include<bits/stdc++.h>
using namespace std;

// Evaluate Postfix expression(also called Reverse Polish Notation)
int calc(string s, int a, int b)
{
	if (s == "+")
		return a + b;
	else if (s == "-")
		return a - b;
	else if (s == "*")
		return a * b;
	else
		return a / b;
}

int evalRPN(vector<string> vec)
{
	stack<int> st;
	for (int i = 0; i < vec.size(); i++)
	{
		string s = vec[i];
		if (!(s == "+" || s == "-" || s == "*" || s == "/"))
			st.push(stoi(s));
		else
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			int cur = calc(s, b, a);
			st.push(cur);
		}
	}
	return st.top();
}

int main()
{
	vector<string> vec = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	cout << evalRPN(vec);
	return 0;
}