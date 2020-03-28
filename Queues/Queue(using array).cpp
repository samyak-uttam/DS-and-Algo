#include<iostream>
using namespace std;
#define MAX 100

int Queue[MAX], front = 0, rear = 0;

void enQueue()
{
	if(rear == MAX)
	{
		cout<<"Queue is full\n";
		return;
	}
	cout<<"Enter data: ";
	cin>>Queue[rear++];
}

void deQueue()
{
	if(front == rear)
	{
		cout<<"Queue is empty\n";
		return;
	}
	cout<<Queue[front]<<" deleted\n";
	for(int i = 0; i < rear - 1; i++)
		Queue[i] = Queue[i+1];
	rear--;
}

bool isEmpty()
{
	return front == rear;
}

void printQueue()
{
	for(int i = front; i < rear; i++)
		cout<<Queue[i]<<" ";
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
    return 0;
}
