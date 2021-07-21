#include<bits/stdc++.h>
using namespace std;
int exactly3Divisors(int N)
    {
        if(N==1||N==2||N==3)
        return 0;
        
        vector<bool> isPrime(N+1,true);

        int ans =0;
        for(int i=2;i<N;i++)
        {
            if(isPrime[i])
            {
                if(i*i<=N)
                ans++;
                for(int j=i*i;j<=N;j=j+i)
                isPrime[j]=false;
            }
        }
        // for(int j=2;j*j<=N;j++)
        // {
        //     if(isPrime[j])
        //     {
        //         for(int i=j*2;i<=N;i+=j)
        //         isPrime[i]=false;
        //     }
        // }

        // for(int i=2;i*i<=N;i++)
        // if(isPrime[i])
        // ans++;
        return ans;
    }

int main(){
    cout<<exactly3Divisors(67);
}