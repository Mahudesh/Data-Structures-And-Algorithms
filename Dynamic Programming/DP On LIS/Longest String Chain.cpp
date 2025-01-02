bool compare(string& largefirst, string& predecessor)
{
    int len1=largefirst.length();
    int len2=predecessor.length();
    if((len1-len2)!=1)
    return false;

    int i=0,j=0;
    while(i<len1)
    {
        if(j<len2 && largefirst[i]==predecessor[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    //b a c d
    //b c d
    if(i==len1 && j==len2)
    return true;
    return false;
}

bool static comp(string& a, string& b)
{
    return a.length()<b.length();
}
int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end(),comp);
    vector<int>dp(arr.size(),1);
    int maxi=1;
    for(int i=0;i<arr.size();i++)
    {
        for(int prev_ind=0;prev_ind<=i-1;prev_ind++)
        {
            //Check For Whether The Previous String Differs 1 Character By Current String
            if(compare(arr[i],arr[prev_ind]))
            {
                if(dp[prev_ind]+1>dp[i])
                {
                    dp[i]=1+dp[prev_ind];
                }
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
}
