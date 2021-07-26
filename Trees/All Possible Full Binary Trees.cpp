#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int val = 0, Node* left = NULL, Node* right = NULL) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

// Given an integer n, return a list of all possible full binary trees with n nodes.
// Each node of each tree in the answer must have Node.val == 0.
unordered_map<int, vector<Node*>> dp;
vector<Node*> allPossibleFBT(int n) {
    if (n < 1 || n % 2 == 0)
        return {};
    if (n == 1)
        return {new Node()};
    if (dp[n].size() == 0) {
        vector<Node*> cur;
        for (int k = 2; k < n; k += 2) {
            vector<Node*> l = allPossibleFBT(k - 1);
            vector<Node*> r = allPossibleFBT(n - k);
            for (int i = 0; i < l.size(); i++)
                for (int j = 0; j < r.size(); j++)
                    cur.push_back(new Node(0, l[i], r[j]));
        }
        dp[n] = cur;
    }
    return dp[n];
}

void preorder(Node *node) {
    if (node == NULL)
        return;
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

int main() {
    int n = 7;
    vector<Node*> res = allPossibleFBT(n);
    for (int i = 0; i < res.size(); i++) {
        preorder(res[i]);
        cout << "\n";
    }
}