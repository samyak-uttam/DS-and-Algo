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

// Left view of a binary tree
void leftViewUtil(Node *root, int level, int &maxLevel)
{
	if (root == NULL)
		return;

	if (level > maxLevel)
	{
		cout << root->data << " ";
		maxLevel = level;
	}

	leftViewUtil(root->left, level + 1, maxLevel);
	leftViewUtil(root->right, level + 1, maxLevel);
}

void leftView(Node *root)
{
	int maxLevel = 0;
	leftViewUtil(root, 1, maxLevel);
}

// Right view of a binary tree
void rightViewUtil(Node *root, int level, int &maxLevel)
{
	if (root == NULL)
		return;

	if (level > maxLevel)
	{
		cout << root->data << " ";
		maxLevel = level;
	}

	rightViewUtil(root->right, level + 1, maxLevel);
	rightViewUtil(root->left, level + 1, maxLevel);
}

void rightView(Node *root)
{
	int maxLevel = 0;
	rightViewUtil(root, 1, maxLevel);
}

// Top view of a binary tree
void topView(struct Node *root)
{
	//Your code here
	if (root == NULL)
		return;

	map<int, int> mp;

	queue<pair<Node *, int>> q;
	q.push({root, 0});

	while (!q.empty())
	{
		pair<Node *, int> cur = q.front();
		Node* node = cur.first;
		int hd = cur.second;
		q.pop();

		if (mp[hd] == 0)
			mp[hd] = node->data;

		if (node->left)
			q.push({node->left, hd - 1});
		if (node->right)
			q.push({node->right, hd + 1});
	}

	for (auto it : mp)
		cout << it.second << " ";
}

// Bottom view of a binary tree
void bottomView(Node *root)
{
	if (root == NULL)
		return;

	map<int, int> mp;

	queue<pair<Node *, int>> q;
	q.push({root, 0});

	while (!q.empty())
	{
		pair<Node *, int> cur = q.front();
		Node* node = cur.first;
		int hd = cur.second;
		q.pop();

		mp[hd] = node->data;

		if (node->left)
			q.push({node->left, hd - 1});
		if (node->right)
			q.push({node->right, hd + 1});
	}

	for (auto it : mp)
		cout << it.second << " ";
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

	cout << "Left View: ";
	leftView(root);

	cout << "\nRight View: ";
	rightView(root);

	cout << "\nTop View: ";
	topView(root);

	cout << "\nBottom View: ";
	bottomView(root);

	return 0;
}