#include<iostream>
using namespace std;

int countX(int x){
    int count=0;
    while((1<<count)<=x)
    count++;
    return count-1;
}
int countSetBits(int n)
{
    if(n == 0)
    return 0;
    
    int count =countX(n);

    int tillx = (1<<(count-1))*count;
    int lastTilln = n - ( 1<<count ) + 1;
    int rem = n - (1<<count);
    int res = tillx + lastTilln + countSetBits(rem);
    return res;
}

int main(){
    int size;
    cout<<"Size: ";
    cin>>size;
    while(size--){
        int value;
        cout<<"Value: ";
        cin>>value;
        cout<<"Set bit: "<<countSetBits(value)<<"\n";
        }
}