#include<bits/stdc++.h>
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

// From preOrder and inOrder
Node *util(vector<int>& pre, vector<int>& in, int preInd, int inSt,
           int inEnd, map<int, int> mp)
{
	if (preInd >= pre.size() || inSt > inEnd)
		return NULL;

	int cur = pre[preInd];
	Node *root = new Node(cur);

	int inInd = mp[cur];

	root->left = util(pre, in, preInd + 1, inSt, inInd - 1, mp);
	root->right = util(pre, in, preInd + inInd - inSt + 1, inInd + 1, inEnd, mp);
	return root;
}

Node *buildTree(vector<int>& pre, vector<int>& in)
{
	int n = in.size();
	map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[in[i]] = i;

	return util(pre, in, 0, 0, n - 1, mp);
}

// from postOrder and inOrder
Node *util2(vector<int>& post, vector<int>& in, int postInd, int inSt,
            int inEnd, map<int, int> mp)
{
	if (inSt > inEnd || postInd < 0)
		return NULL;

	int cur = post[postInd];
	Node *root = new Node(cur);

	int inInd = mp[cur];

	root->left = util2(post, in, postInd + inInd - inEnd - 1, inSt, inInd - 1, mp);
	root->right = util2(post, in, postInd - 1, inInd + 1, inEnd, mp);
	return root;
}

Node *buildTree2(vector<int>& post, vector<int>& in)
{
	int n = in.size();
	map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[in[i]] = i;
	return util2(post, in, n - 1, 0, n - 1, mp);
}

void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


int main()
{
	vector<int> pre = {3, 9, 20, 15, 7};
	vector<int> in = {9, 3, 15, 20, 7};
	vector<int> post = {9, 15, 7, 20, 3};

	Node *root = buildTree(pre, in);
	inorder(root);

	cout << "\n";

	Node *r = buildTree2(post, in);
	inorder(r);
	return 0;
}