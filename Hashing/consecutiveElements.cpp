#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;

    bool consecutiveElements(long long arr[], long long size){
    unordered_map<long long, long long> ump;

    
    for(long long i=0;i<size;i++)
    {
        ump[arr[i]]++;
    }
    
    auto mini = min_element(ump.begin(), ump.end())->first;

    long long count =0;
    for(long long i= mini; i<mini+size;i++)
    {
        if(ump[i] == 1)
        count++;
        else return 0;
    }
    if(count == mini+size-1)
    return true;
    else return false;
    
}

int main() {
    long long size;
    long long sum;

    cout<<"Size: ";
    cin>>size;
    // cout<<"\nSum: ";
    // cin>>sum;

    cout<<"\nValues: ";
    long long arr[size];
    for(long long i=0;i<size;i++)
    cin>>arr[i];

    cout<<"Consecutive Elements : "<<consecutiveElements(arr, size);
}