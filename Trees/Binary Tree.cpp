#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* construct(int arr[], Node *root, int i, int n)
{
	if(i < n)
	{
		Node* temp = new(Node);
		temp->data = arr[i];
		temp->left = temp->right = NULL;
		root = temp;

		root->left = construct(arr, root->left, 2 * i + 1, n);

		root->right = construct(arr, root->right, 2 * i + 2, n);
	}
	return root;
}

Node* create()
{
	cout<<"Enter data: ";
	int x;
	cin>>x;
	if(x == -1)
		return NULL;
	Node *new_node = new Node();
	new_node->data = x;
	cout<<"Enter left child of "<<x<<"\n";
	new_node->left = create();
	cout<<"Enter right child of "<<x<<"\n";
	new_node->right = create();
	return new_node;
}

bool search(Node *root, int key)
{
	if(root == NULL)
		return false;
	if(root->data == key)
		return true;

	bool ans1 = search(root->left, key);

	if(ans1) return true;

	return search(root->right, key);
}

void preorder(Node *node)
{
	if(node == NULL)
		return;
	cout<<node->data<<" ";
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node *node)
{
	if(node == NULL)
		return;
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

void postorder(Node *node)
{
	if(node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<" ";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *root = construct(arr, root, 0, n);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	cout<<search(root, 6);
}
