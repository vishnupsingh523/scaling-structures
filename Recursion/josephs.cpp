#include<iostream>
using namespace std;

int josephus(int n, int k){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=1;

    int index =0,count=0;
    int cnt =0;
    while(count!=n-1){
        for(int i=0;i<n;i++)
        {
            if(arr[i])
            {
                if(cnt==k-1)
                {
                    arr[i]=0;
                    cnt =0;
                    count++;
                }
                else
                cnt++;
            }
        }
    }

    for(int i=0;i<n;i++)
    if(arr[i]==1)
    index = i+1;

    return index;
}
int main(){
    int count =10;
    int n,k;
    while(count--){
    cout<<"\nSize and seek : ";
    cin>>n>>k;
    cout<<"\nPosition: "<<josephus(n,k);
    }
    return 0;
}