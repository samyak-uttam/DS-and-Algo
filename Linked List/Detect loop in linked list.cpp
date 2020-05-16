#include<bits/stdc++.h>
using namespace std;

// Detect if there is a loop in the linked list

struct Node
{
	int data;
	Node *next;
};
Node *head = NULL;

void push(int new_data)
{
	Node *new_node = new(Node);
	new_node->data = new_data;
	new_node->next = NULL;
	if (head != NULL)
		new_node->next = head;
	head = new_node;
}

// Using hashing
bool detectLoop()
{
	Node *temp = head;
	unordered_set<Node*> s;
	while (temp != NULL)
	{
		if (s.find(temp) != s.end())
			return true;
		s.insert(temp);
		temp = temp->next;
	}
	return false;
}

// mark the visited nodes
bool detectLoop2()
{
	Node *temp = head;
	while (temp != NULL)
	{
		if (temp->data > 0)
			temp->data *= -1;
		else
			return true;
		temp = temp->next;
	}
	return false;
}

// most efficient approach
// Using floyd's Cycle algorithm
bool detectLoop3()
{
	Node *fast_ptr = head, *slow_ptr = head;
	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;

		if (fast_ptr == slow_ptr)
			return true;
	}
	return false;
}

int main()
{
	push(20);
	push(4);
	push(15);
	push(10);

	// create loop
	head->next->next->next->next = head;
	cout << detectLoop3();

	return 0;
}