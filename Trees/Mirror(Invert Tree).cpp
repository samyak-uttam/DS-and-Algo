#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// Recursive solution
Node* mirror(Node *root)
{
	if (root == NULL)
		return NULL;

	Node *temp;
	Node *l = mirror(root->left);
	Node *r = mirror(root->right);

	root->left = r;
	root->right = l;
	return root;
}

// Iterative solution
Node *mirrorItr(Node *root)
{
	if (root == NULL)
		return NULL;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node *cur = q.front();
		q.pop();

		swap(cur->left, cur->right);

		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	return root;
}

void inorder(Node *node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "Before mirroring(inverting): ";
	inorder(root);

	root = mirrorItr(root);

	cout << "\nAfter mirroing(inverting): ";
	inorder(root);
	return 0;
}