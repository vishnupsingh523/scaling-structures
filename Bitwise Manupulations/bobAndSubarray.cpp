#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int   n;
    cin>>n;
    int  arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    

    long  mask, ans =0;
    
    for(int i=31;i>=0;i--){
        int next=0;
        mask = (1l<<i);

        for(int  j=n-1;j>=0;j--)
        {
            if(arr[j] & mask)
            {
                next = n-j;
            }
            ans = ans + (next*mask);
        }
    }
    cout<<ans;
    return 0;
}