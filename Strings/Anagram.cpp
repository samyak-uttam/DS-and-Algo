#include<bits/stdc++.h>
using namespace std;

// Check whether two strings are anagram of each other or not
// using sorting, O(nlog n)
bool checkAnagram(string a, string b)
{
	int m = a.length(), n = b.length();
	if (m != n)
		return false;

	sort(begin(a), end(a));
	sort(begin(b), end(b));

	if (a == b)
		return true;
	else
		return false;
}

// by counting no of characters in each string, O(n)
bool checkAnagram2(string a, string b)
{
	int m = a.length(), n = b.length();
	if (m != n)
		return false;

	int count[256] = {};
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
		count[b[i]]--;
	}

	for (int i = 0; i < 256; i++)
		if (count[i])
			return false;
	return true;
}


// Group all the anagrams in a vector of string together
// O(nklog k)
vector<vector<string>> groupAnagrams(vector<string> strs)
{
	vector<vector<string>> ans;
	map<string, vector<string>> mp;
	for (int i = 0; i < strs.size(); i++)
	{
		string cur = strs[i];
		sort(cur.begin(), cur.end());
		mp[cur].push_back(strs[i]);
	}
	for (auto i : mp)
		ans.push_back(i.second);
	return ans;
}

// Efficent solution, O(nk)
vector<vector<string>> groupAnagrams2(vector<string> strs)
{
	vector<vector<string>> ans;
	map<string, vector<string>> mp;
	int count[26];
	for (int i = 0; i < strs.size(); i++)
	{
		memset(count, 0, sizeof(count));
		for (int j = 0; j < strs[i].length(); j++)
			count[strs[i][j] - 'a']++;

		string cur;
		for (int j = 0; j < 26; j++)
		{
			cur += "#";
			cur += to_string(count[j]);
		}
		mp[cur].push_back(strs[i]);
	}
	for (auto i : mp)
		ans.push_back(i.second);
	return ans;
}

int main()
{
	string a = "act", b = "tac";
	cout << checkAnagram2(a, b) << "\n";


	// Group Anagrams
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> vec = groupAnagrams(strs);
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << "\n";
	}

	return 0;
}