#include<bits/stdc++.h>
using namespace std;

int main() {

	int T;
	cin>>T;
	int n;
	while(T--){
        cin>>n;
        if(n==1)
        cout<<"0\n";
        else if(n==2)
        cout<<"4\n";
        else{
            int lowest = floor(sqrt(n));
            int highest = ceil(sqrt(n));
            if(n-lowest*lowest < highest*highest-n)
            cout<<lowest * lowest<<"\n";
            else if(n-lowest*lowest > highest*highest-n)
            cout<<highest * highest<<"\n";
            else if(n-lowest*lowest == highest*highest-n)
            cout<<highest*highest<<"\n";
        }
	}
	
	return 0;
}