#include<bits/stdc++.h>
using namespace std;


bool isLucky(int n) {

    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        return false;

        cout<<n<<" ";
        n=n-i;
    }
    

    return true;
}

int main()
{
    int size, value;
    cin>>size;
    while(size--)
    {
        cout<<"\nInput: ";
        cin>>value;
        cout<<"\nOutput: "<<isLucky(value);
    }
}