#include<bits/stdc++.h>
using namespace std;

// POSITIVE EXPONENT FUNCTION
int positiveExponent(int baseValue, int exponentValue)
{
    if(exponentValue==0)
    return 1;

    int result=1;
    int base = baseValue;

    for(int i=0;i<30&&exponentValue;i++){
        if(exponentValue&1)
        result = result * baseValue;

        baseValue = baseValue*baseValue;
        exponentValue = (exponentValue>>1);
    }
    return result;
}

// ALL EXPONENT FUNCTION
float allExponent(int baseValue, int exponentValue)
{
    float res = 1;
    if(exponentValue>=0)
    res = (float)positiveExponent(baseValue, exponentValue);
    else
    {
        int base = baseValue;
        exponentValue= -exponentValue;

        while(exponentValue){
            res = res/baseValue;
            exponentValue = exponentValue/2;
        }
    }
    return res;
}

//MAIN FUNCTION 
int main(){
    int base, exponent;
    cin>>base>>exponent;
    
    cout<<allExponent(base, exponent);
}