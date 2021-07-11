#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){

}

void standardise(int a, int b){

}

int maxPoints(vector<vector<int>> &points){
    map<pair<int,int>, int> mp;
    int ans =1;
    
    if(points.size()==0)
    return 0;
    else{
        for(int i=0;i<points.size();i++){
            int overlap =0, maxm =0;

            for(int j=i+1;j<points.size();j++)
            {
                
            }
        }
    }
}

int main(){
    vector<vector<int>> points;
    cout<<"Enter size: ";
    int size;
    cin>>size;
    
    cout<<"Values: \n";
    int a,b;
    for(int i=0;i<size;i++){
        cin>>a>>b;
        points[i].push_back(a);
        points[i].push_back(b);
    }

    cout<<"\nMaximum Number: "<<maxPoints(points);
}