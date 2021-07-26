#include<bits/stdc++.h>
using namespace std;

// given a list of strings find the longest common prefix of all the strings.

struct TrieNode {
	TrieNode* children[26];
	bool isEnd;
	TrieNode() {
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
		isEnd = false;
	}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string& word) {
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++) {
			int ind = word[i] - 'a';
			if (cur->children[ind] == NULL)
				cur->children[ind] = new TrieNode();
			cur = cur->children[ind];
		}
		cur->isEnd = true;
	}

	string longestPrefix() {
		string res;
		TrieNode* temp = root;
		while (temp->isEnd == false) {
			int child = 0, ind;
			for (int i = 0; i < 26; i++) {
				if (temp->children[i]) {
					ind = i;
					child += temp->children[i] != NULL;
				}
			}
			if (child > 1) break;
			res += ind + 'a';
			temp = temp->children[ind];
		}
		return res;
	}
};

int main() {

	vector<string> strs = {"flower", "flow", "flight"};
	Trie t;
	for (string& word : strs)
		t.insert(word);
	cout << "Longest Prefix is: " << t.longestPrefix();
	return 0;
}