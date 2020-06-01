#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* construct(int arr[], Node *root, int i, int n)
{
	if (i < n)
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
	cout << "Enter data: ";
	int x;
	cin >> x;
	if (x == -1)
		return NULL;
	Node *new_node = new Node();
	new_node->data = x;
	cout << "Enter left child of " << x << "\n";
	new_node->left = create();
	cout << "Enter right child of " << x << "\n";
	new_node->right = create();
	return new_node;
}

bool search(Node *root, int key)
{
	if (root == NULL)
		return false;
	if (root->data == key)
		return true;

	bool ans1 = search(root->left, key);

	if (ans1) return true;

	return search(root->right, key);
}

void preorder(Node *node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node *node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

void postorder(Node *node)
{
	if (node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout << node->data << " ";
}

int height(Node *root)
{
	if (root == NULL)
		return 0;

	int h1 = height(root->left) + 1;
	int h2 = height(root->right) + 1;

	return max(h1, h2);
}

// Level order(Breadth first) traversal of a tree
// using recursion
void printCurLevel(Node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else
	{
		printCurLevel(root->left, level - 1);
		printCurLevel(root->right, level - 1);
	}
}

void levelOrder1(Node *root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
		printCurLevel(root, i);
}

// using queue
void levelOrder2(Node *root)
{
	if (root == NULL)
		return;
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		Node *node = q.front();
		cout << node->data << " ";
		q.pop();

		if (node->left != NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
	}
}

// Check whether tree is balanced or not
bool util(Node *root, bool &ans)
{
	if (root == NULL)
		return 0;
	int l = util(root->left, ans);
	int r = util(root->right, ans);
	if (abs(l - r) > 1)
		ans = 0;
	return max(l, r) + 1;
}

bool isBalanced(Node *root)
{
	bool ans = true;
	util(root, ans);
	return ans;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *root = NULL;
	root = construct(arr, root, 0, n);
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	cout << search(root, 6);
	cout << "\nHeight of tree is: " << height(root);
	cout << "\nLevel order traversal: ";
	levelOrder2(root);
	cout << "\n" << isBalanced(root);
}