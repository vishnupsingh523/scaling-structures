#include<iostream>

using namespace std;

/*
To make it generic we have to declare a template:
In this version I have added a variable 'swapped=1'
which insures that if there is any swaps so its incremented
and if there is no swappes has happend in first run,
then that means the array is already sorted.
*/
template <typename Array, typename sizeOfArray>
void bubbleSortImproved(Array arr[],sizeOfArray size)
{
    int swapped =1;
    for(int i = 0;i<size&&swapped;i++)
    {
        swapped = 0;
        for(int j =0; j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
                swapped++;
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
    double arr[size];
    cout<<"\n\nEnter the elements of array:\n";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    bubbleSortImproved(arr,size);
    // so now if even we are giving double values so it dosen't matter for us we can 
    // handle that thing also because we have generic function and we can change it 
    // accordingly.
}