#include<bits/stdc++.h>
using namespace std;

// Largest BST in a binary tree
struct Node
{
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

// Naive approach, O(n^2)
bool isBST(Node *root, int min, int max)
{
	if (root == NULL)
		return true;
	if (root->data < min || root->data > max)
		return false;

	return isBST(root->left, min, root->data - 1) &&
	       isBST(root->right, root->data + 1, max);
}

int size(Node *root)
{
	if (root == NULL)
		return 0;
	return size(root->left) + size(root->right) + 1;
}

int largestBST(Node *root)
{
	if (isBST(root, INT_MIN, INT_MAX))
		return size(root);
	return max(largestBST(root->left), largestBST(root->right));
}

// Efficient approach, O(n)
struct Info
{
	int sz; // Size of subtree
	int mi, ma; // min and max value in the subtree
	int ans; // Size of largest BST which is subtree
	// of current node
	bool isBst; // if subtree is BST
};

Info largestBST2(Node *root)
{
	if (root == NULL)
		return {0, INT_MIN, INT_MAX, 0, true};
	if (root->left == NULL && root->right == NULL)
		return {1, root->data, root->data, 1, true};

	Info l = largestBST2(root->left);
	Info r = largestBST2(root->right);

	Info cur;
	cur.sz = l.sz + r.sz + 1;

	if (l.isBst && r.isBst && root->data > l.ma && root->data < r.mi)
	{
		cur.mi = l.mi;
		cur.ma = r.ma;

		cur.ans = cur.sz;
		cur.isBst = true;

		return cur;
	}
	cur.ans = max(l.ans, r.ans);
	cur.isBst = false;
	return cur;
}

int main()
{
	Node *root = new Node(50);
	root->left = new Node(30);
	root->right = new Node(60);
	root->left->left = new Node(5);
	root->left->right = new Node(20);
	root->right->left = new Node(45);
	root->right->right = new Node(70);
	root->right->right->left = new Node(65);
	root->right->right->right = new Node(80);

	cout << "Size of the largest BST is: " << largestBST(root);

	cout << "\nSize of the largest BST is: " << largestBST2(root).ans;
	return 0;
}