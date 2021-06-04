#include<iostream>
using namespace std;

int findGCD(int a, int b){
    int max = 1;
    int count =2;

    for(;count<=min(a,b);count++)
    {
        if(a%count==0 && b%count==0)
        max = count;

        count++;
    }
    return max;
}

int ecluidsGCD(int a, int b)
{
    int divisor, dividend;
    divisor = min(a,b);
    dividend = max(a,b);

    int store;
    while(dividend%divisor != 0){
        store = divisor;
        divisor = dividend%divisor;
        dividend = divisor;
    }
    return divisor;
}
int main(){
    int a,b;
    cout<<"\nEnter the values: ";
    cin>>a>>b;
    cout<<"\nThe GCD is : "<<findGCD(a,b);
    cout<<"\nThe ECLUID's GCD is : "<<ecluidsGCD(a,b);

}