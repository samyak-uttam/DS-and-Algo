#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *top = NULL;
int size = 0;

void push()
{
	Node *new_node = new(Node);
	cout << "Enter the data: ";
	cin >> new_node->data;
	new_node->next = NULL;
	if (top != NULL)
		new_node->next = top;
	top = new_node;
	size++;
}

void pop()
{
	if (top == NULL)
	{
		cout << "No elements, can't delete.\n";
		return;
	}
	Node *temp = top;
	top = top->next;
	cout << temp->data << " deleted.\n";
	delete(temp);
	size--;
}

bool isEmpty()
{
	return top == NULL;
}

int peek()
{
	if (!isEmpty())
		return top->data;
	else
		exit(1);
}

void printStack()
{
	Node *temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	cout << "Enter 1 for push,\n";
	cout << "Enter 2 for pop,\n";
	cout << "Enter 3 for isEmpty,\n";
	cout << "Enter 4 for peek,\n";
	cout << "Enter 5 for printing the Stack,\n";
	while (1)
	{
		cout << "Enter you choice: ";
		int choice, pos;
		cin >> choice;
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			cout << isEmpty() << "\n";
			break;
		case 4:
			cout << peek() << "\n";
			break;
		case 5:
			printStack();
			break;
		default:
			cout << "wrong choice" << endl;
			exit(0);
		}
	}
	return 0;
}
