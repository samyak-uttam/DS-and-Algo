#include<bits/stdc++.h>
using namespace std;

class MinStack
{
	stack<int> st;
	stack<int> minSt;

public:
	void push(int x)
	{
		st.push(x);
		if (minSt.empty() || minSt.top() >= x)
			minSt.push(x);
	}

	void pop()
	{
		if (st.empty())
			return;
		int cur = st.top();
		st.pop();
		if (minSt.top() == cur)
			minSt.pop();
	}

	int top()
	{
		return st.top();
	}

	int getMin()
	{
		return minSt.top();
	}
};

int main()
{
	MinStack minStack;
	minStack.push(3);
	minStack.push(5);
	cout << minStack.getMin() << "\n";
	minStack.push(2);
	minStack.push(1);
	cout << minStack.getMin() << "\n";
	minStack.pop();
	cout << minStack.getMin() << "\n";
	minStack.pop();
	cout << minStack.top() << "\n";
	return 0;
}