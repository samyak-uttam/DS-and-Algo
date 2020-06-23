#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};

// Using recursion
void getVerticalOrder(Node *root, map<int, vector<int>>& mp, int hd)
{
	if (root == NULL)
		return;
	mp[hd].push_back(root->data);
	getVerticalOrder(root->left, mp, hd - 1);
	getVerticalOrder(root->right, mp, hd + 1);
}

void verticalOrder(Node *root)
{
	map<int, vector<int>> mp;
	getVerticalOrder(root, mp, 0);
	map<int, vector<int>>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
			cout << it->second[i] << " ";
	}
}

// efficient method, O(nlog n)
// using Level order traversal
void verticalOrder2(Node *root)
{
	if (root == NULL)
		return;

	map<int, vector<int>> mp;
	int hd = 0;

	queue<pair<Node *, int>> q;
	q.push(make_pair(root, hd));

	while (!q.empty())
	{
		pair<Node *, int> temp = q.front();
		q.pop();
		hd = temp.second;
		Node* node = temp.first;
		mp[hd].push_back(node->data);

		if (node->left)
			q.push(make_pair(node->left, hd - 1));
		if (node->right)
			q.push(make_pair(node->right, hd + 1));
	}
	map<int, vector<int>>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
			cout << it->second[i] << " ";
	}
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->left->right = new Node(8);
	root->right->right->right = new Node(9);

	cout << "Vertical order traversal: ";
	verticalOrder2(root);
	return 0;
}