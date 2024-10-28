#include <bits/stdc++.h> 
long long titleToNumber(string str)
 {
    // Write your code here
    long long ans=0;
    for(int i=0;i<str.length();i++)
    {
        int val=str[i]-65+1;
        ans=(ans*26)+val;
    }
    return ans;
}
