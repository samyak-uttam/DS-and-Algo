#include<iostream>
using namespace std;

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

// iterative and simple
Node* reverse(Node* head)
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
	return prev;
}

// recursive
Node* reverseList(Node* head)
{
	if (!head || !head->next)
		return head;
	Node* node = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
}

// iterative and complex
Node* reverseListItr2(Node* head)
{
	Node *pre = new Node(0), *cur = head;
	pre -> next = head;
	while (cur && cur -> next)
	{
		Node* temp = cur -> next;
		cur -> next = temp -> next;
		temp -> next = pre -> next;
		pre -> next = temp;
	}
	return pre -> next;
}

// print the list
void printList(Node* head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	cout << "List before reversal: ";
	printList(head);

	head = reverse(head);

	cout << "\nList after reversal: ";
	printList(head);

	return 0;
}