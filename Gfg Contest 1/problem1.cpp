#include<bits/stdc++.h>
using namespace std;

int findMin(int n){
    if(n==1)
    return 0;

    if(n==3)
    return 1+ findMin(n-1);
    
    if(n%2==0)
    return 1+ findMin(n/2);
    else
    return 1+findMin(n-1);
}

int main() {

	int T;
	cin>>T;
	int n;
	while(T--){
        int count =0;
	    cin>>n;
	    
	    while(n>1){
	        if(n%2==0)
	        {
	            n=n/2;
	        }
	        else if(n==3||n%4==1)
	        n = n-1;
	        else n=n+1;
	        count++;
	    }
        cout<<count<<"\n";
	}
	
	return 0;
}