#include<iostream>
using namespace std;
/************
 * String Matching funciton with return type void
 * Having two parameters (string str, string pattern)
 * str -> the main string in which we have to find the pattern
 * pattern -> the pattern to find.
*/

void findPattern(string str, string pattern)
{
    int count =0;
    int i =0;
    for(;i<str.size(); ++i)
    {
        for(int j=i;j<pattern.size();j++)
        if(str[i] == pattern[j])
        {
            count++;
            break;
        }else
        count =0;

        if( count = pattern.size())
        break;
    }
    
    cout<<"\nString found at : "<<i<<"  "<<count;
}

int main()
{
    string str,pattern;

    cout<<"Enter a string : ";
    cin>>str;

    cout<<"\nEnter the pattern : ";
    cin>>pattern;

    findPattern(str, pattern);
}