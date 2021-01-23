#include<iostream>

using namespace std;

// function for swapping two number from the given array
void swap(int arr[], int left, int right)
{
    int swap = arr[left];
    arr[left] = arr[right];
    arr[right] = swap;
}

// function of the partitioning the array
int partition(int arr[], int low, int high)
{
    int left, right;
    int pivot_item = arr[low];
    left = low;
    right = high;

    while(left<right)
    {
        // move left while item<pivot
        while(arr[left] <= pivot_item)
        left++;
        // move right while item>pivot
        while(arr[right]> pivot_item)
        right++;

        if(left < right)
        swap(arr,left,right);
    }
    arr[low] = arr[right];
    arr[right] = pivot_item;
    return right;
}

// QuickSort function is used for the sorting the given array with high and low values
void quickSort(int arr[],int low, int high)
{
    int pivot;
    if(high>low)
    {
        pivot = partition(arr, low, high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    
    int arr[size];
    // Entering the values inside the array
    cout<<"\nEnter the values inside the array: "<<endl;
    for(int i=0;i<size;i++)
    cin>>arr[i];
    // calling the quick sort function
    quickSort(arr,0,size);

    // printing the array
    cout<<endl<<endl<<"Printing the whole sorted array:\n";
    for(int i =0; i<size;i++)
    cout<<arr[i]<<endl;
}