#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;

bool sumIsPresent(int arr[], int size, int sum){
    unordered_map<int, int> ump;

    int val = 0;
    ump.insert(make_pair(val, 1));

    for(int i=0;i<size;i++)
    {
        val += arr[i];
        if(ump.find(val-sum) != ump.end())
        {
            cout<<" "<<val;
            return true;
        }
        
        ump.insert(make_pair(val,1));
    }
    return false;
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

    if(sumIsPresent(arr, size, sum))
    cout<<"YES";
    else
    cout<<"NO";
}