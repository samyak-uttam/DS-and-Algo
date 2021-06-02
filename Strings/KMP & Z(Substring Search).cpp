#include<bits/stdc++.h>
using namespace std;

// Return the index of the first occurrence of pattern in text, or -1 if pattern is not part of text.

// Brute force approach, Time - O(m * n), Space - O(1)
int subStrSearch(string text, string pattern) {
	int m = text.length(), n = pattern.length(), j;
	if (n == 0)	return 0;
	for (int i = 0; i <= m - n; i++) {
		for (j = 0; j < n; j++)
			if (text[i + j] != pattern[j])
				break;
		if (j == n)
			return i;
	}
	return -1;
}


// Efficient approach, KMP (Knuth-Morris-Pratt) Algorithm
// Time - O(n + m), Space - O(n)
vector<int> computeLPS(string text, string pattern) {
	int m = text.length(), n = pattern.length();
	// longest suffix that is also a prefix
	vector<int> lps(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j && pattern[i] != pattern[j])
			j = lps[j - 1];
		if (pattern[i] == pattern[j])
			lps[i] = ++j;
	}
	return lps;
}

int subStrSearchKMP(string text, string pattern) {
	int m = text.length(), n = pattern.length();
	if (n == 0)	return 0;
	vector<int> lps = computeLPS(text, pattern);
	for (int i = 0, j = 0; i < m; i++) {
		while (j && text[i] != pattern[j])
			j = lps[j - 1];
		if (text[i] == pattern[j])
			j++;
		if (j == n)
			return i - j + 1;
	}
	return -1;
}


// Z algorithm, Time - O(m + n), Space - O(m + n)
vector<int> getZ(string concat) {
	int n = concat.length();
	vector<int> Z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i > r) {
			l = r = i;
			while (r < n && concat[r] == concat[r - l])
				r++;
			Z[i] = r - l;
			r--;
		}
		else {
			int k = i - l;
			if (Z[k] < r - i + 1)
				Z[i] = Z[k];
			else {
				l = i;
				while (r < n && concat[r] == concat[r - l])
					r++;
				Z[i] = r - l;
				r--;
			}
		}
	}
	return Z;
}

int subStrSearchZ(string text, string pattern) {
	int m = text.length(), n = pattern.length(), l = m + n + 1;
	if (n == 0)	return 0;
	string concat = pattern + "$" + text;

	vector<int> Z = getZ(concat);
	for (int i = n + 1; i < l; i++)
		if (Z[i] == n)
			return i - n - 1;
	return -1;
}

int main() {
	string text = "abxabcabcaby", pattern = "abcaby";
	cout << "The pattern string appears at index: " << subStrSearchZ(text, pattern);

	return 0;
}