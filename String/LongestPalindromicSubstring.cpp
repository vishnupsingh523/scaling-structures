#include<bits/stdc++.h>
using namespace std;

int lps(string s){
    int n = s.length();
    int maxm = 0;
    string str;

    for(int i=0;i<n;i++)
    {
        // for ODD length
        int l=i;
        int r = i;
        while(l>=0&&r<n && s[l]==s[r])
        {
            int currL = r-l+1;
            if(maxm<currL)
            {
                maxm = currL;
                str = s.substr(l,r+1);
            }

            l--;
            r++;
        }
        // for Even length
        l = i;
        r = i+1;
        while(l>=0&&r<n && s[l]==s[r])
        {
            int currL = r-l+1;
            if(maxm<currL)
            {
                maxm = currL;
                str = s.substr(l,r);
            }
            l--;r++;
        }

    }
    cout<<str<<endl;
    return maxm;
}

int main(){
    string s;
    cin>>s;

    cout<<lps(s);
    return 0;
}