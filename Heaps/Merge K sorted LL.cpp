#include<bits/stdc++.h>
using namespace std;

// merge K sorted likned lists

struct Node
{
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

// using divide and conquer
Node *sortedMerge(Node *a, Node *b)
{
	if (!a)
		return b;
	else if (!b)
		return a;

	Node *result = NULL;
	if (a->data < b->data)
	{
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedMerge(a, b->next);
	}
	return result;
}

Node *mergeKLists(Node *arr[], int l)
{
	while (l != 0)
	{
		int i = 0, j = l;
		while (i < j)
		{
			arr[i] = sortedMerge(arr[i], arr[j]);
			i++, j--;
		}
		l = j;
	}
	return arr[0];
}

// using min heap
struct compare {
	bool operator()(Node * a, Node * b)
	{
		return a->data > b->data;
	}
};

Node *mergeKLists2(Node *arr[], int k)
{
	Node *head = NULL, *last;
	priority_queue < Node*, vector < Node*>, compare> pq;

	for (int i = 0; i < k; i++)
		if (arr[i] != NULL)
			pq.push(arr[i]);

	while (!pq.empty())
	{
		Node *top = pq.top();
		pq.pop();

		if (top->next != NULL)
			pq.push(top->next);
		if (head == NULL)
		{
			head = top;
			last = head;
		}
		else
		{
			last->next = top;
			last = top;
		}
	}
	return head;
}

void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}

int main()
{
	int k = 3; // no of linked lists
	int n = 4; // no of elements in each lists

	Node* arr[k];

	arr[0] = new Node(1);
	arr[0]->next = new Node(3);
	arr[0]->next->next = new Node(5);
	arr[0]->next->next->next = new Node(7);

	arr[1] = new Node(2);
	arr[1]->next = new Node(4);
	arr[1]->next->next = new Node(6);
	arr[1]->next->next->next = new Node(8);

	arr[2] = new Node(0);
	arr[2]->next = new Node(9);
	arr[2]->next->next = new Node(10);
	arr[2]->next->next->next = new Node(11);

	Node* head = mergeKLists2(arr, k);

	printList(head);
	return 0;
}