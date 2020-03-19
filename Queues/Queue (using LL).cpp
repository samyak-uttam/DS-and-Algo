#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *front = NULL, *rear = NULL;
int size = 0;

void enQueue()
{
	Node *new_node = new(Node);
	cout<<"Enter the data: ";
	cin>>new_node->data;
	new_node->next = NULL;
	if(rear == NULL)
		front = rear = new_node;
	else
	{
		rear->next = new_node;
		rear = new_node;
	}
	size++;
}

void deQueue()
{
	if(front == NULL)
	{
		cout<<"No elements, can't delete.\n";
		return;
	}
	Node *temp = front;
	front = front->next;
	cout<<temp->data<<" deleted.\n";
	if(front == NULL)
		rear = NULL;
	delete(temp);
	size--;
}

bool isEmpty()
{
	return front == rear == NULL;
}

void printQueue()
{
	Node *temp = front;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
    cout<<"Enter 1 for enQueue,\n";
    cout<<"Enter 2 for deQueue,\n";
    cout<<"Enter 3 for isEmpty,\n";
    cout<<"Enter 4 for printing the queue,\n";
	while(1)
    {
        cout<<"Enter you choice: ";
        int choice, pos;
        cin>>choice;
        switch(choice)
        {
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                cout<<isEmpty()<<"\n";
                break;
            case 4:
                printQueue();
                break;
            default:
                cout<<"wrong choice"<<endl;
                exit(0);
        }
    }
}
