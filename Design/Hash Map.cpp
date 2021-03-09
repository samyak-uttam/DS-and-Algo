#include<bits/stdc++.h>
using namespace std;

// Simplest way to implement hash map
// can only work if the key is of integer type
// Space requirement is very high
// Time Complexity - O(1) for every operation
class HashMapArr {

	int mymap[1001];
public:
	HashMapArr() {
		memset(mymap, -1, sizeof(mymap));
	}

	void insert(int key, int value) {
		mymap[key] = value;
	}

	int getValue(int key) {
		return mymap[key];
	}

	void remove(int key) {
		mymap[key] = -1;
	}
};


// using BST, to get ordered map
// Although the map in stl uses Red Black Self Balancing Tree we will
// use normal BST
// Time Complexity - O(log n) for every operation
struct Node {
	string key;
	int value;
	Node *left, *right;
	Node(string key, int value) {
		this->key = key;
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};

class HashMapBST {
	Node *root;
	int count;

	Node* insertUtil(Node *root, string key, int &value) {
		if (root == NULL) {
			count++;
			return new Node(key, value);
		}

		if (root->key == key)
			root->value = value;
		else if (key < root->key)
			root->left = insertUtil(root->left, key, value);
		else
			root->right = insertUtil(root->right, key, value);

		return root;
	}

	int getValueUtil(Node *root, string key) {
		if (root == NULL)
			return -1;
		if (root->key == key)
			return root->value;

		if (key < root->key)
			return getValueUtil(root->left, key);
		else
			return getValueUtil(root->right, key);
	}

	Node* removeUtil(Node *root, string key) {
		if (root == NULL)
			return root;

		if (key < root->key) {
			root->left = removeUtil(root->left, key);
			return root;
		}
		else if (key > root->key) {
			root->right = removeUtil(root->right, key);
			return root;
		}

		if (root->left == NULL) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else {
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
			root->key = pred->key;
			root->value = pred->value;
			delete pred;
			return root;
		}
	}

public:
	HashMapBST() {
		root = NULL;
		count = 0;
	}

	int size() {
		return count;
	}

	void insert(string key, int value) {
		root = insertUtil(root, key, value);
	}

	int getValue(string key) {
		return getValueUtil(root, key);
	}

	void remove(string key) {
		if (count == 0)
			return;
		root = removeUtil(root, key);
		count--;
	}
};


// using Hash Table, for unordered_map
// We use array of Node Type called Bucket array
// The key is passed thorugh a Hash function which gives the index
// Hash function cconsists of two parts: Hash Code and a Compression function
// Hash Code is a way of converting different types of keys into integers, ex - Number base p
// While the Compression function makes that integer into the bounds of the array, ex - % Bucket Size
// The index can be same for two keys and that condition is called collision
// To handle collision - (1) Closed addressing (Seperate Chaining) (2) Open addressing
// In closed addressing both the keys will go to the same index, so each element of the bucket array will be a linked list
// In open addressing we need to find an alternate index for the key getting same index, we can do hi(a) = hf(a) + f(i), f(0) = 0
// Different types of f(i) gives dfferent open addressing methods, ex - f(i) = i (Linear Probing), f(i) = i^2 (Quadratic Probing)
// Time Complexity - O(1) for all operations

// Load factor - count / numBuckets, each bucket will have on average this many entries
// We try to keep Load factor < 0.7, to keep keek Time Complexity O(1)
// We use use rehashing to increase the size of our bucket Array if Load factor becomes > 0.7

template <typename V>
class MapNode {
public:
	string key;
	V value;
	MapNode* next;

	MapNode(string key, V value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}

	~MapNode() {
		delete next;
	}
};

template <typename V>
class HashMap
{
	MapNode<V>** buckets;
	int count;
	int numBuckets;
	int getBucketIndex(string key) {
		int hashCode = 0;
		int currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hashCode = (hashCode + key[i] * currentCoeff) % numBuckets;
			currentCoeff = (currentCoeff * 37) % numBuckets;
		}
		return hashCode % numBuckets;
	}

	void rehash() {
		MapNode<V>** temp = buckets;
		buckets = new MapNode<V>*[2 * numBuckets];
		for (int i = 0; i < 2 * numBuckets; i++) {
			buckets[i] = NULL;
		}

		int oldBucketCount = numBuckets;
		numBuckets *= 2;
		count = 0;

		for (int i = 0; i < oldBucketCount; i++) {
			MapNode<V>* head = temp[i];
			while (head != NULL) {
				string key = head->key;
				V value = head->value;
				insert(key, value);
				head = head->next;
			}
		}

		for (int i = 0; i < oldBucketCount; i++) {
			MapNode<V>* head = temp[i];
			delete head;
		}
		delete [] temp;
	}
public:
	HashMap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];
		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}
	~HashMap() {
		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	double getLoadFactor() {
		return (1.0 * count) / numBuckets;
	}

	int size() {
		return count;
	}

	V getValue(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				return head->value;
			}
			head = head->next;
		}
		return -1;
	}

	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;

		double loadFactor = (1.0 * count) / numBuckets;
		if (loadFactor > 0.7) {
			rehash();
		}
	}

	V remove(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;
		while (head != NULL) {
			if (head->key == key) {
				if (prev == NULL) {
					buckets[bucketIndex] = head->next;
				}
				else {
					prev->next = head->next;
				}
				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = head->next;
		}
		return -1;
	}
};

int main()
{
	HashMap<int> map;
	for (int i = 0; i < 10; i++) {
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		int value = i + 1;
		map.insert(key, value);
	}
	cout << map.size() << "\n";

	map.remove("abc2");
	map.remove("abc7");

	cout << map.size() << "\n";

	for (int i = 0; i < 10; i++) {
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		cout << key << " : " << map.getValue(key) << "\n";
	}
	return 0;
}