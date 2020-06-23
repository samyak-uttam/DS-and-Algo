#include<bits/stdc++.h>
using namespace std;

// freq of each character
map<char, int> freq;

// mapping of character to its huffman value
map<char, string> codes;

struct Node
{
	char data;
	int freq;
	Node *left, *right;
	Node(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator() (Node* l, Node* r)
	{
		return (l->freq > r->freq);
	}
};

priority_queue <Node*, vector<Node*>, compare> minHeap;

void calcFreq(string str, int l)
{
	for (int i = 0; i < l; i++)
		freq[str[i]]++;
}

void storeCodes(Node* root, string str)
{
	if (root == NULL)
		return;
	if (root->data != '#')
		codes[root->data] = str;
	storeCodes(root->left, str + '0');
	storeCodes(root->right, str + '1');
}

// Encoding
string encode(string str, int l)
{
	Node *left, *right, *top;
	for (map<char, int>::iterator it = begin(freq); it != end(freq); it++)
		minHeap.push(new Node(it->first, it->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new Node('#', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");

	string ans;
	for (auto i : str)
		ans += codes[i];
	return ans;
}

// Decoding
string decode(Node *root, string s)
{
	string ans;
	Node *cur = root;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
			cur = cur->left;
		else
			cur = cur->right;
		if (!cur->left && !cur->right)
		{
			ans += cur->data;
			cur = root;
		}
	}
	return ans;
}

void printCodes()
{
	cout << "\nCodes of characters are:\n";
	for (auto it = begin(codes); it != end(codes); it++)
		cout << it->first << " : " << it->second << "\n";
}

int main()
{
	string str = "excellent";
	int l = str.length();
	string encodedStr, decodedStr;
	calcFreq(str, l);

	encodedStr = encode(str, l);
	printCodes();
	cout << "\nEncoded Huffman String: " << encodedStr;

	decodedStr = decode(minHeap.top(), encodedStr);
	cout << "\nDecoded Huffman string: " << decodedStr;
	return 0;
}