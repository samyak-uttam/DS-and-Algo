#include<bits/stdc++.h>
using namespace std;

// Using Morris Traversal, we can traverse a tree without using stack or recursion
// Time Complexity - O(n), n = number of nodes
// Space Complexity - O(1)

struct Node {
	int val;
	Node *left, *right;
	Node(int val) {
		this->val = val;
		left = right = NULL;
	}
};

// Inorder Traversal
vector<int> morrisInorder(Node* root) {
	Node* cur = root;
	vector<int> res;
	while (cur != NULL) {
		if (cur->left == NULL) {
			res.push_back(cur->val);
			cur = cur->right;
		}
		else {
			// inorder predecessor
			Node *pred = cur->left;
			while (pred->right && pred->right != cur)
				pred = pred->right;
			if (pred->right == NULL) {
				pred->right = cur;
				cur = cur->left;
			}
			else {
				res.push_back(cur->val);
				pred->right = NULL;
				cur = cur->right;
			}
		}
	}
	return res;
}

// Preorder Traversal
vector<int> morrisPreorder(Node* root) {
	Node* cur = root;
	vector<int> res;
	while (cur != NULL) {
		if (cur->left == NULL) {
			res.push_back(cur->val);
			cur = cur->right;
		}
		else {
			Node *pred = cur->left;
			while (pred->right && pred->right != cur)
				pred = pred->right;
			if (pred->right == NULL) {
				res.push_back(cur->val);
				pred->right = cur;
				cur = cur->left;
			}
			else {
				pred->right = NULL;
				cur = cur->right;
			}
		}
	}
	return res;
}

void printArr(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << '\n';
}

int main() {

	Node* root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(30);
	root->left->left = new Node(-2);
	root->left->right = new Node(6);
	root->right->right = new Node(40);

	cout << "Inorder Traversal: ";
	vector<int> inorder = morrisInorder(root);
	printArr(inorder);

	cout << "\nPreorder Traversal: ";
	vector<int> preorder = morrisPreorder(root);
	printArr(preorder);
	return 0;
}