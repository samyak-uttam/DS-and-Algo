#include<bits/stdc++.h>
using namespace std;

// Find the median of the stream formed by each insertion of x to the stream.

// max heap, for smaller half
priority_queue<double> s;

// min heap, for greater half
priority_queue<double, vector<double>, greater<double>> g;

double med = 0;

void median(double cur)
{
	if (s.size() > g.size())
	{
		if (cur < med)
		{
			g.push(s.top());
			s.pop();
			s.push(cur);
		}
		else
			g.push(cur);
		med = (s.top() + g.top()) / 2.0;
	}
	else if (s.size() == g.size())
	{
		if (cur < med)
		{
			s.push(cur);
			med = (double)s.top();
		}
		else
		{
			g.push(cur);
			med = (double)g.top();
		}
	}
	else
	{
		if (cur > med)
		{
			s.push(g.top());
			g.pop();
			g.push(cur);
		}
		else
			s.push(cur);
		med = (s.top() + g.top()) / 2.0;
	}

	cout << med << endl;
}


int main()
{
	// stream of numbers
	double arr[] = {5, 15, 10, 20, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	s.push(arr[0]);
	med = arr[0];
	cout << med << endl;
	for (int i = 1; i < n; i++)
		median(arr[i]);

	return 0;
}