#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
	double r1 = (double) p1.first / p1.second;
	double r2 = (double) p2.first / p2.second;

	return r1 > r2;
}

double fractionalKnapsack(int W, vector<pair<int, int> > arr, int n)
{
	sort(arr.begin(), arr.end(), comp);

	int curWeight = 0;
	double finalValue = 0.0;

	for(int i = 0; i < n; i++)
	{
		if(curWeight + arr[i].second <= W)
		{
			curWeight += arr[i].second;
			finalValue += arr[i].first;
		}
		else
		{
			finalValue += (double) arr[i].first / arr[i].second * (W - curWeight);
			break;
		}
	}

	return finalValue;
}

int main()
{
	int W = 50;

	vector<pair<int, int> > arr = { {120, 30}, {100, 20}, {60, 10}};

	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<fractionalKnapsack(W, arr, n);
}