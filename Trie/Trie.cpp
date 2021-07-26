#include<bits/stdc++.h>
using namespace std;

// Trie is an efficient information retrieval data structure using which search complexities
// can be brought to optimal limit.
// With Trie, we can insert and find strings in O(L) time where L is the length of a single word.
// The main disadvantage of tries is that they need a lot of memory for storing the strings.

const int ALPHABET_SIZE = 26;

struct TrieNode {
	TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
	TrieNode() {
		isEndOfWord = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			children[i] = NULL;
	}
};

class Trie {
private:
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string key);
	bool search(string key);
	bool isEmpty(TrieNode* node);
	TrieNode* removeUtil(TrieNode* node, string key, int level);
	TrieNode* remove(string key);
	void displayUtil(TrieNode* node, char str[], int level);
	void display();
};

void Trie::insert(string key) {
	TrieNode *cur = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (cur->children[index] == NULL)
			cur->children[index] = new TrieNode();

		cur = cur->children[index];
	}
	cur->isEndOfWord = true;
}

bool Trie::search(string key) {
	TrieNode *cur = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (cur->children[index] == NULL)
			return false;
		cur = cur->children[index];
	}
	return (cur != NULL && cur->isEndOfWord);
}

bool Trie::isEmpty(TrieNode* node) {
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (node->children[i])
			return false;
	return true;
}

TrieNode* Trie::removeUtil(TrieNode* node, string key, int level) {
	if (node == NULL)
		return NULL;

	if (level == key.length()) {
		if (node->isEndOfWord)
			node->isEndOfWord = false;

		if (isEmpty(node)) {
			delete(node);
			node = NULL;
		}
		return node;
	}

	int index = key[level] - 'a';
	node->children[index] = removeUtil(node->children[index], key, level + 1);

	if (isEmpty(node) && node->isEndOfWord == false) {
		delete(node);
		node = NULL;
	}

	return node;
}

TrieNode* Trie::remove(string key) {
	return removeUtil(root, key, 0);
}

void Trie::displayUtil(TrieNode *node, char str[], int level) {
	if (node->isEndOfWord) {
		str[level] = '\0';
		cout << str << "\n";
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (node->children[i]) {
			str[level] = i + 'a';
			displayUtil(node->children[i], str, level + 1);
		}
	}
}

void Trie::display() {
	char str[20] = {};
	cout << "Content of Trie: \n";
	displayUtil(root, str, 0);
}

int main() {
	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	int n = 8;

	// Construct Trie
	Trie trie;
	for (int i = 0; i < n; i++)
		trie.insert(keys[i]);

	// Search for different keys
	trie.search("the") ? cout << "Yes\n" : cout << "No\n";
	trie.search("these") ? cout << "Yes\n" : cout << "No\n";

	// Dislay Trie
	trie.display();

	// Delete from Trie
	trie.remove("the");
	cout << "\nAfter deleting: \n";
	trie.display();

	return 0;
}