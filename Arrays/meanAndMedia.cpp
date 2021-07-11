#include<bits/stdc++.h>
using namespace std;

int median(int A[],int N)
{
    sort(A,A+N);
    if(N%2==0)
    return A[N/2];
    else
    return A[N/2-1];    
}

//Function to find mean of the array elements.
int mean(int A[],int N)
{
    int mean = 0;
    for(int i=0;i<N;i++)
    mean += A[i];

    return mean/N;
}

int main(){
    cout<<"Size: ";
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<"Mean : "<<mean(arr, size);
    cout<<"\nMedian: "<<median(arr,size);
}