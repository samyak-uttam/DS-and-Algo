#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int val) {
		this->val = val;
		left = right = NULL;
	}
};

// You're given the root of a BST, where exactly two nodes of the tree were swapped by mistake.
// Recover the tree without changing its structure.

Node* pre, *mi;
bool found = false;
void inorder(Node* root) {
	if (root == NULL)
		return;
	inorder(root->left);
	if (root->val < pre->val && root->val < mi->val) {
		mi = root;
		found = true;
	}
	if (!found)
		pre = root;
	inorder(root->right);
}

void recoverBST(Node* root) {
	pre = new Node(INT_MIN);
	mi = new Node(INT_MAX);
	inorder(root);
	swap(pre->val, mi->val);
}


// using morris traversal
Node* prev1, *min1;
void recoverBST2(Node* root) {
	min1 = new Node(INT_MAX);
	prev1 = new Node(INT_MIN);

	Node* cur = root;
	while (cur != NULL) {
		if (cur->left == NULL) {
			if (cur->val < prev1->val && cur->val < min1->val) {
				min1 = cur;
				found = true;
			}
			if (!found) prev1 = cur;
			cur = cur->right;
		}
		else {
			Node* pred = cur->left;
			while (pred->right && pred->right != cur)
				pred = pred->right;
			if (pred->right == NULL) {
				pred->right = cur;
				cur = cur->left;
			}
			else {
				pred->right = NULL;
				if (cur->val < prev1->val && cur->val < min1->val) {
					min1 = cur;
					found = true;
				}
				if (!found) prev1 = cur;
				cur = cur->right;
			}
		}
	}
	swap(min1->val, prev1->val);
}


void printIn(Node* root) {
	if (root == NULL)
		return;
	printIn(root->left);
	cout << root->val << " ";
	printIn(root->right);
}

int main() {
	Node* root = new Node(3);
	root->left = new Node(1);
	root->right = new Node(4);
	root->right->left = new Node(2);
	cout << "Inorder before: ";
	printIn(root);
	recoverBST2(root);
	cout << "\nInorder after: ";
	printIn(root);
	return 0;
}