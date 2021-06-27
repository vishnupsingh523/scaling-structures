#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;

void booleanMatrix(int** arr, int n, int m){
    vector<int>col,row;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if(arr[i][j]==1)
    {
        row.push_back(i);
        col.push_back(j);
    }

    for(int j=0;j<row.size();j++)
    for(int i=0;i<m;i++)
    arr[row[j]][i]=1;

    for(int j=0;j<col.size();j++)
    for(int i=0;i<n;i++)
    arr[i][col[j]]=1;
}

int main() {
    int m,n;

    cout<<"Size (N and M) : ";
    cin>>n>>m;
    // cout<<"\nSum: ";
    // cin>>sum;

    cout<<"\nValues: \n";
    int **arr;
        
    arr = new int *[n];
    for(int i = 0; i <10; i++)
        arr[i] = new int[m];

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>arr[i][j];

    cout<<"Boolean Matrix : \n";
    booleanMatrix(arr,n,m);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
}