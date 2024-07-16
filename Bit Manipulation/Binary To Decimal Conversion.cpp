#include <bits/stdc++.h>

int convert(int N,string &str)
{
    // Write your code here.
    int decimal=0;
    for(int i=str.length()-1;i>=0;i--)
    {
        decimal=decimal+((str[i]-'0')*(pow(2,N-i-1)));
    }
    return decimal;
}
