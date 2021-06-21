#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;

int longestLength(int arr[], int size, int sum){
    unordered_map<int, int> ump;

    int m =0;
    int val = 0;
    ump.insert(make_pair(val, -1));

    for(int i=0;i<size;i++)
    {
        val += arr[i];
        if(ump.find(val-sum)!=ump.end())
            m++;
        else if(ump.find(val) == ump.end())
        {
            ump.insert(make_pair(val,i));
        }
    }
    return (m*(m+1))/2;
}

int main() {
    int size;
    int sum;

    cout<<"Size: ";
    cin>>size;
    cout<<"\nSum: ";
    cin>>sum;

    cout<<"\nValues: ";
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];

    cout<<"Number of Subarrays: "<<longestLength(arr, size, sum);
}