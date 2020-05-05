#include<bits/stdc++.h>
using namespace std;

// Time complexity of search, insertion and deletion is O(h),
// where h is the height of the tree

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

Node* search(Node *root, int key)
{
	if (root == NULL || root->data == key)
		return root;

	if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

Node* insert(Node *root, int data)
{
	if (root == NULL)
		return new Node(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);

	return root;
}

Node *deleteNode(Node *root, int no)
{
	if (root == NULL)
		return root;

	if (no < root->data)
	{
		root-> left = deleteNode(root->left, no);
		return root;
	}
	else if (no > root->data)
	{
		root->right = deleteNode(root->right, no);
		return root;
	}

	if (root->left == NULL)
	{
		Node *temp = root->right;
		delete(root);
		return temp;
	}
	else if (root->right == NULL)
	{
		Node *temp = root->left;
		delete(root);
		return temp;
	}
	else
	{
		Node *predParent = root;
		Node *pred = root->left;

		while (pred->right != NULL)
		{
			predParent = pred;
			pred = pred->right;
		}

		if (predParent != root)
			predParent->right = pred->left;
		else
			predParent->left = pred->left;
		root->data = pred->data;
		delete pred;
		return root;
	}
}

void inorder(Node *node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

Node *lca(Node *root, int v1, int v2)
{
	int x = root->data;

	if (x > v1 && x > v2)
		return lca(root->left, v1, v2);
	else if (x < v1 && x < v2)
		return lca(root->right, v1, v2);

	return root;
}

bool isBST(Node *root, int min, int max)
{
	if (root == NULL)
		return true;
	if (root->data < min || root->data > max)
		return false;

	return
	    isBST(root->left, min, root->data - 1) &&
	    isBST(root->right, root->data + 1, max);
}

int main()
{
	int arr[] = {50, 30, 20, 40, 70, 60, 80};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *root = NULL;
	root = insert(root, arr[0]);
	for (int i = 1; i < n; i++)
		insert(root, arr[i]);
	inorder(root);
	cout << endl;
	root = deleteNode(root, 70);
	inorder(root);

	cout << "\nLowest common ancestor of " << 40 << ", " << 20;
	cout << " is " << (lca(root, 20, 40))->data;

	cout << "\n" << isBST(root, INT_MIN, INT_MAX);
	return 0;
}