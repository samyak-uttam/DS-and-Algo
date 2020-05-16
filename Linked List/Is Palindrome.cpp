#include<iostream>
using namespace std;

// Check whether linked list is palindrome or notstruct Node
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

Node* reverse(Node *head)
{
	Node *prev = NULL;
	Node *current = head;
	Node *next;

	while (current != NULL)
	{
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

bool isPalindrome()
{
	if (head->next == NULL)
		return true;
	Node *fast_ptr = head, *slow_ptr = head;
	Node *prev_slow;
	Node *sec_half;
	while (1)
	{
		prev_slow = slow_ptr;
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
		// shows even length
		if (fast_ptr == NULL)
		{
			sec_half = slow_ptr;
			break;
		}
		// shows odd length
		else if (fast_ptr->next == NULL)
		{
			sec_half = slow_ptr->next;
			break;
		}
	}
	prev_slow->next = NULL;

	sec_half = reverse(sec_half);
	Node* first_half = head;
	while (first_half && sec_half)
	{
		if (first_half->data != sec_half->data)
			return false;
		first_half = first_half->next, sec_half = sec_half->next;
	}
	return true;
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(2);
	push(1);
	cout << isPalindrome();

	return 0;
}