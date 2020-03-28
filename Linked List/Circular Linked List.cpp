#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *last = NULL;
int size = 0;

void push()
{
	Node *new_node = new(Node);
	cout<<"Enter the data: ";
	cin>>new_node->data;
	if(last == NULL)
	{
		new_node->next = new_node;
		last = new_node;
	}
	else
	{
		new_node->next = last->next;
		last->next = new_node;
	}
	size++;
}

void append()
{
	Node *new_node = new(Node);
	cout<<"Enter the data: ";
	cin>>new_node->data;
	if(last == NULL)
	{
		new_node->next = new_node;
	}
	else
	{
		new_node->next = last->next;
		last->next = new_node;
	}
	last = new_node;
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
		Node *temp = last->next;
		for(int i = 0; i < pos-1; i++)
			temp = temp->next;
		new_node->next = temp->next;
		temp->next = new_node;
		size++;
	}
}

void delBeg()
{
	if(last == NULL)
	{
		cout<<"No elements, can't delete.\n";
		return;
	}
	if(last->next == last)
    {
        cout<<last->data<<" deleted.\n";
        last = NULL;
        return;
    }
	Node *temp = last->next;
	last->next = temp->next;
	cout<<temp->data<<" deleted.\n";
	delete(temp);
	size--;
}

void delEnd()
{
	if(last == NULL)
	{
		cout<<"No elements, can't delete.\n";
		return;
	}
	if(last->next == last)
    {
        cout<<last->data<<" deleted.\n";
        last = NULL;
        return;
    }
    Node *temp = last->next;
    while(temp->next != last)
    	temp = temp->next;
    temp->next = last->next;
    Node *temp1 = last;
    cout<<last->data<<" deleted.\n";
    delete(temp1);
    last = temp;
    size--;
}

void delAfter()
{
	if(last == NULL)
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
		Node *temp = last->next, *prev = last->next;
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

void printList()
{
	if(last != NULL)
	{
        Node *temp = last->next;
		while(temp != last)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<temp->data<<" ";
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
    cout<<"Enter 7 for printing the list,\n";
    cout<<"Enter 8 for finding the size of the list.\n";
	while(1)
    {
        cout<<"Enter you choice: ";
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
                printList();
                break;
            case 8:
            	cout<<"Size of the Circular Linked List is: "<<size<<"\n";
            default:
                cout<<"wrong choice"<<endl;
                exit(0);
        }
    }
	return 0;
}
