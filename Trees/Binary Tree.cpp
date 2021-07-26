#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* construct(int arr[], Node *root, int i, int n) {
	if (i < n) {
		Node* temp = new(Node);
		temp->data = arr[i];
		temp->left = temp->right = NULL;
		root = temp;

		root->left = construct(arr, root->left, 2 * i + 1, n);

		root->right = construct(arr, root->right, 2 * i + 2, n);
	}
	return root;
}

Node* create() {
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

bool search(Node *root, int key) {
	if (root == NULL)
		return false;
	if (root->data == key)
		return true;

	bool ans1 = search(root->left, key);

	if (ans1) return true;

	return search(root->right, key);
}

void preorder(Node *node) {
	if (node == NULL)
		return;
	cout << node->data << " ";
	preorder(node->left);
	preorder(node->right);
}

// Iterative approach of Preorder traverasal
void preorderTraversal(Node* root) {
	if (root == NULL)
		return {};
	vector<int> res;
	stack<Node*> st;
	st.push(root);

	while (!st.empty()) {
		Node* cur = st.top();
		st.pop();
		cout << cur->val << " ";

		if (cur->right)
			st.push(cur->right);
		if (cur->left)
			st.push(cur->left);
	}
	return res;
}

void inorder(Node *node) {
	if (node == NULL)
		return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

// Iterative approach of Inorder traverasal
void inorderItr(Node *root) {
	stack<Node *> st;
	Node *cur = root;
	while (cur || !st.empty()) {
		while (cur != NULL) {
			st.push(cur);
			cur = cur->left;
		}

		cur = st.top();
		st.pop();
		cout << cur->data << " ";

		cur = cur->right;
	}
}

void postorder(Node *node) {
	if (node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout << node->data << " ";
}

// Iterative approach of Postorder traverasal
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	while (true) {
		while (root) {
			res.push_back(root->val);
			st.push(root);
			root = root->right;
		}
		if (st.empty())
			break;
		root = st.top();
		st.pop();
		root = root->left;
	}
	reverse(res.begin(), res.end());
	return res;
}

int height(Node *root) {
	if (root == NULL)
		return 0;

	int h1 = height(root->left) + 1;
	int h2 = height(root->right) + 1;

	return max(h1, h2);
}

// Level order(Breadth first) traversal of a tree
// using recursion
void printCurLevel(Node *root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else {
		printCurLevel(root->left, level - 1);
		printCurLevel(root->right, level - 1);
	}
}

void levelOrder1(Node *root) {
	int h = height(root);
	for (int i = 1; i <= h; i++)
		printCurLevel(root, i);
}

// using queue
void levelOrder2(Node *root) {
	if (root == NULL)
		return;
	queue<Node *> q;
	q.push(root);
	while (!q.empty()) {
		Node *node = q.front();
		cout << node->data << " ";
		q.pop();

		if (node->left != NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
	}
}

// Level order traversal in spiral form
void spiralLevelOrder(Node *root) {
	if (root == NULL)
		return;
	stack<Node *> s1;
	stack<Node *> s2;
	s1.push(root);
	while (!s1.empty() || !s2.empty()) {
		while (!s1.empty()) {
			Node *temp = s1.top();
			cout << temp->data << " ";
			s1.pop();
			if (temp->left)
				s2.push(temp->left);
			if (temp->right)
				s2.push(temp->right);
		}
		while (!s2.empty()) {
			Node *temp = s2.top();
			cout << temp->data << " ";
			s2.pop();
			if (temp->right)
				s1.push(temp->right);
			if (temp->left)
				s1.push(temp->left);
		}
	}
}

// Check whether tree is balanced or not
int util(Node *root, bool &ans)
{
	if (root == NULL)
		return 0;
	int l = util(root->left, ans);
	int r = util(root->right, ans);
	if (abs(l - r) > 1)
		ans = 0;
	return max(l, r) + 1;
}

bool isBalanced(Node *root) {
	bool ans = true;
	util(root, ans);
	return ans;
}

// Lowest Common Ancestor of a Binary Tree
Node *lca(Node *root, Node *p, Node *q) {
	if (root == NULL)
		return NULL;
	if (root == p || root == q)
		return root;

	Node *l = lca(root->left, p, q);
	Node *r = lca(root->right, p, q);

	if (l && r)
		return root;
	if (!l && !r)
		return  NULL;
	return l ? l : r;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *root = NULL;
	root = construct(arr, root, 0, n);
	preorder(root);
	cout << "\n";
	inorder(root);
	cout << "\n";
	postorder(root);
	cout << "\n";
	spiralLevelOrder(root);
	cout << "\n";
	cout << search(root, 6);
	cout << "\nHeight of tree is: " << height(root);
	cout << "\nLevel order traversal: ";
	levelOrder2(root);
	cout << "\n" << isBalanced(root);

	return 0;
}