#include<bits/stdc++.h>
using namespace std;

int main() {

	int T;
	cin>>T;
	int n;
	while(T--){
        cin>>n;
        int values;
        int repeated;
        int missing =0;
        unordered_map<int , int> ump;
        for(int i=0;i<n;i++)
        {
            cin>>values;
            if(ump.find(values)!=ump.end())
            repeated = values;

            ump[values]++;
        }

        for(int i=0;i<n;i++)
        if(ump.find(i)==ump.end())
        missing = i;
        
        cout<<repeated<<" "<<missing<<"\n";
	}
	
	return 0;
}