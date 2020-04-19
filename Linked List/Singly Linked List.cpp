#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *head = NULL;
int size = 0;

void push()
{
	Node *new_node = new(Node);
	cout<<"Enter the data: ";
	cin>>new_node->data;
	new_node->next = NULL;
	if(head != NULL)
		new_node->next = head;
	head = new_node;
	size++;
}

void append()
{
	Node *new_node = new(Node);
	cout<<"Enter the data: ";
	cin>>new_node->data;
	new_node->next = NULL;
	if(head == NULL)
		head = new_node;
	else
	{
		Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	size++;
}

void insertAfter()
{
	cout<<"Enter the position you want to insert after: ";
	int pos;
	cin>>pos;
	if(pos < 0 || pos > size)
	{
		cout<<"wrong position.\n";
		return;
	}
	if(pos == 0)
		push();
	else if(pos == size)
		append();
	else
	{
		Node *new_node = new(Node);
		cout<<"Enter the data: ";
		cin>>new_node->data;
		new_node->next = NULL;
		Node *temp = head;
		for(int i = 0; i < pos-1; i++)
			temp = temp->next;
		new_node->next = temp->next;
		temp->next = new_node;
		size++;
	}
}

void delBeg()
{
	if(head == NULL)
	{
		cout<<"No elements, can't delete.\n";
		return;
	}
	Node *temp = head;
	head = head->next;
	cout<<temp->data<<" deleted.\n";
	delete(temp);
	size--;
}

void delEnd()
{
	if(head == NULL)
	{
		cout<<"No elements, can't delete.\n";
		return;
	}
	Node *temp = head;
	if(head->next == NULL)
	{

		cout<<temp->data<<" deleted.\n";
		delete(temp);
		head = NULL, size--;
		return;
	}
	while(temp->next->next != NULL)
		temp = temp->next;
	cout<<temp->next->data<<" deleted.\n";
	delete(temp->next);
	temp->next = NULL;
	size--;
}

void delAfter()
{
	if(head == NULL)
	{
		cout<<"No elements, can't delete.\n";
		return;
	}
	cout<<"Enter the position of the element you want to delete: ";
	int pos;
	cin>>pos;
	if(pos < 1 || pos > size)
	{
		cout<<"wrong position.\n";
		return;
	}
	if(pos == 1)
		delBeg();
	else if(pos == size)
		delEnd();
	else
	{
		Node *temp = head, *prev = head;
		for(int i = 0; i < pos-1; i++)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		cout<<temp->data<<" deleted.\n";
		delete(temp);
		size--;
	}
}

void reverse()
{
	Node *prev = NULL;
	Node *current = head;
	Node *next;

	while(current != NULL)
	{
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	head = prev;
}

void printList()
{
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	cout<<"Enter 1 for inserting into beginning,\n";
    cout<<"Enter 2 for inserting into end,\n";
    cout<<"Enter 3 for inserting into particular position,\n";
    cout<<"Enter 4 for deleting from beginning,\n";
    cout<<"Enter 5 for deleting from end,\n";
    cout<<"Enter 6 for deleting from particular position,\n";
    cout<<"Enter 7 for reversing the Linked list\n";
    cout<<"Enter 8 for printing the list,\n";
    cout<<"Enter 9 for finding the size of the list.\n";
	while(1)
    {
        cout<<"Enter your choice: ";
        int choice, pos;
        cin>>choice;
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                append();
                break;
            case 3:
                insertAfter();
                break;
            case 4:
                delBeg();
                break;
            case 5:
                delEnd();
                break;
            case 6:
                delAfter();
                break;
            case 7:
            	reverse();
            	break;
            case 8:
                printList();
                break;
            case 9:
            	cout<<"Size of the Linked List is: "<<size<<"\n";
            default:
                cout<<"wrong choice"<<endl;
                exit(0);
        }
    }
	return 0;
}
