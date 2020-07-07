#include<bits/stdc++.h>
using namespace std;

// Check whether a tree is symmertic(mirror around centre) or not
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
bool util(Node *a, Node *b)
{
	if (!a && !b)
		return true;
	if (!a || !b || a->data != b->data)
		return false;
	return util(a->left, b->right) && util(a->right, b->left);
}

bool isSymmetric(Node *root)
{
	if (root == NULL)
		return true;
	return util(root->left, root-> right);
}

// iteratively
bool isSymmetric2(Node *root)
{
	if (root == NULL)
		return true;
	queue<Node *> q;
	q.push(root->left);
	q.push(root->right);
	while (!q.empty())
	{
		Node *x = q.front();
		q.pop();
		Node *y = q.front();
		q.pop();
		if (!x && !y)
			continue;
		if (!x || !y || x->data != y->data)
			return false;
		q.push(x->left);
		q.push(y->right);
		q.push(x->right);
		q.push(y->left);
	}
	return true;
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(4);
	root->right->right = new Node(3);

	cout << isSymmetric2(root);
	return 0;
}