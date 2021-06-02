#include<bits/stdc++.h>
using namespace std;

// Given a string array words, return the maximum value of length(word[i]) * length(word[j])
// where the two words do not share common letters. If no such two words exist, return 0.

// Efficient approach, using Bit Manipulation, O(n^2)
int maxProduct(vector<string>& words) {
	vector<int> mask(words.size());
	int res = 0;
	for (int i = 0; i < words.size(); i++) {
		for (char c : words[i])
			mask[i] |= (1 << (c - 'a'));
		for (int j = i - 1; j >= 0; j--) {
			if (!(mask[i] & mask[j]))
				res = max(res, (int)(words[i].length() * words[j].length()));
		}
	}
	return res;
}

int main() {
	vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	cout << maxProduct(words);
	return 0;
}