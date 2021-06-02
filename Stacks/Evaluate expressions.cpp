#include<bits/stdc++.h>
using namespace std;

// Evaluate Postfix expression(also called Reverse Polish Notation)
int calc(string s, int a, int b) {
	if (s == "+")
		return a + b;
	else if (s == "-")
		return a - b;
	else if (s == "*")
		return a * b;
	else
		return a / b;
}

int evalRPN(vector<string> vec) {
	stack<int> st;
	for (int i = 0; i < vec.size(); i++) {
		string s = vec[i];
		if (!(s == "+" || s == "-" || s == "*" || s == "/"))
			st.push(stoi(s));
		else {
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


// Evaluate infix expression
int evalInfix(string in) {
	stack<int> st;
	char sign = '+';
	int res = 0, cur = 0;
	for (int i = 0; i < in.length(); i++) {
		if (isdigit(in[i]))
			cur = cur * 10 + (in[i] - '0');
		if (!isdigit(in[i]) && !isspace(in[i]) || i == in.length() - 1) {
			if (sign == '+')
				st.push(cur);
			else if (sign == '-')
				st.push(-cur);
			else {
				int x = (sign == '*') ? st.top() * cur : st.top() / cur;
				st.pop();
				st.push(x);
			}
			sign = in[i];
			cur = 0;
		}
	}
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	return res;
}

int main()
{
	vector<string> vec = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	cout << evalRPN(vec);

	string in = "1-1+1";
	cout << "\nInfix value: " << evalInfix(in);
	return 0;
}