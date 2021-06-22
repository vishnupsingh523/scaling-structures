#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;

int longestConsecutive(long long arr[], long long size){
    unordered_map<long long, long long> ump,visited;

    int count=0;
    long long value=0;
    int left =0, right =0;

    for(int i=0;i<size;i++)
    ump[arr[i]]=1;

    int ans =0;
    
    for(int i=0;i<size; i++){
        int x = arr[i];
        count =0;
        if(ump.find(x-1)== ump.end()&& visited.find(arr[i])==visited.end())
        {
            visited[arr[i]]=1;
            for(int j=x; ump.find(j)!=ump.end();j++)
            count++;

            ans = max(ans, count);
        }
    }
    return ans;
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