#include<bits/stdc++.h>
using namespace std;

class Job
{
public:
	int startTime, endTime, profit;
	Job(int s, int e, int p)
	{
		startTime = s;
		endTime = e;
		profit = p;
	}
};

int search(vector<Job> &jobs, int i)
{
	int low = 0, high = i - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (jobs[mid].endTime <= jobs[i].startTime)
		{
			if (jobs[mid + 1].endTime <= jobs[i].startTime)
				low = mid + 1;
			else
				return mid;
		}
		else
			high = mid - 1;
	}
	return -1;
}

int maxProfit(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
	int n = startTime.size();
	// stores profit till ith job
	int dp[n] = {};
	vector<Job> jobs;

	for (int i = 0; i < n; i++)
		jobs.push_back(Job(startTime[i], endTime[i], profit[i]));

	sort(jobs.begin(), jobs.end(), [](Job const & j1, Job const & j2) {
		return j1.endTime < j2.endTime;
	});

	dp[0] = jobs[0].profit;

	for (int i = 1; i < n; i++)
	{
		int cur = jobs[i].profit;

		int idx = search(jobs, i);
		if (idx != -1)
			cur += dp[idx];

		dp[i] = max(dp[i - 1], cur);
	}

	return dp[n - 1];
}

int main()
{
	vector<int> startTime = {1, 3, 3, 2}, endTime = {3, 6, 5, 4};
	vector<int> profit = {50, 70, 40, 10};

	cout << "Max Profit = " << maxProfit(startTime, endTime, profit);
	return 0;
}