#include<iostream>
using namespace std;

int main(){
    int arr[20];
    int sum=0;
    int * ptr;

    cout<<"Enter the values of array: "<<endl;
    for(int i =0;i<20;i++)
    {
        cin>>arr[i];
    }

    ptr = arr;
    
    for(int i=0;i<20;i++)
    {
        if((*ptr)%2==0)
        sum = sum + *ptr;
        ptr++;
    }
    cout<<endl<<"The sum of all even numbers is :  "<<sum;
}