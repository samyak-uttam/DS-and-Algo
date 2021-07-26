#include<bits/stdc++.h>
using namespace std;

// Find the size of the longest substring containing each vowel an even number of times.
// That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
vector<int> vals = {1, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0};
int findTheLongestSubstring(string s) {
	int mask = 0, res = 0;
	vector<int> seen(32, -1);
	for (int i = 0; i < s.size(); i++) {
		mask ^= vals[s[i] - 'a'];
		if (mask != 0 && seen[mask] == -1)
			seen[mask] = i;
		res = max(res, i - seen[mask]);
	}
	return res;
}

// Given a string s. An awesome substring is a non-empty substring of s such that we
// can make any number of swaps in order to make it palindrome.
// Return the length of the maximum length awesome substring of s.
int longestAwesome(string s) {
	int mask = 0, res = 0;
	vector<int> seen(1024, INT_MAX);
	seen[0] = -1;
	for (int i = 0; i < s.size(); i++) {
		mask ^= 1 << (s[i] - '0');
		seen[mask] = min(seen[mask], i);
		res = max(res, i - seen[mask]);
		for (int j = 0; j <= 9; j++)
			res = max(res, i - seen[mask ^ (1 << j)]);
	}
	return res;
}

// A wonderful string is a string where at most one letter appears an odd number of times.
// Given a string word that consists of the first ten English letters, return the number of wonderful non-empty substrings in word.
// If the same substring appears multiple times in word, then count each occurrence separately.
long long wonderfulSubstrings(string word) {
	long long mask = 0, res = 0;
	vector<long long> count(1024, 0);
	count[0] = 1;
	for (int i = 0; i < word.size(); i++) {
		mask ^= 1 << (word[i] - 'a');
		count[mask]++;
		res += count[mask] - 1;
		for (int j = 0; j < 10; j++)
			res += count[mask ^ (1 << j)];
	}
	return res;
}

int main() {
	string s = "eleetminicoworoep";
	cout << "1. " << findTheLongestSubstring(s);
	s = "3242415";
	cout << "\n2. " << longestAwesome(s);
	s = "aabb";
	cout << "\n3. " << wonderfulSubstrings(s);
	return 0;
}