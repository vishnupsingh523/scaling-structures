#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;

int longestConsecutive(long long arr[], long long size){
    unordered_map<long long, long long> ump;

    int count=0;
    long long value=0;
    int left =0, right =0;

    for(int i=0;i<size;i++){
        if(ump.find(arr[i])!= ump.end())
        continue;

        int left =0, right =0;
        
        if(ump.find(arr[i]-1) !=ump.end())
        left = ump[arr[i]-1];

        if(ump.find(arr[i]+1) !=ump.end())
        right = ump[arr[i]+1];

        value = 1 + left + right;
        ump[arr[i]] = value;
        ump[arr[i]-left] = value;
        ump[arr[i]+right] = value;

        if(count<value)
        count = value;
    }
    return count;
}

int main() {
    long long size;
    long long sum;

    cout<<"Size: ";
    cin>>size;
    

    cout<<"\nValues: ";
    long long arr[size];
    for(long long i=0;i<size;i++)
    cin>>arr[i];

    cout<<"Longest Consecutive length : "<<longestConsecutive(arr, size);
}