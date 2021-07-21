#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<pair<int, int>> st;
    
    int size;
    cout<<"Size: ";
    cin>>size;
    
    int values;
    cout<<"\nEnter values: \n";
    for(int i=0;i<size;i++)
    {
        cin>>values;
        int newMin = st.empty()? values: min(values, st.top().second);
        st.push({values, newMin});
    }

    cout<<"\nThe minimum element in the stack: "<<st.top().second;
}