#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;

    int longestLength(int arr[], int size){
    unordered_map<int, int> ump;

    int m =0;
    int val = 0;
    ump.insert(make_pair(val, -1));

    for(int i=0;i<size;i++)
    {
        val += arr[i];
        if(ump.find(val) == ump.end())
        {
            ump.insert(make_pair(val,i));
        }
        else
        m = max(m, i- ump[val]);
    }
    return m;
}

int main() {
    int size;
    int sum;

    cout<<"Size: ";
    cin>>size;
    // cout<<"\nSum: ";
    // cin>>sum;

    cout<<"\nValues: ";
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];

    cout<<"Largest length: "<<longestLength(arr, size);
}