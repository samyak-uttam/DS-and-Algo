#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *left, *right;

	Node(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

// using dfs
vector<int> res;
void distanceKNodesDown(Node* root, int k) {
	if (root == NULL || k < 0)
		return;
	if (k == 0) {
		res.push_back(root->val);
		return;
	}
	distanceKNodesDown(root->left, k - 1);
	distanceKNodesDown(root->right, k - 1);
}

int distanceKNodes(Node* root, Node* target, int k) {
	if (root == NULL)
		return -1;

	if (root == target) {
		distanceKNodesDown(root, k);
		return 0;
	}

	int dl = distanceKNodes(root->left, target, k);
	if (dl != -1) {
		if (k == dl + 1)
			res.push_back(root->val);
		else
			distanceKNodesDown(root->right, k - dl - 2);
		return 1 + dl;
	}

	int dr = distanceKNodes(root->right, target, k);
	if (dr != -1) {
		if (k == dr + 1)
			res.push_back(root->val);
		else
			distanceKNodesDown(root->left, k - dr - 2);
		return 1 + dr;
	}
	return -1;
}


// using dfs(backedge) and bfs
unordered_map<TreeNode*, TreeNode*> parent;
void findParent(TreeNode* root, TreeNode* target) {
	if (root == NULL || root == target)
		return;
	if (root->left) {
		parent[root->left] = root;
		findParent(root->left, target);
	}
	if (root->right) {
		parent[root->right] = root;
		findParent(root->right, target);
	}
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
	unordered_set<TreeNode*> visited;
	vector<int> res;
	findParent(root, target);
	queue<TreeNode*> q;
	q.push(target);
	while (!q.empty() && k >= 0) {
		for (int i = q.size() - 1; i >= 0; i--) {
			TreeNode* cur = q.front();
			q.pop();
			visited.insert(cur);
			if (k == 0)
				res.push_back(cur->val);
			if (cur->left && visited.find(cur->left) == visited.end())
				q.push(cur->left);
			if (cur->right && visited.find(cur->right) == visited.end())
				q.push(cur->right);
			if (parent[cur] && visited.find(parent[cur]) == visited.end())
				q.push(parent[cur]);
		}
		k--;
	}
	return res;
}

int main() {
	Node * root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(4);
	root->left->right = new Node(12);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	Node * target = root->left->right;

	distanceKNodes(root, target, 2);

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

	return 0;
}