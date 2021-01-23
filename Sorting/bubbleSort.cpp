#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        for(int j =0; j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }

    cout<<endl<<"Printing after sorting:\n";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<endl;
}

int main(){
    cout<<"Enter the size of the array: ";
    int size; 
    cin>>size;
    int arr[size];
    cout<<"\n\nEnter the elements of array:\n";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    bubbleSort(arr,size);
}