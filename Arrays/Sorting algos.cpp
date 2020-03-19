#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int minInd = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[j] < arr[minInd])
			{
				minInd = j;
			}
		}
		swap(&arr[i], &arr[minInd]);
	}
}

void bubbleSort(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void insertionSort(int arr[], int  n)
{
	for(int i = 1; i < n; i++)
	{
		int k = i - 1, key = arr[i];
		while(k >= 0 && arr[k] > key)
		{
			arr[k+1] = arr[k];
			k--;
		}
		arr[k+1] = key;
	}
}

int main()
{
	while(1)
	{
	    cout<<"Enter the size of the array: ";
        int n;
        cin>>n;
        cout<<"Enter the elements of the array: ";
        int arr[n];
        for(int i = 0;i < n; i++)
        {
            cin>>arr[i];
        }
		cout<<"Enter 1 for sorting with SelectionSort, 2 with BubbleSort, 3 with InsertionSort\n";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1: selectionSort(arr, n);
					break;
			case 2: bubbleSort(arr, n);
					break;
			case 3: insertionSort(arr, n);
					break;
			default: cout<<"Wrong choice.";
					exit(0);
		}
		cout<<"Elements after sorting:\n";
        for(int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
	}
	return 0;
}
