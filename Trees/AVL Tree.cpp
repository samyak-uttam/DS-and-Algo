#include<bits/stdc++.h>
using namespace std;

// Time complexity of both insertion and deletion in AVL tree
// is O(log n)

struct Node
{
	int data;
	Node *left, *right;
	int height;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->height = 1;
	}
};

int height(Node *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

int getBalance(Node *node)
{
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

Node *insert(Node *node, int data)
{
	if (node == NULL)
		return new Node(data);

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else
		return node;

	node->height = max(height(node->left), height(node->right)) + 1;

	int bal = getBalance(node);

	if (bal > 1 && data < node->left->data)
		return rightRotate(node);

	if (bal < -1 && data > node->right->data)
		return leftRotate(node);

	if (bal > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (bal < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Node *minValNode(Node *node)
{
	while (node->left != NULL)
		node = node->left;
	return node;
}

Node *deleteNode(Node *root, int no)
{
	if (root == NULL)
		return root;

	if (no < root->data)
		root->left = deleteNode(root->left, no);
	else if (no > root->data)
		root->right = deleteNode(root->right, no);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			Node *temp = root->right ? root->right : root->left;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			delete(temp);
		}
		else
		{
			Node *temp = minValNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	if (root == NULL)
		return root;

	root->height = max(height(root->left), height(root->right)) + 1;
	int bal = getBalance(root);

	if (bal > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	if (bal > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (bal < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	if (bal < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void preOrder(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	Node *root = NULL;

	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);

	cout << "Preorder traversal of the AVL tree is:\n";
	preOrder(root);

	root = deleteNode(root, 10);

	cout << "\nPreorder traversal after deletion is:\n";
	preOrder(root);
	return 0;
}