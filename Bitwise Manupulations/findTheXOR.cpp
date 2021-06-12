#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;

    cout<<"Size : ";
    cin>>n;
    
    vector<int> arr;
    int value;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        arr.push_back(value);
    }

    sort(arr.begin(), arr.end());

    cout<<"XOR : ";
    cin>>value;
    
    bool check = false;
    for(int i=0;i<n && check != true;i++)
    {
        int find = value^arr[i];

        check = binary_search(arr.begin()+i, arr.end(), find);
        
    }

    if(check)
    cout<<"\nYes";
    else
    cout<<"\nNo";

}