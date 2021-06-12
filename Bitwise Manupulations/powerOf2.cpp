#include<iostream>
using namespace std;

int main(){

    long long n, count =0;

    cout<<"Enter the number : ";
    cin>>n;
    
    if(n&(n-1))
        cout<<"\nNo, its not the power of 2.";
    else
        cout<<"\nYes, its the power of 2.";

}