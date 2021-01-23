#include<iostream>

using namespace std;

void selectionSort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int max = 0;
        for(int j=1;j<size-i;j++)
        {
            if(arr[j]>arr[max])
            max=j;
        }
        int swap = arr[size-i-1];
        arr[size-i-1] = arr[max];
        arr[max] = swap;
    }
}

// printing function
void printSortedArray(int arr[],int size)
{
    cout<<"\nPrinting the Sorted array:\n";
    for(int i=0;i<size;i++)
    cout<<"| "<<arr[i]<<" |";
}

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];
    cout<<"\nEnter the elements: \n";
    for(int i=0;i<size;i++)
    cin>>arr[i];

    selectionSort(arr,size);
    printSortedArray(arr,size);
}