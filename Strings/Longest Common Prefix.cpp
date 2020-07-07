#include<bits/stdc++.h>
using namespace std;

// find the longest common prefix string of an array of strings
// using binary search
bool isCommonPrefix(vector<string> arr, int l)
{
	string s = arr[0].substr(0, l);
	for (int i = 1; i < arr.size(); i++)
		if (arr[i].rfind(s) == string::npos)
			return false;
	return true;
}

string commonPrefix(vector<string> arr)
{
	int n = arr.size();
	if (n == 0)
		return "";
	int minLen = INT_MAX;
	for (string s : arr)
		minLen = min(minLen, int(s.length()));

	int low = 1;
	int high = minLen;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (isCommonPrefix(arr, mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	return arr[0].substr(0, (low + high) / 2);
}

int main()
{
	vector<string> arr = {"flower", "flow", "flight"};

	string ans = commonPrefix(arr);
	cout << ans;
	return 0;
}