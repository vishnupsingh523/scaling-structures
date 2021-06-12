#include<iostream>
using namespace std;

int main(){

    long long n, count =0;

    cout<<"Enter the number : ";
    cin>>n;
    
    for(; n;)
    {
        if((n&1) == 1)
        count++;

        n = (n>>1);
    }

    cout<<"\nBits: "<<count;
}