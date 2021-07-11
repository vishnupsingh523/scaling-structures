#include<iostream>
using namespace std;

int KthBit(int value, int k){
    return (value&(1<<(k-1)));
}
int main(){
    int size;
    cout<<"Size: ";
    cin>>size;
    while(size--){
        int value;
        cout<<"Value: ";
        cin>>value;
        int k;
        cout<<"K : ";
        cin>>k;
        cout<<"Set bit: "<<KthBit(value,k)<<"\n";
        }
}