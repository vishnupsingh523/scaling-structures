#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;

    cout<<"Size : ";
    cin>>n;
    
    vector<int> arr;
    int value;
    int XOR =0;

    for(int i=0;i<n;i++)
    {
        cin>>value;
        arr.push_back(value);
        XOR = XOR^value;
    }

    long mask  = 1;
    int n1=0, n2=0;

    while(mask&XOR != 1)
    mask <<= 1;
    
    for(int i=0;i<n;i++)
    {
        if(mask & arr[i])
        n1^= arr[i];
        else
        n2^=arr[i];
    }

    cout<<"\nThe two elements are : "<<n2<<" and "<<n1;

}