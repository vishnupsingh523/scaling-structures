#include <bits/stdc++.h>
// #include<unordered_map>

using namespace std;


int main() {
    int size;
    unordered_map<int, int> ump;
    
    cout<<"Size: ";
    cin>>size;

    int value =0;
    for(int i=0;i<size;i++)
    {
        cin>>value;
        ump[value]++;
    }

    cout<<"\nNumber : Frequency\n";
    for(auto itr = ump.begin();itr!= ump.end();itr++)
    cout<<itr->first<<" "<<itr->second<<"\n";


}