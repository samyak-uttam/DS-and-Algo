#include<bits/stdc++.h>
using namespace std;

// Convert Ternary Expression to a Binary Tree

struct Node
{
	char data;
	Node *left, *right;
	Node(char data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};

// Time Complexity: O(n)
Node *formTree(string exp, int &i)
{
	Node *root = new Node(exp[i]);

	if (i == exp.length() - 1)
		return root;
	if (exp[++i] == '?' )
	{
		root->left = formTree(exp, ++i);
		root->right = formTree(exp, ++i);
	}
	return root;
}

void preorder(Node *root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	string exp = "a?b?c:d:e";
	int i = 0;
	Node *root = formTree(exp, i);
	preorder(root);

	return 0;
}