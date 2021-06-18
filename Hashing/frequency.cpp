#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;


int main() {
    int num;
    cout<<"Number: ";
    cin>>num;

    cout<<"\nPrinting all the divisiors : \n";
    
    int i=1;
    for(;i*i<num;i++)
    if(num%i==0)
    cout<<" "<<i;

    for(; i>=1;i--)
    if(num%i==0)
    cout<<" "<<(num/i);
}