#include<bits/stdc++.h>
using namespace std;

// Convert binary tree to Doubly Linked List
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

void bToDLL(Node *root, Node **head)
{
	if (root == NULL)
		return;
	static Node *prev = NULL;
	bToDLL(root->left, head);
	if (*head == NULL)
	{
		prev = NULL;
		*head = root;
	}
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	bToDLL(root->right, head);
}

void bToDLL2(Node *root, Node **head)
{
	if (root == NULL)
		return;
	bToDLL2(root->right, head);

	root->right = *head;
	if (*head != NULL)
		(*head)->left = root;
	*head = root;

	bToDLL2(root->left, head);
}

void printList(Node *head)
{
	Node *node = head;
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->right;
	}
}

int main()
{
	Node *root = new Node(10);
	root->left = new Node(12);
	root->right = new Node(15);
	root->left->left = new Node(25);
	root->left->right = new Node(30);
	root->right->left = new Node(36);

	Node *head = NULL;
	bToDLL(root, &head);

	printList(head);
	return 0;
}