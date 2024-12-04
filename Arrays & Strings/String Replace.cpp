Problem Statement



Jin is working on a string manipulation problem. He needs to replace all occurrences of a specified pattern within a given word with a specified character. 



Write a program to help Jin achieve this task efficiently.



Example



Input:

ABCABCXABCabc

ABC

#

Output:

##X#abc

Explanation:

After replacing occurrences of the pattern ABC with #, the resultant string becomes ##X#abc.

Solution:
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    string change,key;
    cin>>change>>key;
    for(int i=0;i<str.length();i++)
    {
        if(str.substr(i,change.length())==change)
        {
            str.replace(i,change.length(),key);
        }
    }
    cout<<str;
}
