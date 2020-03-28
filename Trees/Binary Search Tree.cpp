#include<iostream>
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

Node* search(Node *root, int key)
{
	if(root == NULL || root->data == key)
		return root;

	if(key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

Node* insert(Node *root, int data)
{
	if(root == NULL)
		return new Node(data);

	if(data < root->data)
		root->left = insert(root->left, data);
	else if(data > root->data)
		root->right = insert(root->right, data);

	return root;
}

void inorder(Node *node)
{
	if(node == NULL)
		return;
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

int main()
{
	int arr[] = {50, 30, 20, 40, 70, 60, 80};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *root = insert(root, arr[0]);
	for(int i = 1; i < n; i++)
		insert(root, arr[i]);
	inorder(root);
	return 0;
}
