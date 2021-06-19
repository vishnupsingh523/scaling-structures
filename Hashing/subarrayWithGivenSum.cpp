#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;

bool hasArrayTwoCandidates(int arr[], int n, int x){
    unordered_map<int, int> ump;
    for(int i=0;i<n;i++)
    {
        ump[arr[i]]++;
        if(ump.find(x-arr[i])!=ump.end())
        {
            if( arr[i] == x-arr[i] )
            {
                if(ump.find(x-arr[i])->second >1)
                {
                    cout<<"\n"<<arr[i]<<" "<<x-arr[i];
                    return true;
                }
            }
            else{
                cout<<"\n"<<arr[i]<<" "<<x-arr[i];
                return true;
            }
        }
    }
    return false;
}

int main() {
    int size;

    cout<<"Size: ";
    cin>>size;

    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];

    cout<<"\nX : ";
    int x ;
    cin>>x;

    if(hasArrayTwoCandidates(arr, size, x))
    cout<<"\nArrays has two candidates whose sum is equal to "<<x;
    else
    cout<<"\nArray don't have.";


}