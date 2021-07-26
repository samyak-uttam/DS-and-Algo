#include<bits/stdc++.h>
using namespace std;

// Given a non-empty binary tree, find the maximum path sum.

struct Node {
	int data;
	Node *left, *right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int getSum(Node *root, int &m) {
	if (root == NULL)
		return 0;
	int l = getSum(root->left, m);
	int r = getSum(root->right, m);

	m = max(m, l + r + root->data);
	return max(0, max(l, r) + root->data);
}

int maxPathSum(Node *root) {
	int ans = INT_MIN;
	getSum(root, ans);
	return ans;
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(2);
	root->right = new Node(10);
	root->left->left = new Node(20);
	root->left->right = new Node(1);
	root->right->right = new Node(-25);
	root->right->right->left = new Node(3);
	root->right->right->right = new Node(4);

	cout << "Max path sum is: " << maxPathSum(root);

	return 0;
}