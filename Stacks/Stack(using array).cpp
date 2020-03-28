#include<iostream>
using namespace std;
#define MAX 100

int Stack[MAX], top = -1;

void push()
{
	if(top == (MAX - 1))
	{
		cout<<"Stack Overflow.\n";
		return;
	}
	cout<<"Enter data: ";
	cin>>Stack[++top];
}

void pop()
{
	if(top == -1)
	{
		cout<<"Stack Underflow.\n";
		return;
	}
	cout<<Stack[top]<<"deleted\n";
	top--;
}

bool isEmpty()
{
	if(top < 0)
		return true;
	else
		return false;
}

int peek()
{
	if(!isEmpty())
		return Stack[top];
	else
		exit(0);
}

void printStack()
{
	for(int i = top; i >= 0; i--)
		cout<<Stack[i]<<" ";
	cout<<endl;
}

int main()
{
	cout<<"Enter 1 for push,\n";
    cout<<"Enter 2 for pop,\n";
    cout<<"Enter 3 for isEmpty,\n";
    cout<<"Enter 4 for peek,\n";
    cout<<"Enter 5 for printing the Stack,\n";
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
                pop();
                break;
            case 3:
                cout<<isEmpty()<<"\n";
                break;
            case 4:
                cout<<peek()<<"\n";
                break;
            case 5:
                printStack();
                break;
            default:
                cout<<"wrong choice"<<endl;
                exit(0);
        }
    }
    return 0;
}
